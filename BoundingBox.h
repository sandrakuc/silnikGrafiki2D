#ifndef BOUNDINGBOX_H
#define BOUNDINGBOX_H

#include <allegro.h>
#include "Point2D.h"

class BoundingBox
{
    public:
        BoundingBox();
        virtual ~BoundingBox();
        Point2D leftTopCorner;
        Point2D rightBottomCorner;
        void setX1(int x);
        void setY1(int y);
        void setX2(int x);
        void setY2(int y);
        void draw(BITMAP *buffer);
        bool isCollision(BoundingBox boundingBox);
    protected:

    private:
};

#endif // BOUNDINGBOX_H
