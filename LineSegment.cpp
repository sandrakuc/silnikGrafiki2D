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
if(a.x <= b.x && a.y <= b.y){
    if(m <= 1.0 && dx !=0){
        float y = a.y;
        for(int x = a.x; x<=b.x; x++){
            putpixel(buffer, x, int(y), col);
            y+=m;
        }
    }
    if(m > 1.0 || dx == 0){
        m = dx/dy;
        float x = a.x;
        for(int y = a.y; y<=b.y; y++){
            putpixel(buffer, int(x), y, col);
            x+=m;
        }
    }
}
if(a.x <= b.x && a.y >= b.y){
    if(m <= 1.0 && dx != 0){
        float y = a.y;
        for(int x = a.x; x<=b.x; x++){
            putpixel(buffer, x, int(y), col);
            y-=m;
        }
    }
    if(m > 1.0 || dx == 0){
        m = dx/dy;
        float x = a.x;
        for(int y = a.y; y>=b.y; y--){
            putpixel(buffer, int(x), y, col);
            x+=m;
        }
    }
}
if(a.x >= b.x && a.y <= b.y){
    if(m <= 1.0 && dx != 0){
        float y = a.y;
        for(int x = a.x; x>=b.x; x--){
            putpixel(buffer, x, int(y), col);
            y+=m;
        }
    }
    if(m > 1.0 || dx == 0){
        m = dx/dy;
        float x = a.x;
        for(int y = a.y; y<=b.y; y++){
            putpixel(buffer, int(x), y, col);
            x-=m;
        }
    }
}
if(a.x >= b.x && a.y >= b.y){
    if(m <= 1.0 && dx != 0){
        float y = a.y;
        for(int x = a.x; x>=b.x; x--){
            putpixel(buffer, x, int(y), col);
            y-=m;
        }
    }
    if(m > 1.0 || dx ==0){
        m = dx/dy;
        float x = a.x;
        for(int y = a.y; y>=b.y; y--){
            putpixel(buffer, int(x), y, col);
            x-=m;
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
if(a.x <= b.x && a.y <= b.y){
    if(m <= 1.0 && dx !=0){
        float y = a.y;
        for(int x = a.x; x<=b.x; x++){
            putpixel(buffer, x, int(y), col);
            y+=m;
        }
    }
    if(m > 1.0 || dx == 0){
        m = dx/dy;
        float x = a.x;
        for(int y = a.y; y<=b.y; y++){
            putpixel(buffer, int(x), y, col);
            x+=m;
        }
    }
}
if(a.x <= b.x && a.y >= b.y){
    if(m <= 1.0 && dx != 0){
        float y = a.y;
        for(int x = a.x; x<=b.x; x++){
            putpixel(buffer, x, int(y), col);
            y-=m;
        }
    }
    if(m > 1.0 || dx == 0){
        m = dx/dy;
        float x = a.x;
        for(int y = a.y; y>=b.y; y--){
            putpixel(buffer, int(x), y, col);
            x+=m;
        }
    }
}
if(a.x >= b.x && a.y <= b.y){
    if(m <= 1.0 && dx != 0){
        float y = a.y;
        for(int x = a.x; x>=b.x; x--){
            putpixel(buffer, x, int(y), col);
            y+=m;
        }
    }
    if(m > 1.0 || dx == 0){
        m = dx/dy;
        float x = a.x;
        for(int y = a.y; y<=b.y; y++){
            putpixel(buffer, int(x), y, col);
            x-=m;
        }
    }
}
if(a.x >= b.x && a.y >= b.y){
    if(m <= 1.0 && dx != 0){
        float y = a.y;
        for(int x = a.x; x>=b.x; x--){
            putpixel(buffer, x, int(y), col);
            y-=m;
        }
    }
    if(m > 1.0 || dx ==0){
        m = dx/dy;
        float x = a.x;
        for(int y = a.y; y>=b.y; y--){
            putpixel(buffer, int(x), y, col);
            x-=m;
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
if(a.x <= b.x && a.y <= b.y){
    if(m <= 1.0 && dx !=0){
        float y = a.y;
        for(int x = a.x; x<=b.x; x++){
            putpixel(buffer, x, int(y), col);
            y+=m;
        }
    }
    if(m > 1.0 || dx == 0){
        m = dx/dy;
        float x = a.x;
        for(int y = a.y; y<=b.y; y++){
            putpixel(buffer, int(x), y, col);
            x+=m;
        }
    }
}
if(a.x <= b.x && a.y >= b.y){
    if(m <= 1.0 && dx != 0){
        float y = a.y;
        for(int x = a.x; x<=b.x; x++){
            putpixel(buffer, x, int(y), col);
            y-=m;
        }
    }
    if(m > 1.0 || dx == 0){
        m = dx/dy;
        float x = a.x;
        for(int y = a.y; y>=b.y; y--){
            putpixel(buffer, int(x), y, col);
            x+=m;
        }
    }
}
if(a.x >= b.x && a.y <= b.y){
    if(m <= 1.0 && dx != 0){
        float y = a.y;
        for(int x = a.x; x>=b.x; x--){
            putpixel(buffer, x, int(y), col);
            y+=m;
        }
    }
    if(m > 1.0 || dx == 0){
        m = dx/dy;
        float x = a.x;
        for(int y = a.y; y<=b.y; y++){
            putpixel(buffer, int(x), y, col);
            x-=m;
        }
    }
}
if(a.x >= b.x && a.y >= b.y){
    if(m <= 1.0 && dx != 0){
        float y = a.y;
        for(int x = a.x; x>=b.x; x--){
            putpixel(buffer, x, int(y), col);
            y-=m;
        }
    }
    if(m > 1.0 || dx ==0){
        m = dx/dy;
        float x = a.x;
        for(int y = a.y; y>=b.y; y--){
            putpixel(buffer, int(x), y, col);
            x-=m;
        }
    }
}
}

void LineSegment::drawLine(BITMAP *buffer, Point2D p1, Point2D p2, int red, int green, int blue){
int col = makecol(red, green, blue);
float dx = p2.x - p1.x;
if(dx < 0)
    dx = 0 - dx;
float dy = p2.y - p1.y;
if(dy < 0)
    dy = 0 - dy;
float m = dy/dx;
if(p1.x <= p2.x && p1.y <= p2.y){
    if(m <= 1.0 && dx != 0){
        float y = p1.y;
        for(int x = p1.x; x<=p2.x; x++){
            putpixel(buffer, x, int(y), col);
            y+=m;
        }
    }
    if(m > 1.0 || dx == 0){
        m = dx/dy;
        float x = p1.x;
        for(int y = p1.y; y<=p2.y; y++){
            putpixel(buffer, int(x), y, col);
            x+=m;
        }
    }
}
if(p1.x <= p2.x && p1.y >= p2.y){
    if(m <= 1.0 && dx != 0){
        float y = p1.y;
        for(int x = p1.x; x<=p2.x; x++){
            putpixel(buffer, x, int(y), col);
            y-=m;
        }
    }
    if(m > 1.0 || dx == 0){
        m = dx/dy;
        float x = p1.x;
        for(int y = p1.y; y>=p2.y; y--){
            putpixel(buffer, int(x), y, col);
            x+=m;
        }
    }
}
if(p1.x >= p2.x && p1.y <= p2.y){
    if(m <= 1.0 && dx != 0){
        float y = p1.y;
        for(int x = p1.x; x>=p2.x; x--){
            putpixel(buffer, x, int(y), col);
            y+=m;
        }
    }
    if(m > 1.0 || dx == 0){
        m = dx/dy;
        float x = p1.x;
        for(int y = p1.y; y<=p2.y; y++){
            putpixel(buffer, int(x), y, col);
            x-=m;
        }
    }
}
if(p1.x >= p2.x && p1.y >= p2.y){
    if(m <= 1.0 && dx != 0){
        float y = p1.y;
        for(int x = p1.x; x>=p2.x; x--){
            putpixel(buffer, x, int(y), col);
            y-=m;
        }
    }
    if(m > 1.0 || dx == 0){
        m = dx/dy;
        float x = p1.x;
        for(int y = p1.y; y>=p2.y; y--){
            putpixel(buffer, int(x), y, col);
            x-=m;
        }
    }
}
}

void LineSegment::drawLine(BITMAP *buffer, Point2D p1, Point2D p2, double red, double green, double blue){
int redi, greeni, bluei;
redi = (int)(255*red);
greeni = (int)(255*green);
bluei = (int)(255 * blue);
int col = makecol(redi, greeni, bluei);
float dx = p2.x - p1.x;
if(dx < 0)
    dx = 0 - dx;
float dy = p2.y - p1.y;
if(dy < 0)
    dy = 0 - dy;
float m = dy/dx;
if(p1.x <= p2.x && p1.y <= p2.y){
    if(m <= 1.0 && dx != 0){
        float y = p1.y;
        for(int x = p1.x; x<=p2.x; x++){
            putpixel(buffer, x, int(y), col);
            y+=m;
        }
    }
    if(m > 1.0 || dx == 0){
        m = dx/dy;
        float x = p1.x;
        for(int y = p1.y; y<=p2.y; y++){
            putpixel(buffer, int(x), y, col);
            x+=m;
        }
    }
}
if(p1.x <= p2.x && p1.y >= p2.y){
    if(m <= 1.0 && dx != 0){
        float y = p1.y;
        for(int x = p1.x; x<=p2.x; x++){
            putpixel(buffer, x, int(y), col);
            y-=m;
        }
    }
    if(m > 1.0 || dx == 0){
        m = dx/dy;
        float x = p1.x;
        for(int y = p1.y; y>=p2.y; y--){
            putpixel(buffer, int(x), y, col);
            x+=m;
        }
    }
}
if(p1.x >= p2.x && p1.y <= p2.y){
    if(m <= 1.0 && dx != 0){
        float y = p1.y;
        for(int x = p1.x; x>=p2.x; x--){
            putpixel(buffer, x, int(y), col);
            y+=m;
        }
    }
    if(m > 1.0 || dx == 0){
        m = dx/dy;
        float x = p1.x;
        for(int y = p1.y; y<=p2.y; y++){
            putpixel(buffer, int(x), y, col);
            x-=m;
        }
    }
}
if(p1.x >= p2.x && p1.y >= p2.y){
    if(m <= 1.0 && dx != 0){
        float y = p1.y;
        for(int x = p1.x; x>=p2.x; x--){
            putpixel(buffer, x, int(y), col);
            y-=m;
        }
    }
    if(m > 1.0 || dx == 0){
        m = dx/dy;
        float x = p1.x;
        for(int y = p1.y; y>=p2.y; y--){
            putpixel(buffer, int(x), y, col);
            x-=m;
        }
    }
}
}

void LineSegment::drawLine(BITMAP *buffer, Point2D p1, Point2D p2, int color){
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
float dx = p2.x - p1.x;
if(dx < 0)
    dx = 0 - dx;
float dy = p2.y - p1.y;
if(dy < 0)
    dy = 0 - dy;
float m = dy/dx;
if(p1.x <= p2.x && p1.y <= p2.y){
    if(m <= 1.0 && dx != 0){
        float y = p1.y;
        for(int x = p1.x; x<=p2.x; x++){
            putpixel(buffer, x, int(y), col);
            y+=m;
        }
    }
    if(m > 1.0 || dx == 0){
        m = dx/dy;
        float x = p1.x;
        for(int y = p1.y; y<=p2.y; y++){
            putpixel(buffer, int(x), y, col);
            x+=m;
        }
    }
}
if(p1.x <= p2.x && p1.y >= p2.y){
    if(m <= 1.0 && dx != 0){
        float y = p1.y;
        for(int x = p1.x; x<=p2.x; x++){
            putpixel(buffer, x, int(y), col);
            y-=m;
        }
    }
    if(m > 1.0 || dx == 0){
        m = dx/dy;
        float x = p1.x;
        for(int y = p1.y; y>=p2.y; y--){
            putpixel(buffer, int(x), y, col);
            x+=m;
        }
    }
}
if(p1.x >= p2.x && p1.y <= p2.y){
    if(m <= 1.0 && dx != 0){
        float y = p1.y;
        for(int x = p1.x; x>=p2.x; x--){
            putpixel(buffer, x, int(y), col);
            y+=m;
        }
    }
    if(m > 1.0 || dx == 0){
        m = dx/dy;
        float x = p1.x;
        for(int y = p1.y; y<=p2.y; y++){
            putpixel(buffer, int(x), y, col);
            x-=m;
        }
    }
}
if(p1.x >= p2.x && p1.y >= p2.y){
    if(m <= 1.0 && dx != 0){
        float y = p1.y;
        for(int x = p1.x; x>=p2.x; x--){
            putpixel(buffer, x, int(y), col);
            y-=m;
        }
    }
    if(m > 1.0 || dx == 0){
        m = dx/dy;
        float x = p1.x;
        for(int y = p1.y; y>=p2.y; y--){
            putpixel(buffer, int(x), y, col);
            x-=m;
        }
    }
}
}

void LineSegment::polyline(BITMAP *buffer, vector<LineSegment> lines, int red, int green, int blue){
    for(int i = 0; i<lines.size(); i++){
        drawLine(buffer, lines[i].a, lines[i].b, red, green, blue);
    }
}

void LineSegment::polyline(BITMAP *buffer, vector<LineSegment> lines, double red, double green, double blue){
    for(int i = 0; i<lines.size(); i++){
        drawLine(buffer, lines[i].a, lines[i].b, red, green, blue);
    }
}

void LineSegment::polyline(BITMAP *buffer, vector<LineSegment> lines, int color){
    for(int i = 0; i<lines.size(); i++){
        drawLine(buffer, lines[i].a, lines[i].b, color);
    }
}
