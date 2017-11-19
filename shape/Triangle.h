#ifndef TRIANGLE_H
#define TRIANGLE_H

#include "../helper/Color.h"
#include "Shape.h"

class Triangle : public Shape
{
    public:
        Triangle();
        virtual ~Triangle();

        Point2D corner1;
        Point2D corner2;
        Point2D corner3;

        void draw(BITMAP *buffer, int red, int green, int blue);
        void draw(BITMAP *buffer, double red, double green, double blue);
        void draw(BITMAP *buffer, DefinedColor color);

        void moveShape(int x, int y);
        void rotateShape(Point2D point, double a);
        void zoom(Point2D point, int k);

    protected:
        void draw(BITMAP *buffer, int color);
        void updateBoundingBox();
    private:
};

#endif // TRIANGLE_H
