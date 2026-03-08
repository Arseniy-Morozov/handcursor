#pragma once
#include<vector>
#include "HandTracker.hpp"
#include <string>

enum class Gesture
{
    NONE,
    LEFT_CLICK,
    CURSOR_MOVE,
    RIGHT_CLICK,
    DRAG,
    SCROLL
};

class GestureDetector
{
    public:
        Gesture detect(const std::vector<HandTracker::Landmark>&);
    private:
        bool isFingerUp(int tip, int pip, const std::vector<HandTracker::Landmark>& lm);
        bool isPinching(const HandTracker::Landmark& a, const HandTracker::Landmark& b);
};
std::string gestureToString(Gesture g);