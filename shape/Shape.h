#ifndef SHAPE_H
#define SHAPE_H

#include <allegro.h>
#include "../Point2D.h"
#include "../BoundingBox.h"

class Shape
{
    public:
        Shape();
        virtual ~Shape();
        virtual void draw(BITMAP *buffer) =0;

        virtual void drawBoundingBox(BITMAP *buffer);
        BoundingBox getBoundingBox();
        bool isCollision(Shape &shape);

        virtual void moveShape(int x, int y) = 0;
        virtual void rotateShape(Point2D point, double a) = 0;
        virtual void zoom(Point2D point, int k) = 0;
    protected:

    private:
        BoundingBox boundingBox;
};

#endif // SHAPE_H
