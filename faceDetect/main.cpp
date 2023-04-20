#include "main.h"

int main(int argc,char *argv[])
{
    if(2 != argc)
    {
        fprintf(stderr,"Usage:%s ${PICTURE NAME}\r\n",argv[0]);
        return -1;
    }
    Mat img = imread(argv[1]);
    faceDetect_init(0.5);
    clock_t  startTime = clock();
    vector<ret_rect> result = faceDetect(argv[1]);
    clock_t endTime = clock();
    double totalTime = (double)(endTime - startTime) / CLOCKS_PER_SEC;
    cout << totalTime << "s" << endl;
    cout << "Num of face:" << result.size() << endl;
    for(int i = 0;i < result.size();i++)
    {
        printf("result[%d]:%d\t%d\t%d\t%d\t%.2f\r\n",
            i,result.at(i).topLx,result.at(i).topLy,
            result.at(i).width,result.at(i).height,result.at(i).threshold);
    }
    cout << "Enter any key close" << endl;
    waitKey(0);

    return 0;
}