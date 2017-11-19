#include <iostream>
#include "LineSegment.h"
#include "../Point2D.h"
#include "../helper/Color.h"

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

void LineSegment::draw(BITMAP *buffer, int red, int green, int blue){
    int col = Color::createIntColor(red, green, blue);
    this->drawLine(buffer, this->a, this->b, col);
}

void LineSegment::draw(BITMAP *buffer, double red, double green, double blue){
    int col = Color::createIntColor(red, green, blue);
    this->drawLine(buffer, this->a, this->b, col);
}

void LineSegment::draw(BITMAP *buffer, DefinedColor color){
    int col = Color::createIntColor(color);
    this->drawLine(buffer, this->a, this->b, col);
}

void LineSegment::draw(BITMAP* buffer, int color)
{
    this->drawLine(buffer, this->a, this->b, color);
}


void LineSegment::polyline(BITMAP *buffer, vector<LineSegment> lines, int red, int green, int blue){
    for(int i = 0; i<lines.size(); i++){
        int col = Color::createIntColor(red, green, blue);
        drawLine(buffer, lines[i].a, lines[i].b, col);
    }
}

void LineSegment::polyline(BITMAP *buffer, vector<LineSegment> lines, double red, double green, double blue){
    for(int i = 0; i<lines.size(); i++){
        int col = Color::createIntColor(red, green, blue);
        drawLine(buffer, lines[i].a, lines[i].b, col);
    }
}

void LineSegment::polyline(BITMAP *buffer, vector<LineSegment> lines, int color){
    for(int i = 0; i<lines.size(); i++){
        drawLine(buffer, lines[i].a, lines[i].b, color);
    }
}

void LineSegment::moveShape(int x, int y)
{
    this->movePoint(this->a, x, y);
    this->movePoint(this->b, x, y);
}

void LineSegment::rotateShape(Point2D point, double a)
{

}

void LineSegment::zoom(Point2D point, int k)
{

}


void LineSegment::drawLine(BITMAP *buffer, Point2D p1, Point2D p2,  int col){
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


