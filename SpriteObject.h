#ifndef SPRITEOBJECT_H
#define SPRITEOBJECT_H
#include <allegro.h>
#include "BitmapHandler.h"


class SpriteObject
{
    public:
        BitmapHandler bh;
        SpriteObject(BitmapHandler bh);
        virtual ~SpriteObject();

    protected:

    private:
};

#endif // SPRITEOBJECT_H
