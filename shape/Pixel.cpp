#include "Pixel.h"



Pixel::Pixel()
{
    //ctor
}

Pixel::~Pixel()
{
    //dtor
}

void Pixel::draw(BITMAP* buffer, int red, int green, int blue)
{
    int color = Color::createIntColor(red, green, blue);
    this->draw(buffer, color);
}

void Pixel::draw(BITMAP* buffer, double red, double green, double blue)
{
    int color = Color::createIntColor(red, green, blue);
    this->draw(buffer, color);
}

void Pixel::draw(BITMAP* buffer, DefinedColor color)
{
    int col = Color::createIntColor(color);
    this->draw(buffer, col);
}

void Pixel::moveShape(int x, int y)
{
    this->movePoint(this->point, x, y);
}

void Pixel::rotateShape(Point2D point, double a)
{

}

void Pixel::zoom(Point2D point, int k)
{

}

void Pixel::draw(BITMAP* buffer, int color)
{
    putpixel(buffer, this->point.x, this->point.y, color);
}

void Pixel::updateBoundingBox()
{
    this->boundingBox.reset();
    this->boundingBox.addEdgeShapePoint(this->point);
}

