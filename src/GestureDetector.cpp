#include "GestureDetector.hpp"
#include <cmath>


Gesture GestureDetector::detect(const std::vector<HandTracker::Landmark>& lm) {
    return Gesture::NONE;
}

bool GestureDetector::isFingerUp(int tip, int pip, const std::vector<HandTracker::Landmark>& lm) {
    return false;
}

bool GestureDetector::isPinching(const HandTracker::Landmark& a, const HandTracker::Landmark& b) {
    return false;
}