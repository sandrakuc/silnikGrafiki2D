#include "Filler.h"
#include <stack>

Filler::Filler()
{
    //ctor
}

Filler::~Filler()
{
    //dtor
}

void Filler::fillBackgroundRecursive(BITMAP* buffer, Point2D point, int red, int green, int blue)
{
    int color = Color::createIntColor(red, green, blue);
    int backgroundColor = getpixel(buffer, point.x, point.y);
    this->fillBackgroundRecursive(buffer, point, color, backgroundColor);
}

void Filler::fillBackgroundRecursive(BITMAP* buffer, Point2D point, double red, double green, double blue)
{
    int color = Color::createIntColor(red, green, blue);
    int backgroundColor = getpixel(buffer, point.x, point.y);
    this->fillBackgroundRecursive(buffer, point, color, backgroundColor);
}

void Filler::fillBackgroundRecursive(BITMAP* buffer, Point2D point, DefinedColor color)
{
    int colorInt = Color::createIntColor(color);
    int backgroundColor = getpixel(buffer, point.x, point.y);
    this->fillBackgroundRecursive(buffer, point, colorInt, backgroundColor);
}

void Filler::fillBackgroundIterative(BITMAP* buffer, Point2D point, int red, int green, int blue)
{
    int color = Color::createIntColor(red, green, blue);
    this->fillBackgroundIterative(buffer, point, color);
}

void Filler::fillBackgroundIterative(BITMAP* buffer, Point2D point, double red, double green, double blue)
{
    int color = Color::createIntColor(red, green, blue);
    this->fillBackgroundIterative(buffer, point, color);
}

void Filler::fillBackgroundIterative(BITMAP* buffer, Point2D point, DefinedColor color)
{
    int colorInt = Color::createIntColor(color);
    this->fillBackgroundIterative(buffer, point, colorInt);
}

void Filler::fillBackgroundRecursive(BITMAP* buffer, Point2D point, int colorToFill, int backgroundColor)
{
    int colorPixel = getpixel(buffer, point.x, point.y);
    if(colorPixel == colorToFill) {
        return;
    } else if(colorPixel == backgroundColor) {
        putpixel(buffer, point.x, point.y, colorToFill);

        Point2D n(point.x,point.y-1);
        Point2D e(point.x+1,point.y);
        Point2D s(point.x,point.y+1);
        Point2D w(point.x-1,point.y);

        this->fillBackgroundRecursive(buffer, n, colorToFill, backgroundColor);
        this->fillBackgroundRecursive(buffer, e, colorToFill, backgroundColor);
        this->fillBackgroundRecursive(buffer, s, colorToFill, backgroundColor);
        this->fillBackgroundRecursive(buffer, w, colorToFill, backgroundColor);
    }

}



void Filler::fillBackgroundIterative(BITMAP* buffer, Point2D point, int colorToFill)
{
    int backgroundColor = getpixel(buffer, point.x, point.y);

    std::stack <Point2D> pointStack;
    pointStack.push(point);

    while(pointStack.size() > 0){
        Point2D sPoint = pointStack.top();
        pointStack.pop();

        if(getpixel(buffer, sPoint.x, sPoint.y) == backgroundColor && getpixel(buffer, sPoint.x, sPoint.y) != colorToFill){
            putpixel(buffer, sPoint.x, sPoint.y, colorToFill);

            pointStack.push({sPoint.x - 1, sPoint.y});
            pointStack.push({sPoint.x + 1, sPoint.y});
            pointStack.push({sPoint.x, sPoint.y - 1});
            pointStack.push({sPoint.x, sPoint.y + 1});
        }
    }
}
