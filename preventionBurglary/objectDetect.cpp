#include "objectDetect.h"

Mat frame;
Net net;
float confidenceThreshold;
float nmsThreshold = 0.3; // Non-maximum suppression threshold
vector<string> classes;

static void drawPred(int classId, float conf, int left, int top, int right, int bottom, Mat& framecopy)
{
    //Draw a rectangle displaying the bounding box
    rectangle(framecopy, Point(left, top), Point(right, bottom), Scalar(0, 0, 255), 8);
    
    //Get the label for the class name and its confidence
    string conf_label = format("%.2f", conf);
    string label="";
    if (!classes.empty())
    {
        label = classes[classId] + ":" + conf_label;
    }
    
    //Display the label at the top of the bounding box
    int baseLine;
    Size labelSize = getTextSize(label, FONT_HERSHEY_SIMPLEX, 0.5, 1, &baseLine);
    top = max(top, labelSize.height);
    putText(framecopy, label, Point(left, top),FONT_HERSHEY_SIMPLEX,3,Scalar(255,0,0),1,8);
    cout << "label: " << label << endl;
    string object = "person";
    if(label.find(object) == 0)
    {
        static int cnt = 0;
        cnt++;
        string picName = to_string(cnt) + label + ".jpg";
        imwrite(picName,framecopy);
        putUrlPic(picName.data());
    }
}

// Remove the bounding boxes with low confidence using non-maxima suppression
static void postprocess(Mat& framecopy, const vector<Mat>& outs)
{
    vector<int> classIds;
    vector<float> confidences;
    vector<Rect> boxes;
    
    for (size_t i = 0; i < outs.size(); ++i)
    {
        // Scan through all the bounding boxes output from the network and keep only the
        // ones with high confidence scores. Assign the box's class label as the class
        // with the highest score for the box.
        float* data = (float*)outs[i].data;
        for (int j = 0; j < outs[i].rows; ++j, data += outs[i].cols)
        {
            Mat scores = outs[i].row(j).colRange(5, outs[i].cols);
            Point classIdPoint;
            double confidence;
            // Get the value and location of the maximum score
            minMaxLoc(scores, 0, &confidence, 0, &classIdPoint);
            if (confidence > confidenceThreshold)
            {
                int centerX = (int)(data[0] * framecopy.cols);
                int centerY = (int)(data[1] * framecopy.rows);
                int width = (int)(data[2] * framecopy.cols);
                int height = (int)(data[3] * framecopy.rows);
                int left = centerX - width / 2;
                int top = centerY - height / 2;
                
                classIds.push_back(classIdPoint.x);
                confidences.push_back((float)confidence);
                boxes.push_back(Rect(left, top, width, height));
            }
        }
    }
    
    // Perform non maximum suppression to eliminate redundant overlapping boxes with
    // lower confidences
    vector<int> indices;
    NMSBoxes(boxes, confidences, confidenceThreshold, nmsThreshold, indices);
    for (size_t i = 0; i < indices.size(); ++i)
    {
        int idx = indices[i];
        Rect box = boxes[idx];
        drawPred(classIds[idx], confidences[idx], box.x, box.y,
                 box.x + box.width, box.y + box.height, framecopy);
    }
}

static vector<String> getOutputsNames(const Net& net)
{
    static vector<String> names;
    if (names.empty())
    {
        //Get the indices of the output layers, i.e. the layers with unconnected outputs
        vector<int> outLayers = net.getUnconnectedOutLayers();
        
        //get the names of all the layers in the network
        vector<String> layersNames = net.getLayerNames();
        
        // Get the names of the output layers in names
        names.resize(outLayers.size());
        for (size_t i = 0; i < outLayers.size(); ++i){
            names[i] = layersNames[outLayers[i] - 1];
        }
    }
    return names;
}


int objectDetect_init(float Threshold)
{
    String modelConfiguration = "/home/wilson/yolov3.cfg";
    String modelWeights = "/home/wilson/yolov3.weights";
    net = readNetFromDarknet(modelConfiguration, modelWeights);
    net.setPreferableBackend(DNN_BACKEND_OPENCV);
    net.setPreferableTarget(DNN_TARGET_CPU);
    if(net.empty())
    {
        cout << "Make sure you enter the correct model file" << endl;
        return -1;
    }
    //加载COCO分类词汇表
    string classesFile = "/home/wilson/coco.names";
    ifstream ifs(classesFile.c_str());
    string line;
    while(getline(ifs,line))
    {
        classes.push_back(line);
    }
    confidenceThreshold = Threshold;
    return 0;
}

void *objectDetect_thread(void *arg)
{
    while(frame.empty())
    {
        usleep(1000);
    }
    while(1)
    {
        Mat frame_copy = frame.clone();
        if(frame_copy.empty())
        {
            cout << "frame is empty" << endl;
            break;
        }
        Mat blobImage = blobFromImage(frame_copy,1.0/255,Size(416,416),Scalar(),true,false);
        net.setInput(blobImage);
        vector<Mat> outs;
        net.forward(outs,getOutputsNames(net));
        postprocess(frame_copy, outs);
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
        if (cv::waitKey(1) == 27) 
        {
            frame.release();
            break;
        }
    }
    pthread_exit(NULL);
}

// GUI 线程
void *guiThread(void *arg) 
{
    while (true) 
    {
        // 在 GUI 线程中显示当前帧
        cv::imshow("Video", frame);
        if (cv::waitKey(1) == 27) 
        {
            break;
        }
    }
    pthread_exit(NULL);
}
