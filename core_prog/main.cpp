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

//includes to allow for threading
#include <thread>

using namespace std;
using namespace cv;

double happiness;
bool keepConnected;

void sendAction()
{
	int fd = open("/dev/ttyACM0", O_RDWR);		//needed for the serial write
	if (fd == -1)
	{
  		perror("/dev/ttyACM0");
  		cout<<"Failed to connect to Arduino. Please connect Arduino.";
  //		return 1;
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
	usleep(1000);
	while (!keepConnected)
	{
		//Need to tell user to connect keepon up and check we can connect
		cout<<"Is Keepon Connected(Y/N)?: ";
		string input;
		getline(cin, input);
		if (input.find("Y") != std::string::npos)
		{		
			cout<<"Perfoming test."<<endl;
			char msg[] = "MOVE PON UP;";
			write(fd, msg, strlen(msg));
			strcpy(msg, "MOVE PON DOWN;");
			write(fd, msg, strlen(msg));
			cout<<"Was the test a success(Y/N)?:"<<endl;
			getline(cin, input);
			if (input.find("Y") != std::string::npos)
				keepConnected = true;
		}
		cout<<"Keepon needs to be connected please connect.";
	}

	while (keepConnected  == true)
	{
		//Sleep for 20seconds just to prevent loads of reapted emotions
		//sleep(20);
		if ((happiness > -10) && (happiness < 11))
		{
			char mst[] = ("MOVE TILT 0;");
			write(fd, mst, strlen(mst));
			strcpy(mst, "MOVE PAN 0;");
			write(fd, mst, strlen(mst));
		}
		if ((happiness > 10) && (happiness < 21))
		{			
			char mst[] = ("MOVE SIDE LEFT;");
			write(fd, mst, strlen(mst));
			strcpy(mst,"MOVE SIDE RIGHT;");
			write(fd, mst, strlen(mst));
			strcpy(mst,"SOUND PLAY 40;");
			write(fd, mst, strlen(mst));
			strcpy(mst,"MOVE SIDE LEFT;");
			write(fd, mst, strlen(mst));
			strcpy(mst,"MOVE SIDE RIGHT;");
			write(fd, mst, strlen(mst));
			strcpy(mst,"SOUND PLAY 40;");
			write(fd, mst, strlen(mst));
			strcpy(mst,"MOVE SIDE LEFT;");
			write(fd, mst, strlen(mst));
			strcpy(mst,"MOVE SIDE RIGHT;");
			write(fd, mst, strlen(mst));
			strcpy(mst,"SOUND PLAY 40;");
			write(fd, mst, strlen(mst));
		}
		if ((happiness > 20) && (happiness < 31))
		{
			char mst[] = ("MOVE SIDE LEFT;");
			write(fd, mst, strlen(mst));
			strcpy(mst,"MOVE SIDE RIGHT;");
			write(fd, mst, strlen(mst));
			strcpy(mst,"MOVE PON UP;");
			write(fd, mst, strlen(mst));
			strcpy(mst,"MOVE PON DOWN;");
			write(fd, mst, strlen(mst));
			strcpy(mst,"MOVE SIDE LEFT;");
			write(fd, mst, strlen(mst));
			strcpy(mst,"MOVE SIDE RIGHT;");
			write(fd, mst, strlen(mst));
			strcpy(mst,"MOVE PON UP;");
			write(fd, mst, strlen(mst));
			strcpy(mst,"MOVE PON DOWN;");
			write(fd, mst, strlen(mst));
		}
		if ((happiness > 30) && (happiness < 41))
		{
			char mst[] = ("MOVE SIDE LEFT;");
			write(fd, mst, strlen(mst));
			strcpy(mst,"MOVE SIDE RIGHT;");
			write(fd, mst, strlen(mst));
			strcpy(mst,"SOUND PLAY 58;");
			write(fd, mst, strlen(mst));
			strcpy(mst,"MOVE SIDE LEFT;");
			write(fd, mst, strlen(mst));
			strcpy(mst,"MOVE SIDE RIGHT;");
			write(fd, mst, strlen(mst));
			strcpy(mst,"SOUND PLAY 58;");	
			write(fd, mst, strlen(mst));
			strcpy(mst,"MOVE PON UP;");
			write(fd, mst, strlen(mst));
			strcpy(mst,"MOVE PON DOWN;");
			write(fd, mst, strlen(mst));
			strcpy(mst,"SOUND PLAY 58;");
			write(fd, mst, strlen(mst));
		}
		if ((happiness > 40) && (happiness < 51))
		{
			char mst[] = ("MOVE LEFT;");
			write(fd, mst, strlen(mst));
			strcpy(mst,"MOVE RIGHT;");
			write(fd, mst, strlen(mst));
			strcpy(mst,"MOVE PON UP;");
			write(fd, mst, strlen(mst));
			strcpy(mst,"MOVE PON DOWN;");
			write(fd, mst, strlen(mst));
			strcpy(mst,"SOUND PLAY 48;");
			write(fd, mst, strlen(mst));
			strcpy(mst,"MOVE PAN 50;");
			write(fd, mst, strlen(mst));
			strcpy(mst,"MOVE LEFT;");
			write(fd, mst, strlen(mst));
			strcpy(mst,"MOVE RIGHT;");
			write(fd, mst, strlen(mst));
			strcpy(mst,"MOVE PON UP;");
			write(fd, mst, strlen(mst));
			strcpy(mst,"MOVE PON DOWN;");
			write(fd, mst, strlen(mst));
			strcpy(mst,"SOUND PLAY 48;");
			write(fd, mst, strlen(mst));
			strcpy(mst,"MOVE PAN -50;");
			write(fd, mst, strlen(mst));
			strcpy(mst,"MOVE LEFT;");
			write(fd, mst, strlen(mst));
			strcpy(mst,"MOVE RIGHT;");
			write(fd, mst, strlen(mst));
			strcpy(mst,"MOVE PON UP;");
			write(fd, mst, strlen(mst));
			strcpy(mst,"MOVE PON DOWN;");
			write(fd, mst, strlen(mst));
			strcpy(mst,"SOUND PLAY 48;");
			write(fd, mst, strlen(mst));
			strcpy(mst,"MOVE PAN 0;");
			write(fd, mst, strlen(mst));
		}

		if ((happiness > -20) && (happiness < -11))
		{
			char mst[] = ("MOVE TILT -100;");
			write(fd, mst, strlen(mst));
			strcpy(mst,"MOVE PAN -25;");
			write(fd, mst, strlen(mst));
			strcpy(mst,"MOVE PAN 25;");
			write(fd, mst, strlen(mst));
			strcpy(mst,"MOVE PAN 0;");
			write(fd, mst, strlen(mst));
			strcpy(mst,"MOVE PON UP;");
			write(fd, mst, strlen(mst));
			strcpy(mst,"MOVE PON DOWN;");
			write(fd, mst, strlen(mst));
			strcpy(mst,"MOVE TILT 100;");
			write(fd, mst, strlen(mst));
			strcpy(mst,"SOUND PLAY 23;");
			write(fd, mst, strlen(mst));
		}
		if ((happiness > -30) && (happiness < -21))
		{
			char mst[] = ("SOUND PLAY 23;");
			write(fd, mst, strlen(mst));
			strcpy(mst,"MOVE TILT 100;");
			write(fd, mst, strlen(mst));
			strcpy(mst,"MOVE PAN 25;");
			write(fd, mst, strlen(mst));
			strcpy(mst,"MOVE TILT -100;");
			write(fd, mst, strlen(mst));
			strcpy(mst,"MOVE TILT 0;");
			write(fd, mst, strlen(mst));
			strcpy(mst,"MOVE PAN -25;");
			write(fd, mst, strlen(mst));
			strcpy(mst,"MOVE TILT -100;");
			write(fd, mst, strlen(mst));
			strcpy(mst,"SOUND PLAY 23;");
			write(fd, mst, strlen(mst));
			strcpy(mst,"MOVE TILT 0;");
			write(fd, mst, strlen(mst));
		}
		if ((happiness > -40) && (happiness < -31))
		{
			char mst[] = ("MOVE SIDE LEFT;");
			write(fd, mst, strlen(mst));
			strcpy(mst,"MOVE SIDE RIGHT;");
			write(fd, mst, strlen(mst));
			strcpy(mst,"MOVE SIDE LEFT;");
			write(fd, mst, strlen(mst));
			strcpy(mst,"MOVE SIDE RIGHT;");
			write(fd, mst, strlen(mst));
			strcpy(mst,"MOVE TILT -100;");
			write(fd, mst, strlen(mst));
			strcpy(mst,"SOUND PLAY 23;");
			write(fd, mst, strlen(mst));
			strcpy(mst,"MOVE TILT 0;");
			write(fd, mst, strlen(mst));
		}
		if ((happiness > -50) && (happiness < -41))
		{
			char mst[] = ("SOUND PLAY 23;");
			write(fd, mst, strlen(mst));
			strcpy(mst,"MOVE TILT 100;");
			write(fd, mst, strlen(mst));
			strcpy(mst,"MOVE PAN 25;");
			write(fd, mst, strlen(mst));
			strcpy(mst,"MOVE PAN -25;");
			write(fd, mst, strlen(mst));
		}

	}
//return 1;
}




void faceDetect()
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
//		return -1;
	}
	//create some matricies to be used in the program.
	Mat captureFrame;
	Mat greyscaleFrame;

	//need a temporary varibale to ensure we dont keep detecting faces and spike values wayyy to high.
	//boolean to check if someone was in the last frame
	int counter = 0;
	bool lastScene = false;
	
	//Make window for the output to be displayed in.
	cvNamedWindow("outputCapture",1);

	while (!keepConnected)
	{
		//cout<<"Waiting..."<<endl;
	}

	//loop to continuously find a face
	while (keepConnected)
	{
		//Check if counter exceeds 100, if it does set it to 0
		if (counter > 100)
			counter = 0;

		//get a new frame
		//captureFrame = cvQueryFrame(captureDevice);
		captureFrame = raspiCamCvQueryFrame(captureDevice);

		//convert frame to greyscale and equalize
		cvtColor(captureFrame, greyscaleFrame, CV_BGR2GRAY);
		equalizeHist(greyscaleFrame, greyscaleFrame);

		//Hold faces
		vector<Rect> faces;
		
		face_cascade.detectMultiScale(greyscaleFrame, faces, 1.1, 3, CV_HAAR_SCALE_IMAGE, Size(30,30));
		
		//Here we output what the camera sees		
		imshow("outputCapture", captureFrame);
		//Drawing rectangles around the faces
		for(int i = 0; i < faces.size(); i++)
        	{
            		Point pt1(faces[i].x + faces[i].width, faces[i].y + faces[i].height);
            		Point pt2(faces[i].x, faces[i].y);
 			rectangle(captureFrame, pt1, pt2, cvScalar(0, 255, 0, 0), 1, 8, 0);
        	}

				
		//check for faces and change value of happiness dependent of if there is a face.
		if (faces.size() > 0)
		{
			if (lastScene == false && counter == 0)
			{
				happiness += 10.0;
				counter++;
			}
			else 
			{
				happiness += 3.0;
				counter++;
			}			
			cout<<"Faces: "<<faces.size()<<endl;
			if (happiness > 50.0)
				happiness = 50.0;
			lastScene = true;
		}
		else 
		{
			lastScene = false;
			happiness -= 0.5;
			cout<<"Faces: "<<faces.size()<<endl;
			if (happiness < -50.0)
				happiness = -50.0;
		}
		if (waitKey(5) == 27)
		{
			cout<<"Process ended"<<endl;
			break;
		}
	}
//return 1;
}

//Main of program argc is the number of arguments while argv is the arguments
//said argument are normally locations of files
int main(int argc, char* argv[])
{
	//initalize variables
	happiness = 0;				//Keepon's happiness rating
	keepConnected = false;
	thread camera(faceDetect);		//Start the faceDetection thread
	thread action(sendAction);		//start the Keepon Control thread
	
	//wait till threads have completed.
	camera.join();
	action.join();
	return 0;
}
