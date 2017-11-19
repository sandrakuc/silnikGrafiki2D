#ifndef VIEWPORT_H
#define VIEWPORT_H
#include "Point2D.h"
#include "shape/LineSegment.h"


class Viewport
{
    public:
        Point2D a, b, c, d;
        LineSegment walls[4];
        vector <LineSegment> lines;
        Viewport();
        virtual ~Viewport();
        void setVertices(Point2D p1, Point2D p2, Point2D p3, Point2D p4);
        Point2D getA();
        Point2D getB();
        Point2D getC();
        Point2D getD();
        void clippingRectangle(BITMAP *buffer);
        void cutLine(BITMAP *buffer, LineSegment line);
    protected:

    private:
};

#endif // VIEWPORT_H
