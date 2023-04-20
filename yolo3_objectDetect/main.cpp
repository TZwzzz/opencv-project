#include "main.h"

int main()
{
    char videoName[] = "rtsp://admin:admin@192.168.0.112:554/profile1";
    objectDetect_init(0.4);
    pthread_t frameTid,objectDetectTid;
    pthread_create(&frameTid,NULL,frameThread,videoName);
    pthread_create(&objectDetectTid,NULL,objectDetect_thread,NULL);
    pthread_join(frameTid,NULL);
    pthread_join(objectDetectTid,NULL);

}