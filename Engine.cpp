#include <allegro.h>
#include <iostream>
#include <vector>
#include "Engine.h"

#define MODE_RGB 1

using namespace std;

enum colors{RED = 1, ORANGE = 2, YELLOW = 3, GREEN = 4, CYAN = 5, BLUE = 6, VIOLET = 7, WHITE = 8};

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

void Engine::drawGroupOfPoints(vector<Point2D> points, BITMAP *buffer, double r, double g, double b){
    int ri, gi, bi;
    ri = (int)(r*255);
    gi = (int)(g*255);
    bi = (int)(b*255);
    for(int i = 0; i<points.size(); i++){
        putpixel(buffer, points[i].x, points[i].y, makecol(ri,gi,bi));
    }
}

void Engine::drawGroupOfPoints(vector<Point2D> points, BITMAP *buffer, int color){
    if(color == RED){
    for(int i = 0; i<points.size(); i++){
        putpixel(buffer, points[i].x, points[i].y, makecol(255,0,0));
    }
    }
    if(color == ORANGE){
    for(int i = 0; i<points.size(); i++){
        putpixel(buffer, points[i].x, points[i].y, makecol(255,127,39));
    }
    }
    if(color == YELLOW){
    for(int i = 0; i<points.size(); i++){
        putpixel(buffer, points[i].x, points[i].y, makecol(255,255,0));
    }
    }
    if(color == GREEN){
    for(int i = 0; i<points.size(); i++){
        putpixel(buffer, points[i].x, points[i].y, makecol(0,255,0));
    }
    }
    if(color == CYAN){
    for(int i = 0; i<points.size(); i++){
        putpixel(buffer, points[i].x, points[i].y, makecol(0,255,255));
    }
    }
    if(color == BLUE){
    for(int i = 0; i<points.size(); i++){
        putpixel(buffer, points[i].x, points[i].y, makecol(0,0,255));
    }
    }
    if(color == VIOLET){
    for(int i = 0; i<points.size(); i++){
        putpixel(buffer, points[i].x, points[i].y, makecol(255,0,255));
    }
    }
    if(color == WHITE){
    for(int i = 0; i<points.size(); i++){
        putpixel(buffer, points[i].x, points[i].y, makecol(255,255,255));
    }
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
    Point2D p, a, b;
    //LineSegment line;
    vector <Point2D> points;
    int color, mode, n, x, y, ri, gi, bi, ax, ay, bx, by;
    double rd, gd, bd;
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

    /*cout << "Set point A and B of Line: "<<endl;
    cin >> ax >> ay >> bx >> by;
    a.setXY(ax, ay);
    b.setXY(bx, by);
    //line.setPoints(a, b); */

    cout << "Choose mode of color: "<<endl;
    cout << "1 - RGB: 0-255"<<endl;
    cout << "2 - RGB: 0-1"<<endl;
    cout << "3 - One from the list"<<endl;
    cin >> mode;
    switch(mode){
    case 1: {
    cout << "Choose a color RGB you want to use: "<<endl;
    cin >> ri >> gi >> bi;
    if(ri < 0 || ri > 255 || gi < 0 || gi >255 || bi < 0 || bi >255)
        errMsg();
    break;
    }
    case 2: {
    cin >> rd >> gd >> bd;
    if(ri < 0 || rd > 1 || gd < 0 || gd >1 || bd < 0 || bd >1)
        errMsg();
    break;
    }
    case 3:{
    cout << "1 - RED\n 2 - ORANGE\n 3 - YELLOW\n 4 - GREEN\n 5 - CYAN\n 6 - BLUE\n 7 - VIOLET\n 8 - WHITE" << endl;
    cin >> color;
    if(color < 0 || color > 8)
        errMsg();
    break;
    }
    default: {
    errMsg();
    break;
    }
    }

    while(!key[KEY_ESC]){
        while(speed > 0){
            clear_to_color(buffer, makecol(0,0,0));
            engine->blockingKeyboardUsing(buffer);
            if(mode == MODE_RGB){
                drawGroupOfPoints(points, buffer, ri, gi, bi);


                //line.drawLine(buffer, ri, gi, bi);
            }

            if(mode == 2){
                //line.drawLine(buffer, rd, gd, bd);
                drawGroupOfPoints(points, buffer, rd, gd, bd);
            }


            if(mode == 3){
                drawGroupOfPoints(points, buffer, color);
                //line.drawLine(buffer, color);
            }


            blit( buffer, screen, 0, 0, 0, 0, SCREEN_W, SCREEN_H ); //cos zrobic zeby przy fullscreenie ekran byl ideolo czarny
            speed--;
            if(key[KEY_ESC])
                break;
        }
    }
}


