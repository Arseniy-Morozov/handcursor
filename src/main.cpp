#include <iostream>
#include <opencv2/opencv.hpp>
#include "HandTracker.hpp"
#include "GestureDetector.hpp"
#include "Smoother.hpp"
#include "CursorController.hpp"

using namespace std;

HandTracker tracker;
GestureDetector detector;


CursorController cursor;

Smoother smoother;


int main() {
    if (!tracker.init()) return 1;
    if (!cursor.init()) return 1;

    cv::Mat frame;

    while (true) {
        if (tracker.processFrame(frame)) {
            Gesture g = detector.detect(tracker.getLandmarks());
            std::cout << gestureToString(g) << "\n";

            const auto& lm = tracker.getLandmarks();

            if (g == Gesture::CURSOR_MOVE) {
                auto [sx, sy] = smoother.smooth(lm[HandTracker::INDEX_TIP].x,
                                    lm[HandTracker::INDEX_TIP].y);
                cursor.moveCursor(sx, sy);
}
            if (g == Gesture::LEFT_CLICK) cursor.leftClick();
            if (g == Gesture::RIGHT_CLICK) cursor.rightClick();
        }
    }
    return 0;
}