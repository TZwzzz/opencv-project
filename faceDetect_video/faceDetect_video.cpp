#include "faceDetect_video.h"

Net faceNet;
float confidenceThreshold;
Mat frame;

int faceDetect_init(double Threshold)
{
    String model_bin = "../ch12_face_age/opencv_face_detector_uint8.pb";
    String config_text = "../ch12_face_age/opencv_face_detector.pbtxt";
    faceNet = readNet(model_bin,config_text);
    if(faceNet.empty())
    {
        cout << "Make sure you enter the correct model file" << endl;
        return -1;
    }
    confidenceThreshold = Threshold;
    return 0;
}

void *faceDetect_thread(void *arg)
{
    while(frame.empty())
    {
        usleep(1000);
    }
    while(1)
    {
        if(frame.empty())
        {
            cout << "frame is empty" << endl;
            break;
        }
        Mat blobImage = blobFromImage(frame,1.0,Size(640,640),Scalar(),false,false);
        faceNet.setInput(blobImage,"data");
        Mat detect = faceNet.forward("detection_out");
        Mat detectionMat(detect.size[2],detect.size[3],CV_32F,detect.ptr<float>());
        for(int i = 0;i < detectionMat.rows;i++)
        {
            float threshold = detectionMat.at<float>(i,2);
            if(threshold > confidenceThreshold)
            {
                int topLx = detectionMat.at<float>(i,3) * frame.cols;
                int topLy = detectionMat.at<float>(i,4) * frame.rows;
                int width = detectionMat.at<float>(i,5) * frame.cols - topLx;
                int height = detectionMat.at<float>(i,6) * frame.rows - topLy;
                rectangle(frame,Rect(topLx,topLy,width,height),Scalar(0,0,255),2,8,0);
            }
        }
    }
    pthread_exit(NULL);
}

//视频流线程
void*frameThread(void *arg)
{
    VideoCapture video((char *)arg);
    if(!video.isOpened())
    {
        cout << "Make sure you enter the correct videoName" << endl;
        pthread_exit(NULL);
    }
    cout << "fps:" << video.get(CAP_PROP_FPS) << endl;
    cout << "width:" << video.get(CAP_PROP_FRAME_WIDTH) << endl;
    cout << "height:" << video.get(CAP_PROP_FRAME_HEIGHT) << endl;
    video >> frame;
    if(frame.empty())
    {
        cout << "frame is empty" << endl;
        pthread_exit(NULL);
    }
    pthread_t gui_tid;
    pthread_create(&gui_tid,NULL,guiThread,NULL);
    while(true)
    {
        video >> frame;
    }
}

// GUI 线程
void *guiThread(void *arg) {
    while (true) {
        // 在 GUI 线程中显示当前帧
        cv::imshow("Video", frame);
        if (cv::waitKey(1) == 27) {
            break;
        }
    }

    return NULL;
}
