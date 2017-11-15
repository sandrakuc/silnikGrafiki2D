#include <allegro.h>
#include <vector>
#include <iostream>
#include "Engine.h"
#include "Point2D.h"

using namespace std;


void Point2D::setXY(int x, int y){
    Point2D::x = x;
    Point2D::y = y;
};
