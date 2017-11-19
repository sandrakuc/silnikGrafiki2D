#include "BoundingBox.h"

#include "shape/LineSegment.h"


BoundingBox::BoundingBox()
{
    //ctor
}

BoundingBox::~BoundingBox()
{
    //dtor
}

void BoundingBox::setX1(int x)
{
    this->corner1.x = x;
}

void BoundingBox::setY1(int y)
{
    this->corner1.y = y;
}

void BoundingBox::setX2(int x)
{
    this->corner2.x = x;
}

void BoundingBox::setY2(int y)
{
    this->corner2.y = y;
}

void BoundingBox::draw(BITMAP* buffer, int red, int green, int blue)
{
    int col = Color::createIntColor(red, green, blue);
    this->draw(buffer, col);
}

void BoundingBox::draw(BITMAP* buffer, double red, double green, double blue)
{
    int col = Color::createIntColor(red, green, blue);
    this->draw(buffer, col);
}

void BoundingBox::draw(BITMAP* buffer, DefinedColor color)
{
    int col = Color::createIntColor(color);
    this->draw(buffer, col);
}


void BoundingBox::draw(BITMAP* buffer, int color)
{
    Point2D topRightCorner = Point2D(this->corner2.x, this->corner1.y);
    Point2D bottomLeftCorner = Point2D(this->corner1.x, this->corner2.y);

    LineSegment line1 = LineSegment();
    line1.setAB(this->corner1, topRightCorner);
    line1.draw(buffer, color);

    LineSegment line2 = LineSegment();
    line2.setAB(topRightCorner, this->corner2);
    line2.draw(buffer, color);

    LineSegment line3 = LineSegment();
    line3.setAB(this->corner2, bottomLeftCorner);
    line3.draw(buffer, color);

    LineSegment line4 = LineSegment();
    line3.setAB(bottomLeftCorner, this->corner1);
    line3.draw(buffer, color);
}

void BoundingBox::addEdgeShapePoint(Point2D point)
{
    if(point.x < this->minX) {
        this->minX = point.x;
    }

    if(point.x > this->maxX) {
        this->maxX = point.x;
    }

    if(point.y < this->minY) {
        this->minY = point.y;
    }

    if(point.y > this->maxY) {
        this->maxY = point.y;
    }

    this->corner1.setXY(this->minX, this->minY);
    this->corner2.setXY(this->maxX, this->maxY);

}

void BoundingBox::reset()
{
        this->minX = 9999;
        this->maxX = 0;
        this->minY = 9999;
        this->maxY = 0;
        this->corner1.setXY(0,0);
        this->corner2.setXY(9999,9999);
}


bool BoundingBox::isCollision(BoundingBox boundingBox)
{




}
