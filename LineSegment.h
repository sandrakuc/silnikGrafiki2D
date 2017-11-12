#ifndef LINESEGMENT_H_INCLUDED
#define LINESEGMENT_H_INCLUDED
#include "Point2D.h"

using namespace std;

class LineSegment{
public:
Point2D a, b;
void setPoints(int ax, int ay, int bx, int by);
int getAx();
int getAy();
int getBx();
int getBy();
protected:

private:

};

#endif // LINESEGMENT_H_INCLUDED
