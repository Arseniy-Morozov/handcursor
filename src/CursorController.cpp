#include <iostream>
#include "CursorController.hpp"


bool CursorController::init()
{
    display_ = XOpenDisplay(nullptr);
    if (!display_) return false;

    root_ = DefaultRootWindow(display_);
    Screen* screen = DefaultScreenOfDisplay(display_);
    screenW_ = screen->width;
    screenH_ = screen->height;

    std::cout << "[CursorController] Screen: " << screenW_ << "x" << screenH_ << "\n";
    return true;
}

void CursorController::moveCursor(float normX, float normY)
{
    int x = static_cast<int>(normX * screenW_);
    int y = static_cast<int>(normY * screenH_);

        // Move cursor
    XWarpPointer(display_, None, root_, 0, 0, 0, 0, x, y);
    XFlush(display_);

    // Fake click (press then release)
    XTestFakeButtonEvent(display_, 1, True, 0);   // press
    XTestFakeButtonEvent(display_, 1, False, 0);  // release
    XFlush(display_);
}

