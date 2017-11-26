#ifndef SPRITEOBJECT_H
#define SPRITEOBJECT_H
#include <allegro.h>
#include <vector>
#include "BitmapHandler.h"

using namespace std;

class SpriteObject
{
    public:
        BitmapHandler bh;
        vector <BitmapHandler> bmps;
        SpriteObject(BitmapHandler bh);
        SpriteObject(vector <BitmapHandler> bmps);
        virtual ~SpriteObject();
        void rysuj(BITMAP *buffer, int x, int y);
        void addBmp(BitmapHandler bh);
        void dltBmp();
        void rdBmp(char* path);
        void rdBmp(vector <char *> paths);
        void translation();
    protected:

    private:
};

#endif // SPRITEOBJECT_H
