#include <allegro.h>
#include "Engine.h"

Engine::Engine()
{
    //ctor
}

Engine::~Engine()
{
    //dtor
}

Engine *Engine::single = NULL;

Engine *Engine::getInstance(){
if(single == NULL){
    single = new Engine;
    return single;
}
else
    return single;
}

Engine::initiall(){
    allegro_init();
    set_gfx_mode(GFX_AUTODETECT_FULLSCREEN, 1600, 900, 0, 0);
    install_keyboard();
    install_mouse();
    return 0;

}

Engine::initiall(int mode){
    allegro_init();
    switch(mode){
        case 1: {
            set_gfx_mode(GFX_AUTODETECT_FULLSCREEN, 1600, 900, 0, 0);
            break;
        }
        case 2: {
            set_gfx_mode(GFX_AUTODETECT_FULLSCREEN, 1280, 720, 0, 0);
            break;
        }
        case 3: {
            set_gfx_mode(GFX_AUTODETECT_FULLSCREEN, 800, 600, 0, 0);
            break;
        }
        case 4: {
            set_gfx_mode(GFX_AUTODETECT_WINDOWED, 1280, 720, 0, 0);
            break;
        }
        case 5: {
            set_gfx_mode(GFX_AUTODETECT_WINDOWED, 800, 600, 0, 0);
            break;
        }
        default: {
            set_gfx_mode(GFX_TEXT, 0, 0, 0, 0);
            allegro_message("INVALID VALUE!!!");
            allegro_exit();
            return -1;
            break;
        }
    }
    install_keyboard();
    install_mouse();
    return 0;
}
