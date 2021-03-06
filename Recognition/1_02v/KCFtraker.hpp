#pragma once
#include "allign.hpp"

// 참조 문서 https://www.learnopencv.com/multitracker-multiple-object-tracking-using-opencv-c-python/


using namespace cv;
using namespace std;
 
// Convert to string
#define SSTR( x ) static_cast< std::ostringstream & >( \
( std::ostringstream() << std::dec << x ) ).str()



static Ptr<Tracker> createTrackerByName(string trackerType)
{
	/*사용가능한 opencv 3.4.1 버젼의 traker*/
	vector<string> trackerTypes = { "BOOSTING", "MIL", "KCF", "TLD", "MEDIANFLOW", "GOTURN", "MOSSE", "CSRT" };
	Ptr<Tracker> Tracker;

	if (trackerType == trackerTypes[0])
		Tracker = TrackerBoosting::create();
	else if (trackerType == trackerTypes[1])
		Tracker = TrackerMIL::create();
	else if (trackerType == trackerTypes[2])
		Tracker = TrackerKCF::create();
	else if (trackerType == trackerTypes[3])
		Tracker = TrackerTLD::create();
	else if (trackerType == trackerTypes[4])
		Tracker = TrackerMedianFlow::create();
	else if (trackerType == trackerTypes[5])
		Tracker = TrackerGOTURN::create();
	else if (trackerType == trackerTypes[6])
		Tracker = TrackerMOSSE::create();
	else if (trackerType == trackerTypes[7])
		Tracker = TrackerCSRT::create();

	else {
		cout << "Incorrect tracker name" << endl;
		cout << "Available trackers are: " << endl;
		for (vector<string>::iterator it = trackerTypes.begin(); it != trackerTypes.end(); ++it)
			std::cout << " " << *it << endl;
	}
	return Tracker;
}



static bool Set_MultiTracker(Ptr<MultiTracker> multiTracker, Mat *frame /*base data*/, string trackerTypes ,double height[], double width[], double x[], double y[]) {
	static int index;
	vector<Rect2d> bboxes;
	

	/*object가 없어서 트래킹을 종료하는 것.*/


	for (index = 0; index < 3; index++) {


		Rect2d bbox(height[index], width[index], x[index], y[index]);;
		bboxes[index] = bbox;

	}
	if (bboxes.size() < 1)

		return false;
	
	bool showCrosshair = true;
	bool fromCenter = false;



	/*multiTraker를 생성한다.*/

	
	for (int i = 0; i < bboxes.size(); i++)
		multiTracker->add(createTrackerByName(trackerTypes), *frame, Rect2d(bboxes[i]));

	return true;

}







static int KCFTraker_Run(Mat *frame /*base data*/, Mat *frame2 /*detecting*/ , Ptr<MultiTracker> multiTracker, double height[], double width[], double x[], double y[])  //손봐야함
{
   static int index;

	/*
    // 비디오 파일 읽는 코드, 실제로는 사용하지 않음
    VideoCapture video("videos/chaplin.mp4");
     
    // Exit if video is not opened
    if(!video.isOpened())
    {
        cout << "Could not read video file" << endl; 
        return 1; 
    } */
    // 박스들을 정의한다. 

		
	multiTracker->update(*frame2);

	Rect2d result[3];
	/*트래킹 결과 출력 */
	for (index = 0; index < 3; index++) {
		if (index = multiTracker->getObjects().size()) {
			break;
		}
		result[index] = multiTracker->getObjects()[index];

		height[index] = result[index].height;
		width[index] = result[index].width;
		x[index] = result[index].x;
		y[index] = result[index].y;

	}

	/* Draw tracked objects
	for (unsigned i = 0; i < multiTracker->getObjects().size(); i++)
	{
			rectangle(*frame, multiTracker->getObjects()[i], colors[i], 2, 1);
	}
	*/

#pragma region single traking
/*
   //  Rect2d bbox(*height, *width, *x, *y);
 
    // Uncomment the line below to select a different bounding box 
    // bbox = selectROI(frame, false); 
    // Display bounding box. 
    // rectangle(frame, bbox, Scalar( 255, 0, 0 ), 2, 1 );  사각형을 그릴 필요는 없다. 
 
    //imshow("Tracking", *frame);
    // tracker->init(*frame, bbox);


	//함수 자체안에서 while문으로 돌면 안된다. 따라서 이 함수는 한번만 돌려야하는데 계속 하는 것은 좋지 않을 것같다. KCFtraker는 한번만 만들어주는게 좋을 것같다. 
     
     
    // Start timer
    // double timer = (double)getTickCount();
     
    // Update the tracking result
    // bool ok = tracker->update(*frame2, bbox);
     
    // Calculate Frames per second (FPS)  >> 굳이 할 필요는 없음.
    // float fps = getTickFrequency() / ((double)getTickCount() - timer);
	if (ok)
	{
        // Tracking success : Draw the tracked object
        //rectangle(*frame2, bbox, Scalar( 255, 0, 0 ), 2, 1 );
		*height = bbox.height;
		*width = bbox.width;
		*x = bbox.x;
		*y = bbox.y;

    }
    else
    {
        // Tracking failure detected.  >> 이경우 다른 값을 반환하는 것이 필요할듯,. 
        putText(*frame, "Tracking failure detected", Point(100,80), FONT_HERSHEY_SIMPLEX, 0.75, Scalar(0,0,255),2);

    }
*/
#pragma endregion 단일 트래킹 코드 지금은 미사용
     
}


    
#pragma region 쓰래기
	//나중에 재귀함수 호출하는 방법도 좋은 시도일것 같다. 
     
    // Display tracker type on frame >> 무슨 트래커를 썻는지 집어 넣는 건데 연산 최소화를 위해서 필요없음
    //putText(frame, trackerType + " Tracker", Point(100,20), FONT_HERSHEY_SIMPLEX, 0.75, Scalar(50,170,50),2);
     
    // Display FPS on frame >> 이것도 굳이 할 필요는 ㅇ벗음. 
    // putText(frame, "FPS : " + SSTR(int(fps)), Point(100,50), FONT_HERSHEY_SIMPLEX, 0.75, Scalar(50,170,50), 2);
 
    // Display frame. >> 굳이 보여줄 필요 없음
    // imshow("Tracking", frame);
#pragma endregion 쓰래기 값들
     

 
    


static void KCFTraker_Cordinate_control(int Center_X[], int Center_Y[], double height[], double width[], double KDF_X[], double KCF_Y[])
{
	static int index;
	for (index = 0; index < 3; index++) {
		if (!Center_X[index] == 0 || !Center_Y[index] == 0) {
			KDF_X[index] = (Center_X[index]) - ((width[index]) * 0.5);
			KCF_Y[index] = (Center_Y[index]) - ((height[index]) * 0.5);
		}
	}
}