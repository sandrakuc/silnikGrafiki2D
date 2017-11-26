#include "BitmapHandler.h"
#include <allegro.h>

BitmapHandler::BitmapHandler(){

}

BitmapHandler::BitmapHandler(BITMAP *bmp, int x, int y)
{
    this->bmp = bmp;
    this->x = x;
    this->y = y;
}

BitmapHandler::~BitmapHandler()
{
    destroyBmp();
}

void BitmapHandler::creatBmp(){
bmp = create_bitmap(x,y);
}

void BitmapHandler::destroyBmp(){
destroy_bitmap(bmp);
}

void BitmapHandler::readBmp(const char* path){
bmp = load_bmp(path, default_palette);
}

void BitmapHandler::writeBmp(const char *path, BITMAP *b){
save_bitmap(path, b, default_palette);
}
