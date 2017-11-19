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
