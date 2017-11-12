#include <allegro.h>
#include <vector>
#include "Point2D.h"
#include "Engine.h"
#include "LineSegment.h"

void LineSegment::setPoints(int ax, int ay, int bx, int by){
    LineSegment::a.x = ax;
    LineSegment::a.y = ay;
    LineSegment::b.x = bx;
    LineSegment::b.y = by;
}

int LineSegment::getAx(){
    return LineSegment::a.x;
}

int LineSegment::getAy(){
    return LineSegment::a.y;
}

int LineSegment::getBx(){
    return LineSegment::b.x;
}

int LineSegment::getBy(){
    return LineSegment::b.y;
}
