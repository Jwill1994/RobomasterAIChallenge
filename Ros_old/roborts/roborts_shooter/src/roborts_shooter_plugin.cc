#include <gazebo/common/Plugin.hh>
#include <ros/ros.h>

#include <gazebo/physics/physics.hh>
#include <gazebo_plugins/gazebo_ros_utils.h>

#include <gazebo/physics/World.hh>
#include <gazebo/physics/Model.hh>
#include <gazebo/physics/Link.hh>
#include <gazebo/physics/physics.hh>

#include <unistd.h>

#include <boost/bind.hpp>
#include <gazebo/gazebo.hh>
#include <gazebo/physics/physics.hh>
#include <gazebo/common/common.hh>
#include <stdio.h>
#include <thread>


#include "roborts_msgs/ShootState.h"
#include "roborts_msgs/ShootInfo.h"
#include "roborts_msgs/ShootCmd.h"
#include "roborts_msgs/FricWhl.h"
#include "gazebo_msgs/GetLinkState.h"
#include "geometry_msgs/Pose.h"


#include <ignition/math/Pose3.hh>
#include <ignition/math/Vector3.hh>
#include <ignition/math/Quaternion.hh>
#include <ignition/math/Matrix3.hh>

namespace gazebo
{
    class RobortsShooterPlugin : public ModelPlugin
    {
    
        public: RobortsShooterPlugin() : ModelPlugin()
        {
        }

        public: void Load(physics::ModelPtr _parent, sdf::ElementPtr _sdf)
        {
            this->model_ = _parent;
            this->gimbal_link = _sdf->Get<std::string>("gimbal_link");
            this->fake_link = _sdf->Get<std::string>("fake_link");
            this->reference_frame_ = _sdf->Get<std::string>("reference_frame");
            this->force = _sdf->Get<double>("force");
            
            // Initialize ros, if it has not already bee initialized.
            if (!ros::isInitialized())
            {
                int argc = 0;
                char **argv = NULL;
                ros::init(argc, argv, "roborts_shooter_node",
                    ros::init_options::NoSigintHandler);
            }

            // Create our ROS node. This acts in a similar manner to
            // the Gazebo node
            // this->ros_nh_.reset(new ros::NodeHandle("roborts_shooter_node"));

            //ros service
            this->gazebo_ros_link_state = this->ros_nh_.serviceClient<gazebo_msgs::GetLinkState>("/gazebo/get_link_state");
            
            

            

            // ros::SubscribeOptions so =
            //     ros::SubscribeOptions::create<std_msgs::Float32>(
            //         earthquake_freq_topicName,
            //         1,
            //         boost::bind(&RobortsShooterPlugin::OnRosMsg, this, _1),
            //         ros::VoidPtr(), &this->rosQueue);
            // this->rosSub = this->rosNode->subscribe(so);
            
            // // Spin up the queue helper thread.
            // this->rosQueueThread =
            //     std::thread(std::bind(&RobortsShooterPlugin::QueueThread, this));

            // ros::Publisher pub = ros_nh_.advertise<geometry_msgs::Pose>("gimbal_pose", 1);
            // pub.publish(this->gimbal_pose);
            

            // this->ros_ctrl_fric_wheel_srv_ = ros_nh_.advertiseService("cmd_fric_wheel", &RobortsShooterPlugin::CtrlFricWheelService, this);
            // this->ros_ctrl_shoot_srv_ = ros_nh_.advertiseService("cmd_shoot", &RobortsShooterPlugin::CtrlShootService, this);

            // this->ros_shoot_state_pub_ = ros_nh_.advertise<roborts_msgs::ShootState>("shoot_state",1);
            // this->ros_shoot_info_pub_ = ros_nh_.advertise<roborts_msgs::ShootInfo>("shoot_info",1);

            // Listen to the update event. This event is broadcast every
            // simulation iteration.
            this->updateConnection = event::Events::ConnectWorldUpdateBegin(
                std::bind(&RobortsShooterPlugin::OnUpdate, this));

            this->old_secs =ros::Time::now().toSec();

            GetBulletList();
            OutputBulletList();

            ROS_INFO("Roborts Shooter Ready....");

        }

        // // need to be fixed!
        // bool RobortsShooterPlugin::CtrlFricWheelService(roborts_msgs::FricWhl::Request &req,
        //                                 roborts_msgs::FricWhl::Response &res){
        //     roborts_sdk::cmd_fric_wheel_speed fric_speed;
        //     if(req.open){
        //         fric_speed.left = 1200;
        //         fric_speed.right = 1200;
        //     } else{
        //         fric_speed.left = 1000;
        //         fric_speed.right = 1000;
        //     }
        //     fric_wheel_pub_->Publish(fric_speed);
        //     res.received = true;
        //     return true;
        // }

        // // need to be fixed!
        // bool RobortsShooterPlugin::CtrlShootService(roborts_msgs::ShootCmd::Request &req,
        //                             roborts_msgs::ShootCmd::Response &res){
        //     roborts_sdk::cmd_shoot_info gimbal_shoot;
        //     uint16_t default_freq = 1500;
        //     switch(static_cast<roborts_sdk::shoot_cmd_e>(req.mode)){
        //         case roborts_sdk::SHOOT_STOP:
        //         gimbal_shoot.shoot_cmd = roborts_sdk::SHOOT_STOP;
        //         gimbal_shoot.shoot_add_num = 0;
        //         gimbal_shoot.shoot_freq = 0;
        //         break;
        //         case roborts_sdk::SHOOT_ONCE:
        //         if(req.number!=0){
        //             gimbal_shoot.shoot_cmd = roborts_sdk::SHOOT_ONCE;
        //             gimbal_shoot.shoot_add_num = req.number;
        //             gimbal_shoot.shoot_freq = default_freq;
        //         }
        //         else{
        //             gimbal_shoot.shoot_cmd = roborts_sdk::SHOOT_ONCE;
        //             gimbal_shoot.shoot_add_num = 1;
        //             gimbal_shoot.shoot_freq = default_freq;
        //         }
        //         break;
        //         case roborts_sdk::SHOOT_CONTINUOUS:
        //         gimbal_shoot.shoot_cmd = roborts_sdk::SHOOT_CONTINUOUS;
        //         gimbal_shoot.shoot_add_num = req.number;
        //         gimbal_shoot.shoot_freq = default_freq;
        //         break;
        //         default:
        //         return  false;
        //     }
        //     gimbal_shoot_pub_->Publish(gimbal_shoot);

        //     res.received = true;
        //     return true;
        // }

        // Called by the world update start event
        public: void OnUpdate()
        {


            srv_.request.link_name = this->fake_link;
            srv_.request.reference_frame = this->reference_frame_;

            if(gazebo_ros_link_state.call(srv_)  && srv.response.success){
                // ROS_WARN("%d", srv_.response.success);

                // ROS_WARN("RESPONSE : %f, %f, %f", srv_.response.link_state.pose.position.x,srv_.response.link_state.pose.position.y,srv_.response.link_state.pose.position.z);
                // ROS_WARN("GIMBAL_POSE : %f, %f, %f", this->gimbal_pose.position.x,this->gimbal_pose.position.y,this->gimbal_pose.position.z);

                this->x_dir = srv_.response.link_state.pose.position.x - this->gimbal_pose.position.x;
                this->y_dir = srv_.response.link_state.pose.position.y - this->gimbal_pose.position.y;
                this->z_dir = srv_.response.link_state.pose.position.z - this->gimbal_pose.position.z;

                // ROS_WARN("BEFORE NORMALIZE : X_DIR, Y_DIR, Z_DIR = %f, %f, %f", this->x_dir, this->y_dir, this->z_dir);

                ignition::math::Vector3d vec = ignition::math::Vector3d(this->x_dir, this->y_dir, this->z_dir).Normalize();


                this->x_dir = vec.X();
                this->y_dir = vec.Y();
                this->z_dir = vec.Z();

                // ROS_WARN("AFTER NORMALIZE : X_DIR, Y_DIR, Z_DIR = %f, %f, %f", this->x_dir, this->y_dir, this->z_dir);
            }


            srv.request.link_name = this->gimbal_link;
            srv.request.reference_frame = this->reference_frame_;

            if(gazebo_ros_link_state.call(srv) && srv.response.success){
                this->gimbal_pose.position.x = srv.response.link_state.pose.position.x;
                this->gimbal_pose.position.y = srv.response.link_state.pose.position.y;
                this->gimbal_pose.position.z = srv.response.link_state.pose.position.z;

                this->gimbal_pose.orientation.x = srv.response.link_state.pose.orientation.x;
                this->gimbal_pose.orientation.y = srv.response.link_state.pose.orientation.y;
                this->gimbal_pose.orientation.z = srv.response.link_state.pose.orientation.z;
                this->gimbal_pose.orientation.w = srv.response.link_state.pose.orientation.w;



                // this->q_ = new ignition::math::Quaternion<double>( \
                //     this->gimbal_pose.orientation.w, this->gimbal_pose.orientation.x, \
                //     this->gimbal_pose.orientation.y, this->gimbal_pose.orientation.z \
                // );
                // // q_.qx = this->gimbal_pose.orientation.x;
                // // q_.qy = this->gimbal_pose.orientation.y;
                // // q_.qz = this->gimbal_pose.orientation.z;
                // // q_.qw = this->gimbal_pose.orientation.w;

                // if(this->gimbal_pose.orientation.w > 1) {this->q_->Normalize();}
                // double angle = 2 * std::acos(this->gimbal_pose.orientation.w);
                // double s = std::sqrt(1 - std::pow(this->gimbal_pose.orientation.w,2));
                // if(s < 0.001) {
                //     this->x_dir = this->gimbal_pose.orientation.x;
                //     this->y_dir = this->gimbal_pose.orientation.y;
                //     this->z_dir = this->gimbal_pose.orientation.z;
                // } else {
                //     this->x_dir = this->gimbal_pose.orientation.x / s;
                //     this->y_dir = this->gimbal_pose.orientation.y / s;
                //     this->z_dir = this->gimbal_pose.orientation.z / s;
                // }

                // this->gimbal_roll = this->q_->Euler().X();
                // this->gimbal_pitch = this->q_->Euler().Y();
                // this->gimbal_yaw = this->q_->Euler().Z();

                

                // ROS_INFO("%f", this->gimbal_pose.position.x);
                // ROS_INFO("%f", this->gimbal_pose.position.y);
                // ROS_INFO("%f", this->gimbal_pose.position.z);
            }





            // TODO: Check what is necessary now here
            double new_secs =this->model_->GetWorld()->GetSimTime().Float();
            double delta = new_secs - this->old_secs;

            double max_delta = 0.0;

            if (this->reset_frequency != 0.0)
            {
            max_delta = 1.0 / this->reset_frequency;
            }

            if (delta > max_delta && delta != 0.0)
            {
                // We update the Old Time variable.
                this->old_secs = new_secs;
                
                
                if (this->link_to_update_index_now >= this->linkIDToName_size)
                {
                    this->link_to_update_index_now = 0;
                }
            
                // Update the Particles
                UpdateBullets(this->link_to_update_index_now);
                this->link_to_update_index_now ++;
            }
            
        }

        void WaitForseconds(float seconds_to_wait)
        {
            unsigned int microseconds;
            microseconds = seconds_to_wait * 1e6;
            ROS_WARN("Waiting for %f seconds",seconds_to_wait);
            usleep(microseconds);
            ROS_WARN("Done waiting...");

        }

        void UpdateBullets(int link_to_update_index_now)
        {
            for (auto model : this->model_->GetWorld()->GetModels())
            {
                std::string model_name = model->GetName();
                if (this->linkIDToName[link_to_update_index_now] == model_name)
                {
                    if(link_to_update_index_now==2){
                    this->MoveBullet(model);
                    this->SetForceBullet(model);
                    }
                }
                
            }
            // delete this->q_;
        }
        
        
        
        void GetBulletList()
        {
            this->linkIDToName.clear();
            // Initialize color map.
            this->linkIDToName_size = 0;
            
            int i = 0;
            for (auto model : this->model_->GetWorld()->GetModels())
            {
                std::string model_name = model->GetName();
                // ROS_WARN("%s", model_name.c_str());
                if (model_name.find(this->bullet_link_name) != std::string::npos)
                {
                    this->linkIDToName[i] = model->GetName();
                    i ++;
                }
            
            }
            
            this->linkIDToName_size = linkIDToName.size();
        }
        
        void OutputBulletList()
        {
            ROS_WARN("Start OutputBulleteList...");

            for (auto const& x : this->linkIDToName)
            {
                ROS_WARN("LinkID=%i, Name=%s", x.first, x.second.c_str());
            }

            ROS_WARN("END OutputBulletList...");

        }
        
        
        void MoveBullet(boost::shared_ptr<gazebo::physics::Model> model)
        {

            std::string model_name = model->GetName();

            // If the model name contains the substring particle, we consider it a particle
            if (model_name.find(this->bullet_link_name) != std::string::npos)
            {
                ROS_WARN("Moving model=%s",model_name.c_str());
                
                ROS_WARN("GIMBAL-POSE[X,Y,Z,X_AXIS,Y_AXIS,Z_AXIS]=[%f,%f,%f,%f,%f,%f], model=%s", 
                    this->gimbal_pose.position.x + this->gimbal_length * this->x_dir,
                    this->gimbal_pose.position.y + this->gimbal_length * this->y_dir,
                    this->gimbal_pose.position.z + this->gimbal_length * this->z_dir - 0.05, 
                    this->x_dir,this->y_dir,this->z_dir, model_name.c_str());
                //ignition::math::Pose3 initPose(ignition::math::Vector3<float>(x_pos_rand, y_pos_rand, z_pos_rand), ignition::math::Quaternion<float>(this->gimbal_roll, this->gimbal_pitch, this->gimbal_yaw));
                
                model->SetWorldPose(ignition::math::Pose3d(
                                    ignition::math::Vector3d(this->gimbal_pose.position.x + this->gimbal_length * this->x_dir, 
                                                             this->gimbal_pose.position.y + this->gimbal_length * this->y_dir, 
                                                             this->gimbal_pose.position.z + this->gimbal_length * this->z_dir - 0.05),
                                    ignition::math::Quaternion<double>(this->gimbal_pose.orientation.w, this->gimbal_pose.orientation.x,
                                                            this->gimbal_pose.orientation.y, this->gimbal_pose.orientation.z))
                                    );

            }

            

        }

        
        void SetForceBullet(boost::shared_ptr<gazebo::physics::Model> model)
        {
            
            std::string model_name = model->GetName();

            double x_axis_force;
            double y_axis_force;
            double z_axis_force;

            x_axis_force = this->x_dir * this->force;
            y_axis_force = this->y_dir * this->force;
            z_axis_force = this->z_dir * this->force;

            // If the model name contains the substring particle, we consider it a particle
            if (model_name.find(this->bullet_link_name) != std::string::npos)
            {
                ROS_WARN("FORCE APPLIED[X,Y,Z]=[%f,%f,%f]", x_axis_force, y_axis_force, z_axis_force);
                model->GetLink("link")->SetForce(ignition::math::Vector3d(x_axis_force, y_axis_force, z_axis_force));
            }
        }


        // public: void SetFrequency(const double &_freq)
        // {
        // this->x_axis_freq = _freq;
        // ROS_WARN("x_axis_freq >> %f", this->x_axis_freq);
        // }
        
        // public: void SetMagnitude(const double &_magn)
        // {
        // this->x_axis_magn = _magn;
        // ROS_WARN("x_axis_magn >> %f", this->x_axis_magn);
        // }
        
        
        // public: void OnRosMsg(const std_msgs::Float32ConstPtr &_msg)
        // {
        // this->SetFrequency(_msg->data);
        // }
        
        // /// \brief ROS helper function that processes messages
        // private: void QueueThread()
        // {
        // static const double timeout = 0.01;
        // while (this->rosNode->ok())
        // {
        //     this->rosQueue.callAvailable(ros::WallDuration(timeout));
        // }
        // }
        
        
        // Pointer to the update event connection
        private: event::ConnectionPtr updateConnection;
        

        /// \brief A node use for ROS transport
        // private: std::unique_ptr<ros::NodeHandle> rosNode;
        
        // /// \brief A ROS subscriber
        // private: ros::Subscriber rosSub;
        // /// \brief A ROS callbackqueue that helps process messages
        // private: ros::CallbackQueue rosQueue;
        // /// \brief A thread the keeps running the rosQueue
        // private: std::thread rosQueueThread;
        
        
        // /// \brief A ROS subscriber
        // private: ros::Subscriber rosSub2;
        // /// \brief A ROS callbackqueue that helps process messages
        // private: ros::CallbackQueue rosQueue2;
        // /// \brief A thread the keeps running the rosQueue
        // private: std::thread rosQueueThread2;

        private:
            gazebo::physics::ModelPtr model_;

            ros::NodeHandle ros_nh_;

            // ros::Publisher ros_shoot_info_pub_;
            // ros::Publisher ros_shoot_state_pub_;

            ros::ServiceServer ros_ctrl_fric_wheel_srv_;
            ros::ServiceServer ros_ctrl_shoot_srv_;

            ros::ServiceClient gazebo_ros_link_state;

            geometry_msgs::Pose gimbal_pose;
            gazebo_msgs::GetLinkState srv;
            gazebo_msgs::GetLinkState srv_;

            std::string gimbal_link;
            std::string fake_link;
            std::string reference_frame_;

            ignition::math::Quaternion<double> *q_;

        /// \brief Maps model IDs to ModelNames
        private: std::map<int, std::string> linkIDToName;
        
        
        // Update Loop frequency, rate at which we restart the positions and apply force to particles
        double reset_frequency = 2.0;
        // Time Memory
        double old_secs;

        double force;

        // double gimbal_roll;
        // double gimbal_pitch;
        // double gimbal_yaw;

        double gimbal_length = 0.2;

        double x_dir;
        double y_dir;
        double z_dir;

        int linkIDToName_size = 0;
        int link_to_update_index_now = 0;
        
        std::string bullet_link_name = "bullet";
    };
    GZ_REGISTER_MODEL_PLUGIN(RobortsShooterPlugin)
}