//openCV include directories
#include "opencv2/highgui/highgui.hpp"
#include "opencv2/objdetect/objdetect.hpp"
#include "opencv2/imgproc/imgproc.hpp"
#include "opencv2/core/core.hpp"
#include "opencv2/contrib/contrib.hpp"

//Requied t run on raspberryPi
#include "facerec.hpp"

//rapberrypicam_cv include directories
#include "RaspiCamCV.h"

//regular includes needed to compile
#include <iostream>
#include <fstream>
#include <sstream>
#include <stdio.h>


using namespace std;
using namespace cv;


//Allows for read in of csv files which are used to build the classifier.
//Code copied from Phillip Wagner 
//Source available at: http://docs.opencv.org/trunk/modules/contrib/doc/facerec/facerec_tutorial.html
//Needed incase we want to remember people at a later date.
//static void read_csv (const string& filename, vector<Mat>& images, vector<int>& labels, char separator = ';')
//{
//	ifstream file(filename.c_str(), ifstream::in);
//	if (!file)
//	{
//		string error_message = "No valid input file was given, please check the given filename.";
//		CV_Error(CV_StsBadArg, error_message);
//	}
//	string line, path, classlabel;
//	while (getline(file, line)) 
//	{
//       getline(liness, path, separator);
//       getline(liness, classlabel);
//        if(!path.empty() && !classlabel.empty()) 
//		{
//            images.push_back(imread(path, 0));
//            labels.push_back(atoi(classlabel.c_str()));
//       }
//	}
//}

//Main of program argc is the number of arguments while argv is the arguments
//said argument are normally locations of files
int main(int argc, char* argv[])
{
	
	
	//create classifier and load a cascade file into it, to allow for face detection.
	CascadeClassifier face_cascade;
	face_cascade.load("~/git/emobot/core_prog/haarcascade_frontalface_alt.xml");

	//set VideoCapture variable and link it to camera.
	//CvCapture *captureDevice = cvCreateCameraCapture(0);
	RaspiCamCvCapture *captureDevice = raspiCamCvCreateCameraCapture(0);


	//check to see if capture device is "real" and alert user if it isn't.
	if (!captureDevice)
	{
		cout<<"Capture device not found please fix"<<endl;
		return -1;
	}
	//create some matricies to be used in the program.
	Mat captureFrame;
	Mat greyscaleFrame;
	
	//Make window for the output to be displayed in.
	cvNamedWindow("outputCapture",1);

	//loop to continuously find a face
	while (1)
	{
		//get a new frame
		//captureFrame = cvQueryFrame(captureDevice);
		 captureFrame = raspiCamCvQueryFrame(captureDevice);

		//convert frame to greyscale and equalize
		cvtColor(captureFrame, greyscaleFrame, CV_BGR2GRAY);
		equalizeHist(greyscaleFrame, greyscaleFrame);

		
		vector<Rect> faces;

		face_cascade.detectMultiScale(greyscaleFrame, faces, 1.1, 3, CV_HAAR_SCALE_IMAGE, Size(30,30));

		for(int i = 0; i < faces.size(); i++)
        {
            Point pt1(faces[i].x + faces[i].width, faces[i].y + faces[i].height);
            Point pt2(faces[i].x, faces[i].y);
 
            rectangle(captureFrame, pt1, pt2, cvScalar(0, 255, 0, 0), 1, 8, 0);
        }
		cout<<faces.size()<<endl;

		imshow("outputCapture", captureFrame);
		if (waitKey(1000) == 27)
		{
			cout<<"Process ended"<<endl;
			break;
		}
	}
	return 0;
}
