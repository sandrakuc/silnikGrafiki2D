#include <iostream>
#include "LineSegment.h"
#include "Point2D.h"

using namespace std;

LineSegment::LineSegment()
{
    //ctor
}

LineSegment::~LineSegment()
{
    //dtor
}

void LineSegment::setAB(Point2D p1, Point2D p2){
a = p1;
b = p2;
}

int LineSegment::getAX(){
return a.x;
}

int LineSegment::getAY(){
return a.y;
}

int LineSegment::getBX(){
return b.x;
}

int LineSegment::getBY(){
return b.y;
}
