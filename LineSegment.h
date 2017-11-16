#ifndef LINESEGMENT_H
#define LINESEGMENT_H
#include "Point2D.h"


class LineSegment
{
    public:
        LineSegment();
        virtual ~LineSegment();
        Point2D a, b;
        void funkcja();
    protected:

    private:
};

#endif // LINESEGMENT_H
