#include <iostream>
#include <unistd.h>
#include <stdlib.h>

#include "Sprite.h"
#include "Canvas.h"

using namespace std;

Canvas::Canvas()
{
	// initialize all values to zero
	height = 0;
	width = 0;
	num_sprites = 0;
	clearCanvas();
}

Canvas::Canvas(int hgt, int wid)
{
	// if the given height/width are acceptable
	// initalize the tank with these values
	if (hgt < MAX_HGT && hgt > 0 &&
	    wid < MAX_WID && wid > 0){
	    height = hgt;
	    width = wid;
	    num_sprites = 0;
	    
	    clearCanvas();
	}
  
}

void Canvas::setHeight(int hgt)
{
	height = hgt;
}

void Canvas::setWidth(int wid)
{
	width = wid;
}

int  Canvas::getHeight()
{
	return height;
}

int  Canvas::getWidth()
{
	return width;
}

int  Canvas::getMaxSprites()
{
	return MAX_SPRITES;
}

int  Canvas::getNumSprites()
{
	return num_sprites;
}

bool Canvas::addSprite(Sprite f)
{
	// only add another fish if the number of fishes is
	// less than maximum number of fish
	if (num_sprites >= MAX_SPRITES){
	    return false;
	}
	sprite_holder[num_sprites] = f;
	num_sprites++;
	return true;
}

void Canvas::clearCanvas()
{
	for (int i=0;i<MAX_HGT;i++){
	    for (int j=0;j<MAX_WID;j++){
		canvas_image[i][j] = ' ';
	    }
	} 
}

void Canvas::showCanvas()
{
	for (int i=0;i<height;i++){
	    for (int j=0;j<width;j++){
		cout << canvas_image[i][j];
	    }
	    cout << endl;
	} 
}

void Canvas::UpdateAt(int row, int col, char newChar)
{
	canvas_image[row][col] = newChar;
}

void Canvas::simulate(bool singleStep, int fps)
{
	clear_screen();
	while (1){
	    home_cursor();
	    clearCanvas();
	    // move all fishes to their new posion, and draw them
	    // within the fishtank
	    for (int j=0;j < num_sprites; j++){
		sprite_holder[j].move(height, width);
		sprite_holder[j].draw(this);
	    }
	    showCanvas();
	    home_cursor();
	    cout.flush();
	    
	    if (singleStep) { // allows for single step
		if (system("read x < /dev/tty") != 0)
                exit(0);
	    } else {
		usleep(1000000/fps); // wait for animation cycle
	    }
	}
}

void Canvas::clear_screen()
{
	cout << "\033[2J";
}

void Canvas::home_cursor()
{
	cout << "\33[H";
}


