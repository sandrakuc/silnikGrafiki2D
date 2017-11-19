#ifndef PIXEL_H
#define PIXEL_H

#include <allegro.h>
#include "../helper/Color.h"
#include "Shape.h"

class Pixel : public Shape
{
    public:
        Pixel();
        virtual ~Pixel();

        Point2D point;

        void draw(BITMAP *buffer, int red, int green, int blue);
        void draw(BITMAP *buffer, double red, double green, double blue);
        void draw(BITMAP *buffer, DefinedColor color);

        void moveShape(int x, int y);
        void rotateShape(Point2D point, double a);
        void zoom(Point2D point, int k);

    protected:
        void draw(BITMAP *buffer, int color);

    private:
};

#endif // PIXEL_H
