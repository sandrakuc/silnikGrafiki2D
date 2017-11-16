#ifndef LINESEGMENT_H
#define LINESEGMENT_H
#include <allegro.h>
#include "Point2D.h"


class LineSegment
{
    public:
        LineSegment();
        virtual ~LineSegment();
        Point2D a, b;
        void setAB(Point2D p1, Point2D p2);
        int getAX();
        int getAY();
        int getBX();
        int getBY();
        void drawLine(BITMAP *buffer, int red, int green, int blue);
    protected:

    private:
};

#endif // LINESEGMENT_H
