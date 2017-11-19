#ifndef CIRCLE_H
#define CIRCLE_H

#include <allegro.h>
#include "../helper/Color.h"
#include "Shape.h"
class Circle: public Shape
{
    public:
        Circle();
        Circle(Point2D point2D);
        virtual ~Circle();
        Point2D center;
        int radious;

        void draw(BITMAP *buffer, int red, int green, int blue);
        void draw(BITMAP *buffer, double red, double green, double blue);
        void draw(BITMAP *buffer, DefinedColor color);

        void draw4(BITMAP *buffer, int red, int green, int blue);
        void draw4(BITMAP *buffer, double red, double green, double blue);
        void draw4(BITMAP *buffer, DefinedColor color);
        void draw8(BITMAP *buffer, int red, int green, int blue);
        void draw8(BITMAP *buffer, double red, double green, double blue);
        void draw8(BITMAP *buffer, DefinedColor color);

        void moveShape(int x, int y);
        void rotateShape(Point2D point, double a);
        void zoom(Point2D point, int k);

    protected:
        void updateBoundingBox();
    private:
        void draw4(BITMAP *buffer, int color);
        void draw8(BITMAP *buffer, int color);
};

#endif // CIRCLE_H
