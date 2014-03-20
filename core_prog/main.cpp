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


//Main of program argc is the number of arguments while argv is the arguments
//said argument are normally locations of files
int main(int argc, char* argv[])
{
	
	
	//create classifier and load a cascade file into it, to allow for face detection.
	CascadeClassifier face_cascade;
	face_cascade.load("haarcascade_frontalface_alt.xml");
	if (face_cascade.empty() == true)
	{cout<<"empty";}
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
		imshow("outputCapture", captureFrame);
		//Write to text file
		if (faces.size() > 0)
		{
			ofstream myfile ("faces.txt");
			if (myfile.is_open())
			{
				myfile<< "1";
				myfile.close();
			}
			else cout<< "Unable to openfile";
		}

		if (waitKey(10) == 27)
		{
			cout<<"Process ended"<<endl;
			break;
		}
	}
	return 0;
}
