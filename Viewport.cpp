#include <vector>
#include <allegro.h>
#include "Viewport.h"
#include "Point2D.h"
#include "shape/LineSegment.h"

using namespace std;

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

void Viewport::cutLine(BITMAP *buffer, LineSegment line){
    int tabZero[] = {0, 0, 0, 0};
    Point2D pp, p1, p2;
    p1 = line.a;
    p2 = line.b;
    if(p1.y <= a.y)
        p1.b[0] = 1;
    if(p1.y >= c.y)
        p1.b[1] = 1;
    if(p1.x >= c.x)
        p1.b[2] = 1;
    if(p1.x <= a.x)
        p1.b[3] = 1;
    if(p2.y <= a.y)
        p2.b[0] = 1;
    if(p2.y >= c.y)
        p2.b[1] = 1;
    if(p2.x >= c.x)
        p2.b[2] = 1;
    if(p2.x <= a.x)
        p2.b[3] = 1;

    int andTab[4] = {p1.b[0] & p2.b[0], p1.b[1] & p2.b[1], p1.b[2] & p2.b[2], p1.b[3] & p2.b[3]};

    if(memcmp(p1.b, tabZero, sizeof(p1.b))==0 && memcmp(p2.b, tabZero, sizeof(p2.b))){
        line.drawLine(buffer, GREEN);
        return;
    }else{
        if(memcmp(andTab, tabZero, sizeof(andTab))!= 0){
            line.drawLine(buffer, RED);
            return;
        }
        else{
            if(memcmp(p1.b, tabZero, sizeof(p1.b))==0){
                int tmp[4];
                memcpy(tmp, p1.b, sizeof(p1.b));
                memcpy(p1.b, p2.b, sizeof(p2.b));
                memcpy(p2.b, tmp, sizeof(tmp));

                int tmp1 = p1.x;
                p1.x = p2.x;
                p2.x = tmp1;
                int tmp2 = p1.y;
                p1.y = p2.y;
                p2.y = tmp2;
            }
            if(p1.b[0] == 1){
                pp.x = p1.x + ((a.y - p1.y)*(p2.x - p1.x)/(p2.y - p1.y));
                pp.y = a.y;
                LineSegment l;
                l.setAB(pp, p1);
                l.drawLine(buffer, RED);
            }
            if(p1.b[1] == 1){
                pp.x = p1.x + ((c.y - p1.y)*(p2.x - p1.x)/(p2.y - p1.y));
                pp.y = c.y;
                LineSegment l;
                l.setAB(pp, p1);
                l.drawLine(buffer, RED);

            }
            if(p1.b[2] == 1){
                pp.y = p1.y + ((c.x - p1.x)*(p2.y - p1.y)/(p2.x - p1.x));
                pp.x = c.x;
                LineSegment l;
                l.setAB(pp, p1);
                l.drawLine(buffer, RED);
            }
            if(p1.b[3] == 1){
                pp.y = p1.y + ((a.x - p1.x)*(p2.y - p1.y)/(p2.x - p1.x));
                pp.x = a.x;
                LineSegment l;
                l.setAB(pp, p1);
                l.drawLine(buffer, RED);

            }



        }
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
