#include <iostream>
#include "HandTracker.hpp"

bool HandTracker::init()
{
    std::cout << "HandTracker initialized\n";
    landmarks_.resize(21);
    pipe_ = popen("python3 /home/time/Desktop/hand_tracker.py", "r");
    if (!pipe_) return false;
    return true;


}

bool HandTracker::processFrame(cv::Mat& frame)
{
    char line[256];
    int count = 0;
    while(fgets(line, sizeof(line), pipe_))
    {
        if(strncmp(line, "---", 3) == 0)
        {
            detected_ = true;
            return true;
        }
        Landmark lm;
        sscanf(line, "%f,%f,%f", &lm.x, &lm.y, &lm.z);
        if (count < 21) landmarks_[count++] = lm;
        
    }
    return false;
}

bool HandTracker::handDetected() const
{
    return detected_;
}

const std::vector<HandTracker::Landmark>& HandTracker::getLandmarks() const
{
    return landmarks_;
}