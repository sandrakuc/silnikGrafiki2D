#ifndef SHAPEOBJECT_H
#define SHAPEOBJECT_H

#include <allegro.h>
#include "../Point2D.h"
#include "Shape.h"

class ShapeObject
{
    public:
        ShapeObject();
        virtual ~ShapeObject();
        void draw(BITMAP *buffer);
        void addShape(Shape& shape);
        void removeShape();
    protected:

    private:
};

#endif // SHAPEOBJECT_H
