#include <iostream>
#include <opencv2/opencv.hpp>
#include "HandTracker.hpp"
using namespace std;

HandTracker tracker;


int main() {
    cv::VideoCapture cap(0);
    
    if (cap.isOpened())
    {

        cv::Mat frame;
        tracker.init();

        while (true) {
        cap >> frame;
        
        if (frame.empty()) break;
        tracker.processFrame(frame);
        cv::imshow("Window Name", frame);
        if (tracker.handDetected())
        {
            cout << "Hand Detected \n";
        }

        if (cv::waitKey(1) == 'q') break;
    }
    }


    
    
    return 0;
}