#ifndef FILLER_H
#define FILLER_H

#include "Point2D.h"
#include <allegro.h>
#include "helper/Color.h"

class Filler
{
    public:
        Filler();
        virtual ~Filler();
        void fillBackgroundRecursive(BITMAP *buffer,Point2D point ,int red, int green, int blue);
        void fillBackgroundRecursive(BITMAP *buffer,Point2D point , double red, double green, double blue);
        void fillBackgroundRecursive(BITMAP *buffer,Point2D point , DefinedColor color);
        void fillBackgroundIterative(BITMAP *buffer,Point2D point , int red, int green, int blue);
        void fillBackgroundIterative(BITMAP *buffer,Point2D point , double red, double green, double blue);
        void fillBackgroundIterative(BITMAP *buffer,Point2D point , DefinedColor color);

    protected:

    private:
        void fillBackgroundRecursive(BITMAP *buffer,Point2D point, int colorToFill, int backgroundColor);
        void fillBackgroundIterative(BITMAP *buffer,Point2D point, int colorToFill);

};

#endif // FILLER_H
