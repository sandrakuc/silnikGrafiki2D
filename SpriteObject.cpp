#include "SpriteObject.h"
#include "BitmapHandler.h"
#include <allegro.h>

SpriteObject::SpriteObject(BitmapHandler bh)
{
    this->bh = bh;
}

SpriteObject::~SpriteObject()
{
    //dtor
}
