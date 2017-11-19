#include <allegro.h>
#include <iostream>
#include <winalleg.h>

#include <vector>
#include "Engine.h"
#include "Point2D.h"
#include "shape/LineSegment.h"
#include "Viewport.h"
#include "Circle.h"
#include "helper/Color.h"
#include "shape/Shape.h"

#define MODE_RGB_INT 1
#define MODE_RGB_DOUBLE 2
#define MODE_LIST 3

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
    this->filler = Filler();
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

void Engine::drawGroupOfPoints(vector<Point2D> points, BITMAP *buffer, DefinedColor color){
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

void Engine::tomekTest(BITMAP *buffer) {

    Point2D point;
    point.setXY(10,10);

    vector <Point2D> points;
    points.push_back(point);

    drawGroupOfPoints(points, buffer, ORANGE);

    Point2D pointOfCenter(100,100);
    Circle circle = Circle();
    circle.center = pointOfCenter;
    circle.radious = 50;
    circle.draw4(buffer, 100,100,100);

    circle.center.setXY(200, 100);
    circle.draw8(buffer, BLUE);

    this->filler.fillBackgroundRecursive(buffer,circle.center, ORANGE);

    Point2D pointToFill(100,100);
    this->filler.fillBackgroundIterative(buffer,pointToFill,  ORANGE);

    blit( buffer, screen, 0, 0, 0, 0, SCREEN_W, SCREEN_H );
    Sleep(3*1000);
}

void Engine::sandraTest(BITMAP *buffer){
Point2D a, b;
Point2D p1, p2, p3, p4;
a.setXY(10, 25);
b.setXY(100, 125);
p1.setXY(50, 100);
p2.setXY(150,100);
p3.setXY(150,300);
p4.setXY(50,300);
LineSegment line;
line.setAB(a,b);
line.drawLine(buffer, WHITE);
Viewport v;
v.setVertices(p1, p2, p3, p4);
v.clippingRectangle(buffer);
v.cutLine(buffer, line);
}

void Engine::mainLoop(Engine *engine, BITMAP *buffer){

    Point2D p, a, b, pt1, pt2, pt3, pt4;
    pt1.setXY(100,150);
    pt2.setXY(300,150);
    pt3.setXY(300,250);
    pt4.setXY(100,250);
    LineSegment line;
    Viewport v;
    vector <Point2D> points;
    vector <LineSegment> lines;
    int color, mode, n, x, y, ri, gi, bi, ax, ay, bx, by;
    double rd, gd, bd;
    /*cout << "How many points do you want draw?" << endl;
    cin >> n;
    for(int i=0; i<n; i++){
        cout << "\nx: ";
        cin>>x;
        cout<< "y: ";
        cin>>y;
        p.setXY(x, y);
        points.push_back(p);
    }*/

    /*cout << "How many lines do you want draw?" << endl;
    cin >> n;
    for(int i=0; i<n; i++){
    if(i==0){*/
        cout << "Set point A and B of first Line: "<<endl;
        cin >> ax >> ay >> bx >> by;
   /*}
    else{
        cout << "Set point B next Line: "<<endl;
        ax = bx;
        ay = by;
        cin >> bx >> by;
    }*/
    if(ax < 0 || ay < 0 || bx < 0 || by < 0)
        errMsg();
    a.setXY(ax, ay);
    b.setXY(bx, by);
    line.setAB(a, b);
    cout << "DEBUG: A: " << line.getAX() << ", " <<line.getAY() << endl;
    cout << "DEBUG: B: " << line.getBX() << ", " <<line.getBY() << endl;
   /* lines.push_back(line);
    }*/

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
            if(mode == MODE_RGB_INT){
                //drawGroupOfPoints(points, buffer, ri, gi, bi);
                line.drawLine(buffer, ri, gi, bi);
                //line.polyline(buffer, lines, ri, gi, bi);
                //v.Triangle(buffer, pt1, pt2, pt3, ri, gi, bi);
            }

            if(mode == MODE_RGB_DOUBLE){
                line.drawLine(buffer, rd, gd, bd);
                //drawGroupOfPoints(points, buffer, rd, gd, bd);
                //line.polyline(buffer, lines, rd, gd, bd);
                //v.Triangle(buffer, pt1, pt2, pt3, rd, gd, bd);
            }


            if(mode == MODE_LIST){
                //drawGroupOfPoints(points, buffer, color);
                line.drawLine(buffer, color);
               // line.polyline(buffer, lines, color);
               //v.Triangle(buffer, pt1, pt2, pt3, color);
            }
            if(key[KEY_UP]){
                pt1.y--;
                pt2.y--;
                pt3.y--;
                pt4.y--;
            }
            if(key[KEY_DOWN]){
                pt1.y++;
                pt2.y++;
                pt3.y++;
                pt4.y++;
            }
            if(key[KEY_RIGHT]){
                pt1.x++;
                pt2.x++;
                pt3.x++;
                pt4.x++;
            }
            if(key[KEY_LEFT]){
                pt1.x--;
                pt2.x--;
                pt3.x--;
                pt4.x--;
            }
            v.setVertices(pt1, pt2, pt3, pt4);
            v.clippingRectangle(buffer);
            if(key[KEY_ENTER])
                v.cutLine(buffer, line);

            blit( buffer, screen, 0, 0, 0, 0, SCREEN_W, SCREEN_H ); //cos zrobic zeby przy fullscreenie ekran byl ideolo czarny
            speed--;
            if(key[KEY_ESC])
                break;
        }
    }
}
