#pragma once
#include <X11/Xlib.h>
#include <X11/extensions/XTest.h>


class CursorController
{
    public:
        bool init();
        void moveCursor(float normX, float normY);
        void leftClick();
        void rightClick();
        void scroll(bool up);
        void beginDrag();
        void endDrag();
        bool isDragging() const {return dragging_;};


    private:
        Display* display_ = nullptr;
        Window root_ = 0;
        int screenW_ = 0;
        int screenH_ = 0;
        bool dragging_ = false;

};