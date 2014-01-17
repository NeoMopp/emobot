cmake_minimum_required(VERSION 2.8)
project(emobot_eyes)

find_package(OpenCV REQUIRED)

include_directories(include home/pi/git/robidouille/raspicam_cv)

link_directories(~/git/emobot/libfacerec0.04)

add_executable(emobot_eyes main.cpp)
target_link_libraries(emobot_eyes  ${OpenCV_LIBS})
target_link_libraries(emobot_eyes home/pi/git/raspberrypi/userland/build/lib -lmmal_core -lmmal -l mmal_util -lvcos -lbcm_host)
target_link_libraries(emobot_eyes home/pi/git/robidouille/raspicam_cv)
