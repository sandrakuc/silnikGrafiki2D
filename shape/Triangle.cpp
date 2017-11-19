#include "Triangle.h"
#include "LineSegment.h"

Triangle::Triangle()
{
    //ctor
}

Triangle::~Triangle()
{
    //dtor
}

void Triangle::draw(BITMAP* buffer, int red, int green, int blue)
{
    int col = Color::createIntColor(red, green, blue);
    this->draw(buffer, col);
}

void Triangle::draw(BITMAP* buffer, double red, double green, double blue)
{
    int col = Color::createIntColor(red, green, blue);
    this->draw(buffer, col);
}

void Triangle::draw(BITMAP* buffer, DefinedColor color)
{
    int col = Color::createIntColor(color);
    this->draw(buffer, col);
}

void Triangle::moveShape(int x, int y)
{
    this->movePoint(this->corner1, x, y);
    this->movePoint(this->corner2, x, y);
    this->movePoint(this->corner3, x, y);
}

void Triangle::rotateShape(Point2D point, double a)
{

}

void Triangle::zoom(Point2D point, int k)
{

}

void Triangle::draw(BITMAP* buffer, int color)
{
    LineSegment line1 = LineSegment();
    line1.setAB(this->corner1, this->corner2);
    line1.draw(buffer, color);

    LineSegment line2 = LineSegment();
    line2.setAB(this->corner2, this->corner3);
    line2.draw(buffer, color);

    LineSegment line3 = LineSegment();
    line3.setAB(this->corner3, this->corner1);
    line3.draw(buffer, color);


}
