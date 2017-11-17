#include "Viewport.h"
#include "Point2D.h"
#include "LineSegment.h"

Viewport::Viewport()
{
    //ctor
}

Viewport::~Viewport()
{
    //dtor
}

void Viewport::setVertices(Point2D p1, Point2D p2, Point2D p3, Point2D p4){
a = p1;
b = p2;
c = p3;
d = p4;
walls[0].setAB(a,b);
walls[1].setAB(b,c);
walls[2].setAB(c,d);
walls[3].setAB(d,a);
}

Point2D Viewport::getA(){
return a;
}

Point2D Viewport::getB(){
return b;
}

Point2D Viewport::getC(){
return c;
}

Point2D Viewport::getD(){
return d;
}
