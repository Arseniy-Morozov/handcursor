#include <iostream>
#include "HandTracker.hpp"

bool HandTracker::init()
{
    std::cout << "HandTracker initialized\n";
    landmarks_.resize(21);
    return true;


}

bool HandTracker::processFrame(cv::Mat& frame)
{
    return true;
}

bool HandTracker::handDetected() const
{
    return detected_;
}

const std::vector<HandTracker::Landmark>& HandTracker::getLandmarks() const
{
    return landmarks_;
}