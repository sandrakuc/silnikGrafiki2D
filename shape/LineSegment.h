#ifndef LINESEGMENT_H
#define LINESEGMENT_H
#include <vector>
#include <allegro.h>
#include "../Point2D.h"
#include "Shape.h"
#include "../helper/Color.h"


class LineSegment: public Shape
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

        void draw(BITMAP *buffer, int red, int green, int blue);
        void draw(BITMAP *buffer, double red, double green, double blue);
        void draw(BITMAP *buffer, DefinedColor color);

        void polyline(BITMAP *buffer, vector<LineSegment> lines, int red, int green, int blue);
        void polyline(BITMAP *buffer, vector<LineSegment> lines, double red, double green, double blue);
        void polyline(BITMAP *buffer, vector<LineSegment> lines, int color);




        void moveShape(int x, int y);
        void rotateShape(Point2D point, double a);
        void zoom(Point2D point, int k);

    protected:

    private:
        void drawLine(BITMAP *buffer,Point2D p1, Point2D p2, int color);
};

#endif // LINESEGMENT_H
