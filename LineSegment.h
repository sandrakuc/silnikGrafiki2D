#ifndef LINESEGMENT_H
#define LINESEGMENT_H
#include "Point2D.h"
#include "Engine.h"
#include <allegro.h>
#include <vector>
#include <iostream>


using namespace std;

class LineSegment{
public:
Point2D a, b;
void setPoints(int ax, int ay, int bx, int by);
int getAx();
int getAy();
int getBx();
int getBy();
void drawLine(BITMAP *buffer,int r, int b, int g);
void drawLine(BITMAP *buffer,double r, double b, double g);
void drawLine(BITMAP *buffer,int col);
protected:

private:

};

#endif // LINESEGMENT_H_INCLUDED
