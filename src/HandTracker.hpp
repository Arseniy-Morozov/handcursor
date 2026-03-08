#pragma once
#include <vector>
#include <opencv2/opencv.hpp>



class HandTracker {
public:
    struct Landmark {
    float x, y, z;
    };
    bool init();
    bool handDetected() const;
    bool processFrame(cv::Mat& frame);
    const std::vector<Landmark>& getLandmarks() const;
private:

    bool detected_ = false;
    std::vector<Landmark> landmarks_;
};
