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


//additional includes so we can send commands to serial
#include <termios.h>
#include <fcntl.h>
#include <sys/ioctl.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <string.h>
#include <unistd.h>

using namespace std;
using namespace cv;




void sendAction(double& happiness, int& fd)
{
	char msg[] = "SOUND PLAY 63;";	
	write(fd, msg, strlen(msg));
}



//Main of program argc is the number of arguments while argv is the arguments
//said argument are normally locations of files
int main(int argc, char* argv[])
{

	
	//initalize variables
	double happiness = 0;				//Keepon's happiness rating
	int fd = open("/dev/ttyACM0", O_RDWR);		//needed for the serial write
	if (fd == -1) 	
	{
  		perror("/dev/ttyACM0");
  		cout<<"Failed to connect";
  		return 1;
	}

	//Set up the serial port to allow for writing to it.
	struct termios tios;
	tcgetattr(fd, &tios);
	// disable flow control and all that, and ignore break and parity errors
	tios.c_iflag = IGNBRK | IGNPAR;
	tios.c_oflag = 0;
	tios.c_lflag = 0;
	cfsetspeed(&tios, B115200);
	tcsetattr(fd, TCSAFLUSH, &tios);
	
	// the serial port has a brief glitch once we turn it on which generates a
	// start bit; sleep for 1ms to let it settle
	sleep(1000);
	
	int i;
	cin>>i;
	//Need to tell user to connect keepon up and check we can connect
	sendAction(happiness, fd);


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

		//Hold faces
		vector<Rect> faces;
		
		face_cascade.detectMultiScale(greyscaleFrame, faces, 1.1, 3, CV_HAAR_SCALE_IMAGE, Size(30,30));
		imshow("outputCapture", captureFrame);
				
		//check for faces and change value of happiness dependent of if there is a face.
		if (faces.size() > 1)
		{
			happiness += 10.0;
		}
		else 
			happiness -= 0.5;

		if (waitKey(10) == 27)
		{
			cout<<"Process ended"<<endl;
			break;
		}
	}
	return 0;
}
