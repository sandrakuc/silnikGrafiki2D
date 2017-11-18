#include "Mouse.h"
#include <allegro.h>

Mouse::Mouse()
{
    //ctor
}

Mouse::~Mouse()
{
    //dtor
}


int Mouse::getX()
{
    return mouse_x;
}

int Mouse::getY()
{
    return mouse_y;
}

Point2D Mouse::getPoint()
{
    Point2D p(this->getX(), this->getY());
    return p;
}

bool Mouse::leftButtonIsDown()
{
    return (mouse_b & 1);
}

bool Mouse::rightButtonIsDown()
{
    return (mouse_b & 2);
}
