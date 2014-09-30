#include <iostream>
#include <string>

#include "Sprite.h"
#include "Canvas.h"

using namespace std;

Sprite::Sprite()
{
	// initialize all values to zero/empty string
    img_hgt = 0;
	img_wid = 0;
	pos_vert = 0.0;
	pos_horz = 0.0;
	speed_vert = 0.0;
	speed_horz = 0.0;
	name = "";

	// initialize fish image with all spaces
	for (int i=0;i<MAX_HGT;i++){
		for (int j=0;j<MAX_WID;j++){
		    image[i][j] = ' ';
		}
	}
}

bool Sprite::readSprite()
{
	string test, line, blank_line;
	cin >> test;
	// tests that first word/input is in fact 'fish'
	if (test != "sprite") {
		return false;
	}

	cin >> img_hgt >> img_wid >> pos_vert >> pos_horz
	    >> speed_vert >> speed_horz >> name;
	getline(cin, blank_line); // cin rest of first line (should be blank)
	
	for (int i=0;i<img_hgt;i++){
	    getline(cin, line);
	    for (int j=0;j<img_wid;j++){
		if (j >= line.length())   // if no more characters are present
		    image[i][j] = ' ';    // add spaces to fish image (until max)
		else
		    image[i][j] = line[j];
	    }
	}

	// if any of the following occur (too big, too small, end of file, etc)
	// return false (signifying the fish was not properly read in
	// and will therefore not be added to the fish_holder array
	if ((cin.fail()) || (img_hgt < 0) || (img_hgt > MAX_HGT) ||
	    (img_wid < 0) || (img_wid > MAX_WID))
	    return false;
	
	return true;
}

string Sprite::getName()
{
    	return name;
}

void Sprite::setName(string new_name)
{
    	name = new_name;
}

void Sprite::setHSpeed(float new_speed)
{
	speed_horz = new_speed;
} 

void Sprite::setVSpeed(float new_speed)
{
	speed_vert = new_speed;
}

void Sprite::setPos(int row, int col)
{
	pos_vert = row;
	pos_horz = col;
}

int Sprite::getHeight()
{
    return img_hgt;
}

int Sprite::getWidth()
{
    return img_wid;
}

void Sprite::move(int canvasHeight, int canvasWidth)
{
    pos_vert += speed_vert;
    pos_horz += speed_horz;
    
    // if position is outside of the bounds of the tank,
    // re-position it properly
    if (pos_vert <= -img_hgt)
	pos_vert = canvasHeight - img_hgt;
    else if (pos_vert >= canvasHeight)
	pos_vert = 0;
    else if (pos_horz <= -img_wid)
	pos_horz = canvasWidth - img_wid;
    else if (pos_horz >= canvasWidth)
	pos_horz = 0;
}

void Sprite::draw(Canvas *p_canvas)
{
    int cHeight = p_canvas->getHeight();
    int cWidth  = p_canvas->getWidth();
    
    // loops through ever element of fish image
    for (int i=0;i<img_hgt;i++){
    	for (int j=0;j<img_wid;j++){
    	    int x_pos = pos_horz + j;
    	    int y_pos = pos_vert + i;
		if (image[i][j] != ' '){ // doesn't print spaces
		    // compensates if part of image is outside of tank bounds
		    if (pos_vert+i >= cHeight)
			y_pos = pos_vert + i - cHeight;
		    if (pos_vert+i < 0)
			y_pos = cHeight+(pos_vert + i);
		    if (pos_horz+j >= cWidth)
			x_pos = pos_horz + j - cWidth;
		    if (pos_horz+j < 0)
			x_pos = cWidth+(pos_horz + j);

	        p_canvas->UpdateAt(y_pos,x_pos,image[i][j]);
		}
	}
    }
}