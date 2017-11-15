#include <allegro.h>
#include <vector>
#include <iostream>
#include "Engine.h"
#include "Point2D.h"
#include "LineSegment.h"

using namespace std;

Point2D::Point2D(){

}

void Point2D::setXY(int x, int y){
    Point2D::x = x;
    Point2D::y = y;
}
