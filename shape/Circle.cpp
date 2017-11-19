#include "Circle.h"

#include <allegro.h>
#include "Point2D.h"
#include "helper/Color.h"
#include <math.h>

#define M_PI		3.14159265358979323846
#define M_PI_2		1.57079632679489661923
#define M_PI_4		0.78539816339744830962

Circle::Circle()
{
    //ctor
}

Circle::Circle(Point2D point2D)
{
    this->center = point2D;
}

Circle::~Circle()
{
    //dtor
}

void Circle::draw(BITMAP* buffer, int red, int green, int blue)
{
    this->draw8(buffer, red, green, blue);
}

void Circle::draw(BITMAP* buffer, double red, double green, double blue)
{
    this->draw8(buffer, red, green, blue);
}

void Circle::draw(BITMAP* buffer, DefinedColor color)
{
    this->draw8(buffer, color);
}

void Circle::draw4(BITMAP *buffer, int red, int green, int blue)
{
    int color = Color::createIntColor(red, green, blue);
    this->draw4(buffer, color);
}

void Circle::draw4(BITMAP *buffer, double red, double green, double blue)
{
    int color = Color::createIntColor(red, green, blue);
    this->draw4(buffer, color);
}

void Circle::draw4(BITMAP *buffer, DefinedColor colorParam)
{
    int color = Color::createIntColor(colorParam);
    this->draw4(buffer, color);
}

void Circle::draw8(BITMAP *buffer, int red, int green, int blue)
{
    int color = Color::createIntColor(red, green, blue);
    this->draw8(buffer, color);
}

void Circle::draw8(BITMAP *buffer, double red, double green, double blue)
{
    int color = Color::createIntColor(red, green, blue);
    this->draw8(buffer, color);
}

void Circle::draw8(BITMAP *buffer, DefinedColor colorParam)
{
    int color = Color::createIntColor(colorParam);
    this->draw8(buffer, color);
}

void Circle::draw4(BITMAP *buffer, int color)
{
    int x, y;
    double i;
    for(i = 0; i <= M_PI_2; i = i+ (1.0/this->radious)){
        x = this->radious * cos(i);
        y = this->radious * sin(i);
        putpixel(buffer, this->center.x - x, this->center.y - y, color);
        putpixel(buffer, this->center.x + x, this->center.y - y, color);
        putpixel(buffer, this->center.x - x, this->center.y + y, color);
        putpixel(buffer, this->center.x + x, this->center.y + y, color);
    }

}

void Circle::draw8(BITMAP *buffer, int color)
{
    int x, y;
    double i;
    for(i = 0; i <= M_PI_4; i = i+ (1.0/this->radious)){
        x = this->radious * cos(i);
        y = this->radious * sin(i);
        putpixel(buffer, this->center.x + x, this->center.y + y, color);
        putpixel(buffer, this->center.x + y, this->center.y + x, color);
        putpixel(buffer, this->center.x - y, this->center.y + x, color);
        putpixel(buffer, this->center.x - x, this->center.y + y, color);
        putpixel(buffer, this->center.x - x, this->center.y - y, color);
        putpixel(buffer, this->center.x - y, this->center.y - x, color);
        putpixel(buffer, this->center.x + y, this->center.y - x, color);
        putpixel(buffer, this->center.x + x, this->center.y - y, color);
    }
}




void Circle::moveShape(int x, int y)
{
    this->movePoint(this->center, x, y);
}

void Circle::rotateShape(Point2D point, double a)
{

}

void Circle::zoom(Point2D point, int k)
{

}


