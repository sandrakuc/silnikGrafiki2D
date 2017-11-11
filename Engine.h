#ifndef ENGINE_H_INCLUDED
#define ENGINE_H_INCLUDED
#include <vector>
#include "Point2D.h"

using namespace std;

class Engine
{
    public:
        int w, h;
        Engine();
        virtual ~Engine();
        BITMAP *initiall(BITMAP *buffer);
        BITMAP *initiall(int mode, BITMAP *buffer);
        static Engine *getInstance();
        int errMsg();
        void blockingKeyboardUsing(BITMAP *buffer);
        void nonBlockingKeyboardUsing();
        void mainLoop(Engine *engine, BITMAP *buffer);
        void drawGroupOfPoints(vector<Point2D> points, BITMAP *buffer, int r, int g, int b);
        void drawGroupOfPoints(vector<Point2D> points, BITMAP *buffer, double r, double g, double b);
    protected:

    private:
        static Engine *single;

};


#endif // ENGINE_H_INCLUDED
