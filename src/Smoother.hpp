#pragma once
#include <utility>  // for std::pair

class Smoother {
public:
    std::pair<float, float> smooth(float x, float y) {
        // first time init
        if (!initialized_) {
            smoothX_ = x;
            smoothY_ = y;
            initialized_ = true;
            return {smoothX_, smoothY_};
        }
        smoothX_ = alpha_ * x + (1 - alpha_) * smoothX_;
        smoothY_ = alpha_ * y + (1 - alpha_) * smoothY_;
        return {smoothX_, smoothY_};
    }

private:
    float smoothX_     = 0.0f;
    float smoothY_     = 0.0f;
    float alpha_       = 0.05f;
    bool  initialized_ = false;
};