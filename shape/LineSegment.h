#ifndef LINESEGMENT_H
#define LINESEGMENT_H
#include <vector>
#include <allegro.h>
#include "Point2D.h"
#include "Shape.h"

using namespace std;

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
        void drawLine(BITMAP *buffer, int red, int green, int blue); //wprowadzic poprawki
        void drawLine(BITMAP *buffer, double red, double green, double blue); //wprowadzic poprawki
        void drawLine(BITMAP *buffer, int color); //wprowadzic poprawki
        void drawLine(BITMAP *buffer, Point2D p1, Point2D p2, int red, int green, int blue); //wprowadzic poprawki
        void drawLine(BITMAP *buffer, Point2D p1, Point2D p2, double red, double green, double blue); //wprowadzic poprawki
        void drawLine(BITMAP *buffer, Point2D p1, Point2D p2, int color); //wprowadzic poprawki
        void polyline(BITMAP *buffer, vector<LineSegment> lines, int red, int green, int blue);
        void polyline(BITMAP *buffer, vector<LineSegment> lines, double red, double green, double blue);
        void polyline(BITMAP *buffer, vector<LineSegment> lines, int color);


        void draw(BITMAP *buffer, int red, int green, int blue);
        void draw(BITMAP *buffer, double red, double green, double blue);
        void draw(DefinedColor color);

        void moveShape(int x, int y);
        void rotateShape(Point2D point, double a);
        void zoom(Point2D point, int k);

    protected:

    private:
};

#endif // LINESEGMENT_H
