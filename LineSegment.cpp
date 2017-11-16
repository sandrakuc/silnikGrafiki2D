#include <iostream>
#include "LineSegment.h"
#include "Point2D.h"

using namespace std;

enum colors{RED = 1, ORANGE = 2, YELLOW = 3, GREEN = 4, CYAN = 5, BLUE = 6, VIOLET = 7, WHITE = 8};

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

void LineSegment::drawLine(BITMAP *buffer, int red, int green, int blue){
int col = makecol(red, green, blue);
float dx = b.x - a.x;
if(dx < 0)
    dx = 0 - dx;
float dy = b.y - a.y;
if(dy < 0)
    dy = 0 - dy;
float m = dy/dx;
if(a.x < b.x && a.y < b.y){
    if(m <= 1.0){
        float y = a.y;
        for(int x = a.x; x<=b.x; x++){
            putpixel(buffer, x, int(y+0.5), col);
            y+=m;
        }
    }
    if(m > 1.0){
        m = dx/dy;
        float x = a.x;
        for(int y = a.y; y<=b.y; y++){
            putpixel(buffer, int(x+0.5), y, col);
            x+=m;
        }
    }
}
if(a.x < b.x && a.y > b.y){
    if(m <= 1.0){
        float y = a.y;
        for(int x = a.x; x<=b.x; x++){
            putpixel(buffer, x, int(y+0.5), col);
            y-=m;
        }
    }
    if(m > 1.0){
        m = dx/dy;
        float x = a.x;
        for(int y = a.y; y>=b.y; y--){
            putpixel(buffer, int(x+0.5), y, col);
            x+=m;
        }
    }
}
if(a.x > b.x && a.y < b.y){
    Point2D tmp = a;
    a = b;
    b = tmp;
    if(m <= 1.0){
        float y = a.y;
        for(int x = a.x; x<=b.x; x++){
            putpixel(buffer, x, int(y+0.5), col);
            y+=m;
        }
    }
    if(m > 1.0){
        m = dx/dy;
        float x = a.x;
        for(int y = a.y; y<=b.y; y++){
            putpixel(buffer, int(x+0.5), y, col);
            x+=m;
        }
    }
}
if(a.x > b.x && a.y > b.y){
    Point2D tmp = a;
    a = b;
    b = tmp;
    if(m <= 1.0){
        float y = a.y;
        for(int x = a.x; x<=b.x; x++){
            putpixel(buffer, x, int(y+0.5), col);
            y-=m;
        }
    }
    if(m > 1.0){
        m = dx/dy;
        float x = a.x;
        for(int y = a.y; y>=b.y; y--){
            putpixel(buffer, int(x+0.5), y, col);
            x+=m;
        }
    }
}
}

void LineSegment::drawLine(BITMAP *buffer, double red, double green, double blue){
int redi, greeni, bluei;
redi = (int)(255*red);
greeni = (int)(255*green);
bluei = (int)(255 * blue);
int col = makecol(redi, greeni, bluei);
float dx = b.x - a.x;
if(dx < 0)
    dx = 0 - dx;
float dy = b.y - a.y;
if(dy < 0)
    dy = 0 - dy;
float m = dy/dx;
if(a.x < b.x && a.y < b.y){
    if(m <= 1.0){
        float y = a.y;
        for(int x = a.x; x<=b.x; x++){
            putpixel(buffer, x, int(y+0.5), col);
            y+=m;
        }
    }
    if(m > 1.0){
        m = dx/dy;
        float x = a.x;
        for(int y = a.y; y<=b.y; y++){
            putpixel(buffer, int(x+0.5), y, col);
            x+=m;
        }
    }
}
if(a.x < b.x && a.y > b.y){
    if(m <= 1.0){
        float y = a.y;
        for(int x = a.x; x<=b.x; x++){
            putpixel(buffer, x, int(y+0.5), col);
            y-=m;
        }
    }
    if(m > 1.0){
        m = dx/dy;
        float x = a.x;
        for(int y = a.y; y>=b.y; y--){
            putpixel(buffer, int(x+0.5), y, col);
            x+=m;
        }
    }
}
if(a.x > b.x && a.y < b.y){
    Point2D tmp = a;
    a = b;
    b = tmp;
    if(m <= 1.0){
        float y = a.y;
        for(int x = a.x; x<=b.x; x++){
            putpixel(buffer, x, int(y+0.5), col);
            y+=m;
        }
    }
    if(m > 1.0){
        m = dx/dy;
        float x = a.x;
        for(int y = a.y; y<=b.y; y++){
            putpixel(buffer, int(x+0.5), y, col);
            x+=m;
        }
    }
}
if(a.x > b.x && a.y > b.y){
    Point2D tmp = a;
    a = b;
    b = tmp;
    if(m <= 1.0){
        float y = a.y;
        for(int x = a.x; x<=b.x; x++){
            putpixel(buffer, x, int(y+0.5), col);
            y-=m;
        }
    }
    if(m > 1.0){
        m = dx/dy;
        float x = a.x;
        for(int y = a.y; y>=b.y; y--){
            putpixel(buffer, int(x+0.5), y, col);
            x+=m;
        }
    }
}
}

void LineSegment::drawLine(BITMAP *buffer, int color){
int col;
if(color == RED)
    col = makecol(255, 0, 0);
if(color == ORANGE)
    col = makecol(255, 127, 39);
if(color == YELLOW)
    col = makecol(255, 255, 0);
if(color == GREEN)
    col = makecol(0, 255, 0);
if(color == CYAN)
    col = makecol(0, 255, 255);
if(color == BLUE)
    col = makecol(0, 0, 255);
if(color == VIOLET)
    col = makecol(255, 0, 255);
if(color == WHITE)
    col = makecol(255, 255, 255);
float dx = b.x - a.x;
if(dx < 0)
    dx = 0 - dx;
float dy = b.y - a.y;
if(dy < 0)
    dy = 0 - dy;
float m = dy/dx;
if(a.x < b.x && a.y < b.y){
    if(m <= 1.0){
        float y = a.y;
        for(int x = a.x; x<=b.x; x++){
            putpixel(buffer, x, int(y+0.5), col);
            y+=m;
        }
    }
    if(m > 1.0){
        m = dx/dy;
        float x = a.x;
        for(int y = a.y; y<=b.y; y++){
            putpixel(buffer, int(x+0.5), y, col);
            x+=m;
        }
    }
}
if(a.x < b.x && a.y > b.y){
    if(m <= 1.0){
        float y = a.y;
        for(int x = a.x; x<=b.x; x++){
            putpixel(buffer, x, int(y+0.5), col);
            y-=m;
        }
    }
    if(m > 1.0){
        m = dx/dy;
        float x = a.x;
        for(int y = a.y; y>=b.y; y--){
            putpixel(buffer, int(x+0.5), y, col);
            x+=m;
        }
    }
}
if(a.x > b.x && a.y < b.y){
    Point2D tmp = a;
    a = b;
    b = tmp;
    if(m <= 1.0){
        float y = a.y;
        for(int x = a.x; x<=b.x; x++){
            putpixel(buffer, x, int(y+0.5), col);
            y+=m;
        }
    }
    if(m > 1.0){
        m = dx/dy;
        float x = a.x;
        for(int y = a.y; y<=b.y; y++){
            putpixel(buffer, int(x+0.5), y, col);
            x+=m;
        }
    }
}
if(a.x > b.x && a.y > b.y){
    Point2D tmp = a;
    a = b;
    b = tmp;
    if(m <= 1.0){
        float y = a.y;
        for(int x = a.x; x<=b.x; x++){
            putpixel(buffer, x, int(y+0.5), col);
            y-=m;
        }
    }
    if(m > 1.0){
        m = dx/dy;
        float x = a.x;
        for(int y = a.y; y>=b.y; y--){
            putpixel(buffer, int(x+0.5), y, col);
            x+=m;
        }
    }
}
}
