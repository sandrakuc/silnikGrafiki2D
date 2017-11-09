#include <allegro.h>
#include "Engine.h"
#include "Point2D.h"

volatile long speed = 0;

void increment_speed(){
    speed++;
}
END_OF_FUNCTION(increment_speed);
LOCK_VARIABLE(speed);
LOCK_FUNCTION(increment_speed);

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

Engine::errMsg(){
    set_gfx_mode(GFX_TEXT, 0, 0, 0, 0);
    allegro_message("ALLEGRO ERROR!!!");
    allegro_exit();
    return -1;
}


BITMAP *Engine::initiall(BITMAP *buffer){
    allegro_init();
    Engine::w = 1600;
    Engine::h = 900;
    set_gfx_mode(GFX_AUTODETECT_FULLSCREEN, Engine::w, Engine::h, 0, 0);
    buffer = create_bitmap(Engine::w, Engine::h);
    install_keyboard();
    install_mouse();
    install_timer();
    install_int_ex(increment_speed, BPS_TO_TIMER( 100 ) );
    return buffer;

}

BITMAP *Engine::initiall(int mode, BITMAP *buffer){
    allegro_init();
    switch(mode){
        case 1: {
            Engine::w = 1600;
            Engine::h = 900;
            set_gfx_mode(GFX_AUTODETECT_FULLSCREEN, Engine::w, Engine::h, 0, 0);
            buffer = create_bitmap(Engine::w, Engine::h);
            break;
        }
        case 2: {
            Engine::w = 1280;
            Engine::h = 720;
            set_gfx_mode(GFX_AUTODETECT_FULLSCREEN, Engine::w, Engine::h, 0, 0);
            buffer = create_bitmap(Engine::w, Engine::h);
            break;
        }
        case 3: {
            Engine::w = 800;
            Engine::h = 600;
            set_gfx_mode(GFX_AUTODETECT_FULLSCREEN, Engine::w, Engine::h, 0, 0);
            buffer = create_bitmap(Engine::w, Engine::h);
            break;
        }
        case 4: {
            Engine::w = 1280;
            Engine::h = 720;
            set_gfx_mode(GFX_AUTODETECT_WINDOWED, Engine::w, Engine::h, 0, 0);
            buffer = create_bitmap(Engine::w, Engine::h);
            break;
            break;
        }
        case 5: {
            Engine::w = 800;
            Engine::h = 600;
            set_gfx_mode(GFX_AUTODETECT_WINDOWED, Engine::w, Engine::h, 0, 0);
            buffer = create_bitmap(Engine::w, Engine::h);
            break;
        }
        default: {
            errMsg();
            buffer = NULL;
            return buffer;
            break;
        }
    }
    install_keyboard();
    install_mouse();
    install_timer();
    install_int_ex(increment_speed, BPS_TO_TIMER( 100 ) );
    return buffer;
}

void Engine::blockingKeyboardUsing(BITMAP *buffer){
    int key;
    key = readkey();
    textprintf( buffer, font, 20, 20, makecol( 255, 255, 255 ), "You pressed: %d", key);

}

void Engine::nonBlockingKeyboardUsing(){
    //if(key[KEY_UP]);
    //if(key[KEY_DOWN]);
    //if(key[KEY_LEFT]);
    //if(key[KEY_RIGHT]);
}

void Engine::mainLoop(Engine *engine, BITMAP *buffer){
    while(!key[KEY_ESC]){
        while(speed > 0){
            clear_to_color(buffer, makecol(0,0,0));
            engine->blockingKeyboardUsing(buffer);
            blit( buffer, screen, 0, 0, 0, 0, w, h );
            speed--;
            if(key[KEY_ESC])
                break;
        }
}
}
