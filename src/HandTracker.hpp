#pragma once
#include <vector>
#include <opencv2/opencv.hpp>



class HandTracker {
public:
    static constexpr int THUMB_TIP  = 4;
    static constexpr int INDEX_TIP  = 8;
    static constexpr int INDEX_PIP  = 6;
    static constexpr int MIDDLE_TIP = 12;
    static constexpr int MIDDLE_PIP = 10;
    static constexpr int RING_TIP   = 16;
    static constexpr int RING_PIP   = 14;
    static constexpr int PINKY_TIP  = 20;
    static constexpr int PINKY_PIP  = 18;
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
    FILE* pipe_;
};
