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

    
    
}


void CursorController::leftClick()
{
    XTestFakeButtonEvent(display_, 1, True, 0);   // press
    XTestFakeButtonEvent(display_, 1, False, 0);  // release
    XFlush(display_);
}
void CursorController::rightClick()
{
    XTestFakeButtonEvent(display_, 3, True, 0);   // press
    XTestFakeButtonEvent(display_, 3, False, 0);  // release
    XFlush(display_);
}
void CursorController::scroll(bool up)
{
    int btn = up ? 4 : 5;
    XTestFakeButtonEvent(display_, btn, True, 0);   // press
    XTestFakeButtonEvent(display_, btn, False, 0);  // release
    XFlush(display_);
}
void CursorController::beginDrag()
{
    if (!dragging_) {
    XTestFakeButtonEvent(display_, 1, True, 0);
    dragging_ = true;
}
}
void CursorController::endDrag()
{
    if (dragging_) {
    XTestFakeButtonEvent(display_, 1, False, 0);
    dragging_ = false;
}
}
