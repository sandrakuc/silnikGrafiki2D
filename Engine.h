#ifndef ENGINE_H
#define ENGINE_H
#include <vector>
#include <allegro.h>
#include "Point2D.h"
#include "LineSegment.h"
#include "helper/Color.h"
#include "Filler.h"

using namespace std;

class Engine
{
    public:
        int w, h;
        Filler filler;
        Engine();
        virtual ~Engine();
        BITMAP *initiall(BITMAP *buffer);
        BITMAP *initiall(int mode, BITMAP *buffer);
        static Engine *getInstance();
        int errMsg();
        void mainLoop(Engine *engine, BITMAP *buffer);
        void tomekTest(BITMAP *buffer);
        void sandraTest(BITMAP *buffer);
        void drawGroupOfPoints(vector<Point2D> points, BITMAP *buffer, DefinedColor color);
        void drawGroupOfPoints(vector<Point2D> points, BITMAP *buffer, int r, int g, int b);
        void drawGroupOfPoints(vector<Point2D> points, BITMAP *buffer, double r, double g, double b);
    protected:

    private:
        static Engine *single;

};


#endif // ENGINE_H_INCLUDED

