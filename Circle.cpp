#include "Circle.h"

#include <allegro.h>
#include "Point2D.h"
#include "helper/Color.h"
#include <math.h>

Circle::Circle()
{
    //ctor
}

Circle::Circle(Point2D point2D)
{
    //ctor
}

Circle::~Circle()
{
    //dtor
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


