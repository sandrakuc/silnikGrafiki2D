#include <vector>
#include <allegro.h>
#include "Viewport.h"
#include "Point2D.h"
#include "LineSegment.h"

using namespace std;

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

vector <LineSegment> Viewport::cutLine(BITMAP *buffer, LineSegment line){
    int tab[] = {0, 0, 0, 0};
    Point2D pp, p1, p2;
    p1 = line.a;
    p2 = line.b;
    if(p1.y <= a.y)
        p1.b[0] = 1;
    else
        p1.b[0] = 0;
    if(p1.y >= c.y)
        p1.b[1] = 1;
    else
        p1.b[1] = 0;
    if(p1.x >= c.x)
        p1.b[2] = 1;
    else
        p1.b[2] = 0;
    if(p1.x <= a.x)
        p1.b[3] = 1;
    else
        p1.b[3] = 0;
    if(p2.y <= a.y)
        p2.b[0] = 1;
    else
        p2.b[0] = 0;
    if(p2.y >= c.y)
        p2.b[1] = 1;
    else
        p2.b[1] = 0;
    if(p2.x >= c.x)
        p2.b[2] = 1;
    else
        p2.b[2] = 0;
    if(p2.x <= a.x)
        p2.b[3] = 1;
    else
        p2.b[3] = 0;
    if(p1.b[0] == p2.b[0] == p1.b[1] == p2.b[1] == p1.b[2] == p2.b[2] == p1.b[3] == p2.b[3] == 0 ){
        line.drawLine(buffer, GREEN);
        lines.push_back(line);
        return lines;
    }
    if((p1.b[0] != 0 || p1.b[1]!=0 || p1.b[2]!=0 || p1.b[3]) && (p2.b[0]!=0 || p2.b[1]!=0||p2.b[2]!=0||p2.b[3]!=0)){
        line.drawLine(buffer, RED);
        lines.push_back(line);
        return lines;
    }
    else{
        if(p1.b[0]==p1.b[1]==p1.b[2]==p1.b[3]==0){
            Point2D tmp = p1;
            p1 = p2;
            p2 = tmp;
        }
        if(p1.b[0] == 1){
            pp.x = p1.x + ((a.y - p1.y)*(p2.x - p1.x)/(p2.y - p1.y));
            pp.y = a.y;
            p1 = pp;
            LineSegment l1, l2;
            l1.setAB(p1, pp);
            l2.setAB(pp, p2);
            lines.push_back(l1);
            lines.push_back(l2);
            return cutLine(buffer, l1);
        }
        if(p1.b[1] == 1){
            pp.x = p1.x + ((c.y - p1.y)*(p2.x - p1.x)/(p2.y - p1.y));
            pp.y = c.y;
            p1 = pp;
            LineSegment l1, l2;
            l1.setAB(p1, pp);
            l2.setAB(pp, p2);
            lines.push_back(l1);
            lines.push_back(l2);
            return cutLine(buffer, l1);
        }
        if(p1.b[2] == 1){
            pp.y = p1.y + ((c.x - p1.x)*(p2.y - p1.y)/(p2.x - p1.x));
            pp.x = c.x;
            p1 = pp;
            LineSegment l1, l2;
            l1.setAB(p1, pp);
            l2.setAB(pp, p2);
            lines.push_back(l1);
            lines.push_back(l2);
            return cutLine(buffer, l1);
        }
        if(p1.b[3] == 1){
            pp.y = p1.y + ((a.x - p1.x)*(p2.y - p1.y)/(p2.x - p1.x));
            pp.x = a.x;
            p1 = pp;
            LineSegment l1, l2;
            l1.setAB(p1, pp);
            l2.setAB(pp, p2);
            lines.push_back(l1);
            lines.push_back(l2);
            return cutLine(buffer, l1);
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
