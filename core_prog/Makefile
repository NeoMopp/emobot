CFLAGS:= 'pkg-config --cflags opencv --libs opencv'
CC := g++
HOME := /home/pi
LDFLAGS_CAMCV := -L$(HOME)/git/robidouille/raspicam_cv -lraspicamcv
LDFLAGS_USER := -L$(HOME)/git/raspberrypi/userland/build/lib -lmmal_core -lmmal -l mmal_util -lvcos -lbcm_host
LDFLAGS_FACE := -L$(HOME)/git/emobot/libfacere0.04
LDFLAGS = $(LDFLAGS_CAMCV) $(LDFLAGS_USER) $(LDFLAGS_FACE)
INCLUDE := -I$(HOME)/git/robidouille/raspicam_cv

all: emobot_test

emobot_test:
	$(CC)  -o emobot_test.exe main.cpp  $(INCLUDE) $(LDFLAGS)
