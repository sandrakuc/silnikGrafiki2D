#include <allegro.h>
#include <iostream>
#include <vector>
#include "Engine.h"
#include "Point2D.h"

using namespace std;

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

void Engine::drawGroupOfPoints(vector<Point2D> points, BITMAP *buffer, int r, int g, int b){
    for(int i = 0; i<points.size(); i++){
        putpixel(buffer, points[i].x, points[i].y, makecol(r,g,b));
    }
}

BITMAP *Engine::initiall(BITMAP *buffer){
    allegro_init();
    Engine::w = 1600;
    Engine::h = 900;
    set_gfx_mode(GFX_AUTODETECT_FULLSCREEN, Engine::w, Engine::h, 0, 0);
    buffer = create_bitmap(Engine::w, Engine::h);
    if(!buffer){
        errMsg();
    }
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
            buffer = create_bitmap(SCREEN_W, SCREEN_H);
            if(!buffer){
                errMsg();
            }
            break;
        }
        case 2: {
            Engine::w = 1280;
            Engine::h = 720;
            set_gfx_mode(GFX_AUTODETECT_FULLSCREEN, Engine::w, Engine::h, 0, 0);
            buffer = create_bitmap(SCREEN_W, SCREEN_H);
            if(!buffer){
                errMsg();
            }
            break;
        }
        case 3: {
            Engine::w = 800;
            Engine::h = 600;
            set_gfx_mode(GFX_AUTODETECT_FULLSCREEN, Engine::w, Engine::h, 0, 0);
            buffer = create_bitmap(SCREEN_W, SCREEN_H);
            if(!buffer){
                errMsg();
            }
            break;
        }
        case 4: {
            Engine::w = 1280;
            Engine::h = 720;
            set_gfx_mode(GFX_AUTODETECT_WINDOWED, Engine::w, Engine::h, 0, 0);
            buffer = create_bitmap(Engine::w, Engine::h);
            if(!buffer){
                errMsg();
            }
            break;
        }
        case 5: {
            Engine::w = 800;
            Engine::h = 600;
            set_gfx_mode(GFX_AUTODETECT_WINDOWED, Engine::w, Engine::h, 0, 0);
            buffer = create_bitmap(Engine::w, Engine::h);
            if(!buffer){
                errMsg();
            }
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
    Point2D p;
    vector <Point2D> points;
    int n, x, y, r, g, b;
    cout << "How many points do you want draw?" << endl;
    cin >> n;
    for(int i=0; i<n; i++){
        cout << "\nx: ";
        cin>>x;
        cout<< "y: ";
        cin>>y;
        p.x = x;
        p.y = y;
        points.push_back(p);
    }
    cout << "Choose a color RGB you want to use: "<<endl;
    cin >> r >> g >> b;
    if(r < 0 || r > 255 || g < 0 || g >255 || b < 0 || b >255)
        errMsg();
    while(!key[KEY_ESC]){
        while(speed > 0){
            clear_to_color(buffer, makecol(0,0,0));
            engine->blockingKeyboardUsing(buffer);
            drawGroupOfPoints(points, buffer, r, g, b);
            blit( buffer, screen, 0, 0, 0, 0, SCREEN_W, SCREEN_H ); //cos zrobic zeby przy fullscreenie ekran byl ideolo czarny
            speed--;
            if(key[KEY_ESC])
                break;
        }
}
}
