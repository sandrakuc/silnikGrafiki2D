#ifndef SHAPE_H
#define SHAPE_H

#include <allegro.h>
#include "../Point2D.h"
#include "../BoundingBox.h"
#include "../helper/Color.h"
class Shape
{
    public:
        Shape();
        virtual ~Shape();
        virtual void draw(BITMAP *buffer, int red, int green, int blue) =0;
        virtual void draw(BITMAP *buffer, double red, double green, double blue) =0;
        virtual void draw(BITMAP *buffer, DefinedColor color) =0;

        void drawBoundingBox(BITMAP *buffer);
        BoundingBox getBoundingBox();
        bool isCollision(Shape &shape);

        virtual void moveShape(int x, int y) = 0;
        virtual void rotateShape(Point2D point, double a) = 0;
        virtual void zoom(Point2D point, int k) = 0;
    protected:
        void movePoint(Point2D &point, int x, int y);
        BoundingBox boundingBox;

    private:


};

#endif // SHAPE_H
