// Vision_3.01v 
// Kwak Donghwan


//////////////////////////preprocesser define////////////////////////////
#define BASIC_FUNTION  //this is for basic function
#define DISPLAY  // control opencv_ imshow function 
//#define DEBUG  //show what function start and worked
//#define VIRTUAL  // for mechine learning code with object detection

//#define VISION_DATACHECK //show visoin output data such as number of detection
#define ZIMBAL_DATACHECK //show zimbal`s output data such as angle
 
#ifndef BASIC_FUNTION
#define MAKEING_IMG //this fucntion is making a img
#ifdef MAKEING_IMG 
#define ADD_DEEPLEARNING  //makeing image while using object detection
#endif
#endif

#include "src/all.hpp"

void main() {
	data_control CT_data; //define basic data class
	vision_camera camera; //camera class initialize
	vision_detector detector; //object detector class setup
	
	while (true) {

		camera.vision_camera_run(CT_data);  //get camera_color_image
		detector.vision_detector_run(CT_data);  //run object detector and assign output data

	}


}