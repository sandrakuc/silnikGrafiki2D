#include "Viewport.h"
#include "Point2D.h"
#include "LineSegment.h"

enum colors{RED = 1, ORANGE = 2, YELLOW = 3, GREEN = 4, CYAN = 5, BLUE = 6, VIOLET = 7, WHITE = 8};

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

void Viewport::clippingRectangle(BITMAP *buffer){
for(int i=0; i<4; i++){
    walls[i].drawLine(buffer, WHITE);
}
}

void Viewport::Triangle(BITMAP *buffer, Point2D p1, Point2D p2, Point2D p3, int red, int green, int blue){
    walls[0].setAB(p1, p2);
    walls[1].setAB(p2, p3);
    walls[2].setAB(p3, p1);
    for(int i=0; i<3; i++){
        walls[i].drawLine(buffer, red, green, blue);
    }
}

void Viewport::Triangle(BITMAP *buffer, Point2D p1, Point2D p2, Point2D p3, double red, double green, double blue){
    walls[0].setAB(p1, p2);
    walls[1].setAB(p2, p3);
    walls[2].setAB(p3, p1);
    for(int i=0; i<3; i++){
        walls[i].drawLine(buffer, red, green, blue);
    }
}

void Viewport::Triangle(BITMAP *buffer, Point2D p1, Point2D p2, Point2D p3, int color){
    walls[0].setAB(p1, p2);
    walls[1].setAB(p2, p3);
    walls[2].setAB(p3, p1);
    for(int i=0; i<3; i++){
        walls[i].drawLine(buffer, color);
    }
}
