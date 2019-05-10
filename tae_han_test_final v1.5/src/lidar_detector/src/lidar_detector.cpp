// matrix.h & matrix.tpp : https://github.com/andrea993/Matrix-Library-Cpp with little bit of change (added transpose)
// Object detection package를 활용한 버전
// 고칠점
// 1. pose받을 때 받는 covariance도 이용해보면 좋을듯
// 2. lidar에서 직접 점을 받아서 하면 좋을듯
// 3. merge가 안되는거 같음... 해결해보자
// 4. start covariance 값 어케할지 -> 지금 나오는거 대부분이 99.9정도의 covariance를 가지는 것들인데 시작 covariance가 100 이였음. merge문제!!
// 5. 점 받아오는거 initiater 사용하게 변경 해보자
// 6. 트래커 점이랑 새로운점 merging이 끝나면 그 loop 에서는 또 다른 새로운점과는 merging이 되면 안되게 만들기
#define RVIZ	// rviz용 publish
#define DEBUG
//#define MOVING_LIDAR
#define TEST

#include "matrix.h"
#include <ros/ros.h>
#include <math.h>
#include <iostream>
#include <time.h>
#include "icra_roboin_msgs/Obstacles.h"
#include "icra_roboin_msgs/CircleObstacle.h"
#include "geometry_msgs/PoseWithCovarianceStamped.h"		// 라이다 위치 subscribe용


int clear_param = 2;			// point_track의 clear가 new_clear-clear_param 보다 작아지면 없애기
bool sub_ok = false;
bool sensor_start = true;
short new_clear = 100;
double delta_time = 0.0;
double theta_sensor = 0.0;		// sensor pose theta
double speed_threshold;			// 이 값 이상이면 충분한 속도를 가지고 있다고 봄
double covariance_threshold;	// 이 값 이하면 충분한 신뢰도를 가지고 있다고 봄
double validation_threshold;	// 이 값 이하면 같은 점으로 보고 merge
double for_gaussian = 0.0001;	// Noise 매트릭스들 용 gaussian에 쓰일 variance
double for_gaussian_v = 0.0001;	// Noise 매트릭스들 용 gaussian에 쓰일 variance
unsigned int time_p = 0;		// past
unsigned int time_c = 0;		// current

ros::Subscriber obstacles_sub_;
ros::Subscriber pose_sub_;
ros::Publisher d_obstacles_pub_;
#ifdef RVIZ
std::string frame = "world";	// 뭔지 잘 모르겠음... rviz 사용에 필요해서 사용중
#endif
std::default_random_engine generator;
std::normal_distribution<double> d {0.0,for_gaussian};
std::normal_distribution<double> dv {0.0,for_gaussian_v};

//문제있음**문제있음**문제있음**문제있음**문제있음**문제있음**문제있음**문제있음**문제있음**문제있음**문제있음**문제있음**문제있음**
double for_P_vel = 100.0;		// Covariance 처음 만들 때 velocity 의 covariance 초기값
double for_P_state = 0.5;		// Covariance 처음 만들 때 state 의 covariance 초기값


/*물체 정보 담는 구조*/
struct point_track {
	Matrix<double> x = {{0},{0},{0},{0}}; // Main point state [x, y, x_dot, y_dot]
	Matrix<double> p = {{for_P_state,0,0,0},{0,for_P_state,0,0},{0,0,for_P_vel,0},{0,0,0,for_P_vel}};
	int clear = new_clear;
	int life = 0;	// 얼마나 오래 살아있었는가
	int info = 0;	// 0:새로운 점, 1:멈춰있는 점, 2:움직이는 점, 3:아군, 4:죽은로봇, 5:적군, 6:1번 적군, 7:2번 적군
	int group = 0;
	double velocity = 0.0;
	double covariance = 0.0;
};
/*정보의 집합*/
std::vector<point_track> tracker;
/*publish 할 점들의 집합*/
std::vector<point_track> publisher;
/*받아온 점들의 집합*/
std::vector<point_track> initiater;
/*센서의 포즈*/
Matrix<double> x_sensor(2,1,0);

/*칼만필터 사용에 필요한 매트릭스들*/
Matrix<double> y;							// Error (2x1)
Matrix<double> K;							// Kalman gain (4x2)
Matrix<double> S;							// Innovation covariance (2x2)
Matrix<double> Rotate(2,2,0);				// 2D rotation matrix (2x2)
Matrix<double> K_ini = { {0.5,0.1}, {0.1,0.5}, {0.01,0.01}, {0.01,0.01} };	// S.Det() = 0 로 인한 오류가 있을때 사용 //손질 필요
Matrix<double> I = {{1,0,0,0},{0,1,0,0},{0,0,1,0},{0,0,0,1}};				// Identity matrix
Matrix<double> Q = {{d(generator),d(generator),d(generator),d(generator)},{d(generator),d(generator),d(generator),d(generator)},	// Noise for P (2x2)
					{d(generator),d(generator),d(generator),d(generator)},{d(generator),d(generator),d(generator),d(generator)}};		
Matrix<double> v = {{dv(generator)},{dv(generator)},{dv(generator)},{dv(generator)}};						// Noise for x (4x1)
Matrix<double> R = {{d(generator),d(generator)},{d(generator),d(generator)}};							// Noise for S (2x2)
Matrix<double> F = {{1,0,0,0},{0,1,0,0},{0,0,1,0},{0,0,0,1}};							// State transition matrix (4x4)

//문제있음**문제있음**문제있음**문제있음**문제있음**문제있음**문제있음**문제있음**문제있음**문제있음**문제있음**문제있음**문제있음**
// 사실 이거도 우리는 xy가 아니라 r과 theta를 보기 때문에 바뀌어야 함
Matrix<double> H = {{1,0,0,0},{0,1,0,0}};		// Measurement function --> reflect the fact that we observe x and y but not the two velocities (2x4)

//문제있음**문제있음**문제있음**문제있음**문제있음**문제있음**문제있음**문제있음**문제있음**문제있음**문제있음**문제있음**문제있음**
//점 받아오는것도 바꿔보자
std::vector< Matrix<double>> x_point_init;	// Newly recived [x, y]
Matrix<double> check(2,1,0);				// 이전점과 현재점의 차이 구할때 쓰임
Matrix<double> ininin(2,1,0);				// 점 받아올 때 쓰임

/* Reset noise functions (Q,v,R) every loop */
void re_noise() {
	Q = Matrix<double> {{d(generator),d(generator),d(generator),d(generator)},{d(generator),d(generator),d(generator),d(generator)},
						{d(generator),d(generator),d(generator),d(generator)},{d(generator),d(generator),d(generator),d(generator)}};
	v = Matrix<double> {{dv(generator)},{dv(generator)},{dv(generator)},{dv(generator)}};
	R = Matrix<double> {{d(generator),d(generator)},{d(generator),d(generator)}};
	if (time_p != 0.0) {			// 첫 loop는 건너뛰기
		time_c = clock();			// loop 하나 도는데 걸린 시간을 F에 적용해줌
		delta_time = (time_c - time_p) / 1000000.0;	// 1,000,000 = 10^6
		F[0][2] = delta_time;
		F[1][3] = delta_time;
		std::cout<<"(re_noise) delta_time = "<<delta_time<<std::endl;
	}
	time_p = clock();
}

#ifdef MOVING_LIDAR
/* Get lidar pose through ROS Topic */
void get_sensor(const geometry_msgs::PoseWithCovarianceStamped::ConstPtr& msg) {
	x_sensor[0][0] = msg->pose.pose.position.x;
	x_sensor[1][0] = msg->pose.pose.position.y;
	theta_sensor = msg->pose.pose.orientation.z;
	sensor_start = true;
	//std::cout<<"(get_sensor)	working"<<std::endl; 
}
#endif//MOVING_LIDAR

/* Predict the position of points that were viewed before */
void get_prediction() {
	if (tracker.size() == 0) {return;}	
	for (int i=0; i<tracker.size(); i++) {
		tracker[i].x = F * tracker[i].x + v;
		tracker[i].p = F * tracker[i].p * F.Trp() + Q; }}

/* Change the frame between lidar_frame --> world_frame */
void SE2_Transform() {
	Rotate[0][0] = cos(theta_sensor);
	Rotate[0][1] = -1 * sin(theta_sensor);
	Rotate[1][0] = sin(theta_sensor);
	Rotate[1][1] = cos(theta_sensor);
	for (int i=0; i<x_point_init.size(); i++) { x_point_init[i] = x_sensor + Rotate * x_point_init[i]; }
}

/* Publish dynamic points */
void publish_point() {
	/*publish 할 점 구하기*/
	if (tracker.size() == 0) {
		//std::cout<<"(publish_point)	tracker.size() == 0"<<std::endl;
		return;}
	publisher.clear();
	for (int main=0; main<tracker.size(); main++) {
		double velocity = sqrt(tracker[main].x[2][0] * tracker[main].x[2][0] + tracker[main].x[3][0] * tracker[main].x[3][0]);
		double covariance = (tracker[main].p[2][2] + tracker[main].p[3][3]) * 0.5;
		if (covariance < covariance_threshold && velocity > speed_threshold) {
			point_track p_pub;
			p_pub.covariance = covariance;
			p_pub.x = tracker[main].x;
			p_pub.group = tracker[main].group;
			p_pub.info = tracker[main].info;
			p_pub.velocity = velocity;
			publisher.push_back(p_pub);
			std::cout<<"(publish_point)	covariance : "<<covariance<<std::endl;
		} }
	if (publisher.size() == 0) {
		//std::cout<<"(get_prediction)	no point to publish"<<std::endl; 
		return;}
	int itr = 0;
	if (publisher.size() > 3) { itr = 3; }
	else { itr = publisher.size(); }

	/*publish 하기*/
	#ifdef RVIZ
	icra_roboin_msgs::Obstacles Dobstacles;
	icra_roboin_msgs::CircleObstacle circle;
	for (int i=0; i<itr; i++) {
		double max_vel = 0.0;
		for (int j=0; j<publisher.size(); j++) {if(max_vel < publisher[j].velocity){max_vel = publisher[j].velocity;}}
		for (int j=0; j<publisher.size();j++) {
			if (publisher[j].velocity == max_vel) {
				circle.center.x = publisher[j].x[1][0];
				circle.center.y = publisher[j].x[2][0];
				circle.radius = 0.09;
				Dobstacles.circles.push_back(circle);
				publisher.erase(publisher.begin() + j);
				std::cout<<"(publish_point)	velocity :		"<<publisher[j].velocity<<std::endl;
				break; } } }
	Dobstacles.header.frame_id = frame;
	Dobstacles.header.stamp = ros::Time::now();
	d_obstacles_pub_.publish(Dobstacles);
	#else//RVIZ
	geometry_msgs::PoseWithCovarianceStamped black;
	for (int i=0; i<itr; i++) {
		double max_vel = 0.0;
		for (int j=0, j<publisher.size(); j++) {if(max_vel < publisher[j].velocity){max_vel = publisher[j].velocity;}}
		for (int j=0; j<publisher.size();j++) {
			if (publisher[j].velocity == max_vel) {
				black.pose.pose.position.x = publisher[j].x[1][0];
				black.pose.pose.position.y = publisher[j].x[2][0];
				black.pose.covariance = publisher[j].covariance;
				publisher.erase(publisher.begin() + j);
				std::cout<<"(publish_point)	velocity :		"<<publisher[j].velocity<<std::endl;
				break; } } }
	black.header.stamp = ros::Time::now();
	d_obstacles_pub_.publish(black);
	#endif//RVIZ
}

/* Make new points if there are no points that match */
void make_new_point(int init) {
	point_track initiate;
	initiate.x[0][0] = x_point_init[init][0][0];
	initiate.x[1][0] = x_point_init[init][1][0];
	tracker.push_back(initiate);
	//std::cout<<"(make_new_point)	new points initiated"<<std::endl;
}

/* Merge point (Kalman measurement update) */
void merge_point(int init, int main) {
	y = x_point_init[init] - H * tracker[main].x;
	S = H * tracker[main].p * H.Trp() + R;
	K = tracker[main].p * H.Trp() * S.Inv();
	//catch (std::logic_error) {K = K_ini;}
	tracker[main].x = tracker[main].x + (K * y);
	tracker[main].p = (I - K * H) * tracker[main].p;
	//std::cout<<"(merge_point)	points merged"<<std::endl;
}

/* Compare newly viewed points and points that were viewed before */
void check_init_merge() {
	if (x_point_init.size() == 0) {
		//std::cout<<"(check_init_merge)	x_point_init.size() == 0"<<std::endl; 
		return;}
	for (int init=0; init<x_point_init.size(); init++) {
		if (tracker.size() ==0) {make_new_point(init);}
		for (int main=tracker.size()-1; main>-1; main--) { // 가장 최근에 잡힌 점과 먼저 비교
			#ifdef TEST
			double validation = sqrt((x_point_init[init][0][0]-tracker[main].x[0][0])*(x_point_init[init][0][0]-tracker[main].x[0][0])+(x_point_init[init][1][0]-tracker[main].x[1][0])*(x_point_init[init][1][0]-tracker[main].x[1][0]));
			#else
			check[0][0] = x_point_init[init][0][0] - tracker[main].x[0][0];
			check[1][0] = x_point_init[init][1][0] - tracker[main].x[1][0];
			// 이거 다시한번 체크
			Matrix<double> calcu = check.Trp() * (H * tracker[main].p * H.Trp() + R) * check;
			double validation = sqrt(calcu[0][0] * calcu[0][0]);
			#endif
			std::cout<<"(check_init_merge)	validation : "<<validation<<std::endl; 
			if (validation < validation_threshold * delta_time) {
				merge_point(init, main);
				tracker[main].clear = new_clear;
				break;
			}
			if (main == 0) {
				make_new_point(init);
				} } }
	//std::cout<<"(check_init_merge)	working"<<std::endl; 
}

/* Erase points that were not viewed for a certain loop */
void clean_point() {	
	if (tracker.size() == 0) {
		//std::cout<<"(clean_point)	tracker.size() == 0"<<std::endl; 
		return;}	
	for (int i=0; i<tracker.size(); i++) {
		tracker[i].clear -= 1;
		tracker[i].life += 1;}
	for (int main=0; main<tracker.size(); main++) {
		if (tracker[main].clear < new_clear - clear_param) {
			// std::cout<<"cleaning"<<std::endl;
			tracker.erase(tracker.begin() + main);
		}
	}
	//std::cout<<"(clean_point)	number of main points : "<<tracke.size()<<std::endl; 
}

/* Get obstacle position through ROS Topic */
void get_point(const icra_roboin_msgs::Obstacles::ConstPtr& msg) {
	x_point_init.clear();
	//std::cout<<"(get_point)	number of points recieved : "<<msg->circles.size()<<std::endl; 
	for (int init=0; init<msg->circles.size(); init++) {
		ininin[0][0] = msg->circles[init].center.x;
		ininin[1][0] = msg->circles[init].center.y;
		x_point_init.push_back(ininin); }
	SE2_Transform();
	sub_ok = true;
}

// 프레딕트(get_prediction) -> 메져맨트(get_point) -> 월드프레임으로이동(SE2_Transform)
// -> 매져먼트&프레딕트비교(check_init_merge) -> publish_point -> clean_point -> re_noise

int main(int argc, char **argv)
{
    ros::init(argc, argv, "D_detector");
    ros::NodeHandle n;
	ros::NodeHandle n_local("~");
	#ifdef RVIZ
	d_obstacles_pub_ = n.advertise<icra_roboin_msgs::Obstacles>("obstacles", 3);	// rviz 사용시
	#else//RVIZ
	d_obstacles_pub_ = n.advertise<geometry_msgs::PoseWithCovarianceStamped>("obstacles, 3");	// 로봇에 쏴줄 때
	#endif//RVIZ
    n_local.param<double>("covariance_threshold", covariance_threshold, 110.0);			// covariance가 이 이하이여야지 pub
    n_local.param<double>("speed_threshold", speed_threshold, 0.5);						// 속도가 이 이상이여야지 pub. 벽이 튀는 현상 방지를 위해 일정 속도 이상만 받는게 좋음
    n_local.param<double>("validation_threshold", validation_threshold, 0.4);			// 이 이하의 값을 가져야지 같은 점. 낮을수록 벽 인식을 잘 안함
    n_local.param<int>("new_clear", clear_param, 2);			// 이 횟수만큼 안보여야지 리셋
    obstacles_sub_ = n.subscribe("obst", 5, get_point);
	#ifdef MOVING_LIDAR
	sensor_start = false;
	pose_sub_ = n.subscribe("amcl_pose", 1, get_sensor);	// 센서 점은 들어올때마다 새롭게 업데이트하기
	#endif//MOVING_LIDAR
	while(ros::ok()) {
		if (sub_ok && sensor_start) {
			get_prediction();
			re_noise();
			check_init_merge();
			publish_point();
			clean_point();
			sub_ok = false;
		}
		ros::spinOnce();
	}
    return 0;
}

// 110/	0.5/	0.4
// 
