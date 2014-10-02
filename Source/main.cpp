#include <iostream>
#include "Sprite.h"
#include "Canvas.h"

using namespace std;

const bool singleStep = false;
const int  fps = 20;

int main()
{
    string canvas_test;
    int    canvas_height, canvas_width;
    cin >> canvas_test >> canvas_height >> canvas_width;

    // test that first word was in fact canvas
    if (canvas_test != "canvas"){
	   return 1;
    }
    
    

    // create a fish and tank instance
    Canvas backdrop(canvas_height, canvas_width);
    Sprite fishy;
    
    
    // read in fish and draw them until an error in readFish()
    // (such as EOF, bad fish input, etc)
    while(fishy.readSprite()){
    	backdrop.addSprite(fishy);
    	fishy.draw(&backdrop);
    }
    

    // simulate motion in tank
    backdrop.simulate(singleStep, fps);
    
    return 0;
}
