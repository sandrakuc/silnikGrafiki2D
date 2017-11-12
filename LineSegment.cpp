#include <allegro.h>
#include <vector>
#include "Point2D.h"
#include "Engine.h"
#include "LineSegment.h"

using namespace std;

enum colors{RED = 1, ORANGE = 2, YELLOW = 3, GREEN = 4, CYAN = 5, BLUE = 6, VIOLET = 7, WHITE = 8};

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

void LineSegment::drawLine(int r, int g, int b){
float dx=LineSegment::b.x-LineSegment::a.x;
if(dx < 0)
    dx = 0 - dx;
float dy=LineSegment::b.y-LineSegment::a.y;
if(dy < 0)
    dy = 0 - dy;
float m=dy/dx;
if(m <= 1.0){
float y=LineSegment::a.y;
for(int x=x0; x<=x1; x++){
putpixel(screen, x, int(y+0.5), makeacol(r,g,b));
y+=m;
}
}
if(m > 1.0){
    m = dx/dy;
    float x=LineSegment::b.y;
    for(int y=y0; y<=y1; y++){
        putpixel(screen,int(x+0.5),y,makeacol(r,g,b));
        x+=m;
    }
}
}

void LineSegment::drawLine(double r, double g, double b){
int ri = (int)(r*255);
int gi = (int)(g*255);
int bi = (int)(b*255);
float dx=LineSegment::b.x-LineSegment::a.x;
if(dx < 0)
    dx = 0 - dx;
float dy=LineSegment::b.y-LineSegment::a.y;
if(dy < 0)
    dy = 0 - dy;
float m=dy/dx;
if(m <= 1.0){
float y=LineSegment::a.y;
for(int x=x0; x<=x1; x++){
putpixel(screen, x, int(y+0.5), makeacol(ri,gi,bi));
y+=m;
}
}
if(m > 1.0){
    m = dx/dy;
    float x=LineSegment::b.y;
    for(int y=y0; y<=y1; y++){
        putpixel(screen,int(x+0.5),y,makeacol(ri,gi,bi));
        x+=m;
    }
}
}

void LineSegment::drawLine(int col){
int color;
if(col == RED){
        color = makecol(255,0,0);
    }
    if(col == ORANGE){
        color = makecol(255,127,39);
    }
    if(col == YELLOW){
        color = makecol(255,255,0);
    }
    if(col == GREEN){
        color = makecol(0,255,0);
    }
    if(col == CYAN){
        color = makecol(0,255,255);
    }
    if(col == BLUE){
        color = makecol(0,0,255);
    }
    if(col == VIOLET){
        color = makecol(255,0,255);
    }
    if(col == WHITE){
        color = makecol(255,255,255);
    }
float dx=LineSegment::b.x-LineSegment::a.x;
if(dx < 0)
    dx = 0 - dx;
float dy=LineSegment::b.y-LineSegment::a.y;
if(dy < 0)
    dy = 0 - dy;
float m=dy/dx;
if(m <= 1.0){
float y=LineSegment::a.y;
for(int x=x0; x<=x1; x++){
putpixel(screen, x, int(y+0.5), color);
y+=m;
}
}
if(m > 1.0){
    m = dx/dy;
    float x=LineSegment::b.y;
    for(int y=y0; y<=y1; y++){
        putpixel(screen,int(x+0.5),y,color);
        x+=m;
    }
}
}
