#ifndef MOUSE_H
#define MOUSE_H
#include <Point2D.h>

class Mouse
{
    public:
        Mouse();
        virtual ~Mouse();
        int getX();
        int getY();
        Point2D getPoint();
        bool leftButtonIsDown();
        bool rightButtonIsDown();
    protected:

    private:
};

#endif // MOUSE_H
