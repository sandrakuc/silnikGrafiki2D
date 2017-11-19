#include "Shape.h"

Shape::Shape()
{
    this->boundingBox = BoundingBox();
}

Shape::~Shape()
{
    //dtor
}



void Shape::drawBoundingBox(BITMAP* buffer)
{

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
