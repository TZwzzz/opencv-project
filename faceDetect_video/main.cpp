#include "main.h"

int main()
{
    // char *videoName = "rtsp://192.168.137.6/live/main_stream";
    char *videoName = "rtsp://admin:admin@192.168.0.112:554/profile1";
    pthread_t faceDetect_tid;
    pthread_t frameTid;

    faceDetect_init(0.3);
    pthread_create(&frameTid,NULL,frameThread,videoName);
    pthread_create(&faceDetect_tid,NULL,faceDetect_thread,NULL);
    pthread_join(frameTid,NULL);
    pthread_join(faceDetect_tid,NULL);
}