#include <opencv2/highgui/highgui.hpp>
#include <opencv2/objdetect/objdetect.hpp>
#include <opencv2/imgproc/imgproc.hpp>

#include <iostream>
#include <stdio.h>

using namespace std;
using namespace cv;

int main(int argc, char* argv[])
{
	
	
	//create classifier and load a cascade file into it, to allow for face detection.
	CascadeClassifier face_cascade;
	face_cascade.load("C:\\openCV\\data\\haarcascades\\haarcascade_frontalface_alt.xml");

	//set VideoCapture variable and link it to camera.
	VideoCapture captureDevice;
	captureDevice.open(0);

	//check to see if capture device is "real" and alert user if it isn't.
	if (!captureDevice.isOpened())
	{
		cout<<"Capture device not found please fix"<<endl;
		return -1;
	}
	
	//create some matricies to be used in the program.
	Mat captureFrame;
	Mat greyscaleFrame;
	
	//Make window for the output to be displayed in.
	namedWindow("outputCapture",1);

	//loop to continuously find a face
	while (1)
	{
		//get a new frame
		captureDevice>>captureFrame;

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
		if (waitKey(30) == 27)
		{
			cout<<"Process ended"<<endl;
			break;
		}
	}
	return 0;
}
