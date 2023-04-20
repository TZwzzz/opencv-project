#ifndef OBJECT_DETECT_H_
#define OBJECT_DETECT_H_

#include <opencv2/opencv.hpp>
#include <opencv2/dnn.hpp>
#include <iostream>
#include <unistd.h>
#include <pthread.h>
#include <bits/pthreadtypes.h>

#include "putUrlPic.h"

using namespace std;
using namespace cv;
using namespace cv::dnn;

int objectDetect_init(float Threshold = 0.5);
void *objectDetect_thread(void *arg);
void*frameThread(void *arg);
void *guiThread(void *arg);

#endif