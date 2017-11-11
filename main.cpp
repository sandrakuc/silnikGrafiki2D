#include <iostream>
#include <allegro.h>
#include <vector>
#include "Engine.h"
#include "Point2D.h"
#define WIDTH 1600
#define HEIGHT 900

using namespace std;

int main(){
int mode = 0;
BITMAP *buffer = NULL;
Point2D p;
vector <Point2D> points;
int n, x, y;
cout << "In which mode do you want to work?" <<endl;
cout << "1 - full screen, resolution: 1600x900" <<endl;
cout << "2 - full screen, resolution: 1280x720" <<endl;
cout << "3 - full screen, resolution: 800x600" <<endl;
cout << "4 - windowed, resolution:1280x720" <<endl;
cout << "5 - windowed, resolution: 800x600" <<endl;
cin >> mode;
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
Engine *engine = Engine::getInstance();
buffer = engine->initiall(mode, buffer);
engine->mainLoop(engine, buffer);
destroy_bitmap(buffer);
allegro_exit();
return 0;
}
END_OF_MAIN()

