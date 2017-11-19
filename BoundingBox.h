#ifndef BOUNDINGBOX_H
#define BOUNDINGBOX_H

#include <allegro.h>
#include "Point2D.h"
#include "../helper/Color.h"


class BoundingBox
{
    public:
        BoundingBox();
        virtual ~BoundingBox();
        Point2D corner1;
        Point2D corner2;
        void setX1(int x);
        void setY1(int y);
        void setX2(int x);
        void setY2(int y);

        void draw(BITMAP *buffer, int red, int green, int blue);
        void draw(BITMAP *buffer, double red, double green, double blue);
        void draw(BITMAP *buffer, DefinedColor color);

        void reset();

        bool isCollision(BoundingBox boundingBox);
        void addEdgeShapePoint(Point2D point);
    protected:
        int minX;
        int maxX;
        int minY;
        int maxY;

        void draw(BITMAP *buffer, int color);


    private:
};

#endif // BOUNDINGBOX_H
