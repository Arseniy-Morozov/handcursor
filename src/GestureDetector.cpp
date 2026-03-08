#include "GestureDetector.hpp"
#include <cmath>


Gesture GestureDetector::detect(const std::vector<HandTracker::Landmark>& lm) {
    bool indexUp  = isFingerUp(HandTracker::INDEX_TIP, HandTracker::INDEX_PIP, lm);
    bool middleUp = isFingerUp(HandTracker::MIDDLE_TIP, HandTracker::MIDDLE_PIP, lm);
    bool ringUp = isFingerUp(HandTracker::RING_TIP, HandTracker::RING_PIP, lm);
    bool pinkyUp = isFingerUp(HandTracker::PINKY_TIP, HandTracker::PINKY_PIP, lm);
    bool indexPinch  = isPinching(lm[HandTracker::THUMB_TIP], lm[HandTracker::INDEX_TIP]);
    bool middlePinch = isPinching(lm[HandTracker::THUMB_TIP], lm[HandTracker::MIDDLE_TIP]);
    if (indexPinch) return Gesture::LEFT_CLICK;
    if (middlePinch) return Gesture::RIGHT_CLICK;
    if (!indexUp && !middleUp && !ringUp && !pinkyUp) return Gesture::DRAG;
    if (indexUp && middleUp && !ringUp && !pinkyUp)   return Gesture::SCROLL;
    if (indexUp && !middleUp && !ringUp && !pinkyUp)  return Gesture::CURSOR_MOVE;
    return Gesture::NONE;
}

bool GestureDetector::isFingerUp(int tip, int pip, const std::vector<HandTracker::Landmark>& lm) {
    return lm[tip].y < lm[pip].y;
}

bool GestureDetector::isPinching(const HandTracker::Landmark& a, const HandTracker::Landmark& b) {
    float dist = std::sqrt(pow((a.x - b.x), 2) + pow((a.y - b.y), 2) + pow((a.z - b.z), 2));
    return dist < 0.05f;
}
std::string gestureToString(Gesture g) {
    switch (g) {
        case Gesture::CURSOR_MOVE:  return "CURSOR_MOVE";
        case Gesture::LEFT_CLICK:   return "LEFT_CLICK";
        case Gesture::RIGHT_CLICK:  return "RIGHT_CLICK";
        case Gesture::DRAG:         return "DRAG";
        case Gesture::SCROLL:       return "SCROLL";
        default:                    return "NONE";
    }
}