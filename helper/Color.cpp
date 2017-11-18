#include "Color.h"
#include <allegro.h>


Color::Color()
{
    //ctor
}

Color::~Color()
{
    //dtor
}

Color::createIntColor(int red, int green, int blue)
{
    return makecol(red, green, blue);
}

Color::createIntColor(double red, double green, double blue)
{
    int redi, greeni, bluei;
    redi = (int)(255*red);
    greeni = (int)(255*green);
    bluei = (int)(255 * blue);
    int col = makecol(redi, greeni, bluei);
}

Color::createIntColor(DefinedColor color)
{
    if(color == RED)
        return makecol(255, 0, 0);
    if(color == ORANGE)
        return makecol(255, 127, 39);
    if(color == YELLOW)
        return makecol(255, 255, 0);
    if(color == GREEN)
        return makecol(0, 255, 0);
    if(color == CYAN)
        return makecol(0, 255, 255);
    if(color == BLUE)
        return makecol(0, 0, 255);
    if(color == VIOLET)
        return makecol(255, 0, 255);
    if(color == WHITE)
        return makecol(255, 255, 255);

}
