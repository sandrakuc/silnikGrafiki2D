#include "SpriteObject.h"
#include "BitmapHandler.h"
#include <vector>
#include <allegro.h>

using namespace std;

SpriteObject::SpriteObject(BitmapHandler bh)
{
    this->bh = bh;
}

SpriteObject::SpriteObject(vector <BitmapHandler> bmps){
    this->bmps = bmps;
}

SpriteObject::~SpriteObject()
{
    //dtor
}
void SpriteObject::rysuj(BITMAP *buffer, int x, int y){
    blit(bh.bmp, buffer, 0, 0, x, y, bh.x, bh.y);
}

void SpriteObject::addBmp(BitmapHandler bh){
    bmps.push_back(bh);
}

void SpriteObject::dltBmp(){
    bmps.pop_back();
}

void SpriteObject::rdBmp(char *path){
    bh.readBmp(path);
}

void SpriteObject::rdBmp(vector <char *> paths){
    for(int i=0;i<paths.size(); i++){
        bmps[i].readBmp(paths[i]);
    }
}

void SpriteObject::translation(){
    if(bh.bmp != NULL){
        if(key[KEY_UP]){
            bh.y--;
        }
        if(key[KEY_DOWN]){
            bh.y++;
        }
        if(key[KEY_LEFT]){
            bh.x--;
        }
        if(key[KEY_RIGHT]){
            bh.x++;
        }
    }
    if(bmps[0].bmp != NULL){
        for(int i=0;i<bmps.size();i++){
            if(key[KEY_UP]){
            bmps[i].y--;
        }
        if(key[KEY_DOWN]){
            bmps[i].y++;
        }
        if(key[KEY_LEFT]){
            bmps[i].x--;
        }
        if(key[KEY_RIGHT]){
            bmps[i].x++;
        }
        }
    }
}
