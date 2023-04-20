#include <opencv2/core/utility.hpp>
#include <opencv2/tracking.hpp>
#include <opencv2/videoio.hpp>
#include <opencv2/highgui.hpp>
#include <iostream>
#include <cstring>

#define RTSP_VIDEO 	1
#define LOCAL_VIDEO !RTSP_VIDEO

using namespace std;
using namespace cv;

Mat frame;
Rect2d roi;
bool finished = false;
bool trackinit = false;

void mouse(int event,int x,int y,int flags,void*)
{
	if (event == CV_EVENT_LBUTTONDOWN)//按下左键
    {
		roi.x = x;
		roi.y = y;
        cout << x << " " << y << endl;
    }
	if(event == EVENT_MOUSEMOVE && (flags & EVENT_FLAG_LBUTTON))//按住左键移动
	{
		roi.width = x - roi.x;
		roi.height = y - roi.y;
		cout << "width=" << roi.width << endl;
		cout << "height=" << roi.height << endl;
		rectangle(frame,roi,Scalar(0,0,255),1,8,0);
	}
	if(event == EVENT_LBUTTONUP)
	{
		finished = true;//绘制完成
	}
}

int main() {
	printf("还有bug,及时修改！\r\nRTSP_VIDEO为1时画框还有问题！\r\n");
#if RTSP_VIDEO
	setMouseCallback("tracker",mouse,0);
	std::string video = "rtsp://admin:admin@192.168.0.111:554/profile1";
#else
	std::string video = "../1.mp4";
#endif
	Ptr<Tracker> tracker = TrackerKCF::create();
	VideoCapture cap(video);
	if(!cap.isOpened())
	{
		cout << "VideoCapture is not opened" << endl;
		return -1;
	}
	cap >> frame;
	cout << "fps:" << cap.get(CAP_PROP_FPS) << endl;
	cout << "width:" << cap.get(CAP_PROP_FRAME_WIDTH) << endl;
	cout << "height:" << cap.get(CAP_PROP_FRAME_HEIGHT) << endl;
#if !RTSP_VIDEO
	roi = selectROI("tracker", frame);
	if (roi.width == 0 || roi.height == 0)
		return 0;
	tracker->init(frame, roi);
	printf("Start the tracking process\n");
#endif
	for (;; ) {
		cap >> frame;
		if (frame.rows == 0 || frame.cols == 0)
			break;
#if RTSP_VIDEO
		if(finished)
		{
			if(!trackinit)
			{
				finished = false;
				if (roi.width == 0 || roi.height == 0)
					return 0;
				tracker->init(frame, roi);
				trackinit = true;
			}
			else//画完了且初始化过->开始跟踪
			{
				tracker->update(frame,roi);
				rectangle(frame,roi,Scalar(0,0,255),1,8,0);
			}

		}
		
#else
		tracker->update(frame, roi);
		rectangle(frame, roi, Scalar(255, 0, 0), 2, 1);
#endif

		imshow("tracker", frame);
		if (waitKey(1) == 27)
			break;
	}

	return 0;
}

