#ifndef BITMAPHANDLER_H
#define BITMAPHANDLER_H
#include <allegro.h>


class BitmapHandler
{
    public:
        int x, y;
        BitmapHandler(BITMAP *bmp, int x, int y);
        virtual ~BitmapHandler();
        BITMAP *bmp;
        void creatBmp();
        void destroyBmp();
        void readBmp(const char* path);
        void writeBmp(const char* path, BITMAP *b);
    protected:

    private:
};

#endif // BITMAPHANDLER_H
