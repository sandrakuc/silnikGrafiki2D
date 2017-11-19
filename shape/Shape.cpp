#include "Shape.h"

Shape::Shape()
{
    this->boundingBox = BoundingBox();
}

Shape::~Shape()
{
    //dtor
}

void Shape::drawBoundingBox(BITMAP* buffer, int red, int green, int blue)
{
    this->updateBoundingBox();
    this->boundingBox.draw(buffer, red, green, blue);
}

void Shape::drawBoundingBox(BITMAP* buffer, double red, double green, double blue)
{
    this->updateBoundingBox();
    this->boundingBox.draw(buffer, red, green, blue);
}

void Shape::drawBoundingBox(BITMAP* buffer, DefinedColor color)
{
    this->updateBoundingBox();
    this->boundingBox.draw(buffer, color);
}



BoundingBox Shape::getBoundingBox()
{

}

bool Shape::isCollision(Shape& shape)
{

}

void Shape::movePoint(Point2D &point, int x, int y)
{
    point.x = point.x+x;
    point.y = point.y+y;
}
