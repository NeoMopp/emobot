cmake_minimum_required(VERSION 2.8)
project(emobot)

find_package(OpenCV REQUIRED)

include_directories(I$(HOME)/git/robidouille/raspicam_cv)

link_directories(I$(HOME)/git/emobot/libfacerec0.04)

add_executable(emobot main.cpp)
#target_link_libraries(L$(HOME)/git/robidouille/raspicam_cv -lraspicamcv)
#target_link_libraries(L$(HOME)/git/raspberrypi/userland/build/lib -lmmal_core -lmmal -l mmal_util -lvcos -lbcm_host)
target_link_libraries( displayimage ${OpenCV_LIBS} L$(HOME)/git/raspberrypi/userland/build/lib -lmmal_core -lmmal -l mmal_util -lvcos -lbcm_host L$(HOME)/git/robidouille/raspicam_cv -lraspicamcv)
