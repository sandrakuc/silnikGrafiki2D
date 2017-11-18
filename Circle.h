#ifndef CIRCLE_H
#define CIRCLE_H

#include <allegro.h>
#include "Point2D.h"
#include "helper/Color.h"

class Circle
{
    public:
        Circle();
        Circle(Point2D point2D);
        virtual ~Circle();
        Point2D center;
        int radious;
        void draw4(BITMAP *buffer, int red, int green, int blue);
        void draw4(BITMAP *buffer, double red, double green, double blue);
        void draw4(BITMAP *buffer, DefinedColor color);
        void draw8(BITMAP *buffer, int red, int green, int blue);
        void draw8(BITMAP *buffer, double red, double green, double blue);
        void draw8(BITMAP *buffer, DefinedColor color);
    protected:

    private:
        void draw4(BITMAP *buffer, int color);
        void draw8(BITMAP *buffer, int color);
};

#endif // CIRCLE_H
