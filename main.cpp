#include <iostream>
#include <allegro.h>
#include <vector>
#include "Engine.h"
#include "Point2D.h"
#include "shape/LineSegment.h"
#define WIDTH 1600
#define HEIGHT 900

using namespace std;

int main(){
int mode = 0;
BITMAP *buffer = NULL;
cout << "In which mode do you want to work?" <<endl;
cout << "1 - full screen, resolution: 1600x900" <<endl;
cout << "2 - full screen, resolution: 1280x720" <<endl;
cout << "3 - full screen, resolution: 800x600" <<endl;
cout << "4 - windowed, resolution:1280x720" <<endl;
cout << "5 - windowed, resolution: 800x600" <<endl;
cin >> mode;
Engine *engine = Engine::getInstance();
buffer = engine->initiall(mode, buffer);
//engine->tomekTest(buffer);
engine->sandraTest(buffer);
engine->cleanUp(buffer);
return 0;
}
END_OF_MAIN()
