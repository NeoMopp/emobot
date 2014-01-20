CFLAGS_OPENCV:= -I/usr/include/opencv
CLFAGS_OPENCV2:= -I/usr/include/opencv2
LDFLAGS2_OPENCV:= -lopencv_highgui -lopencv_core -lopencv_legacy -lopencv_video -lopencv_features2d -lopencv_calib3d -lopencv_imgproc
CC := g++
HOME := /home/pi
LDFLAGS_CAMCV := -L$(HOME)/git/robidouille/raspicam_cv -lraspicamcv
LDFLAGS_USER := -L$(HOME)/git/raspberrypi/userland/build/lib -lmmal_core -lmmal -l mmal_util -lvcos -lbcm_host
LDFLAGS_FACE := -L$(HOME)/git/emobot/libfacerec0.04 -lopencv_facerec
LDFLAGS = $(LDFLAGS_CAMCV) $(LDFLAGS_USER) $(LDFLAGS_FACE) $(LDFLAGS2_OPENCV) $(LDFLAGS_OPENCV2) 
INCLUDE := -I$(HOME)/git/robidouille/raspicam_cv
INCLUDE_FACE := -I$(HOME)/git/emobot/libfacerec0.04/include

all: emobot_test

emobot_test:
	$(CC)  -o emobot_test.exe main.cpp  $(INCLUDE) $(LDFLAGS) $(INCLUDE_FACE)
