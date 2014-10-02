#include <iostream>
#include <unistd.h>
#include <stdlib.h>

#include "animObject.h"

using namespace std;

// constructor (with set img_num and img_size)
animObject::animObject(int img_num, int img_hgt, int img_wid) {
	img_num = img_num;
	img_hgt = img_hgt;
	img_wid = img_wid;

	read();
}

// read in the parameters and sprites of the animObject
// return true if successful (false if not)
bool animObject::read() {
	// insert code here

	return true;
}

// draw the object (current image sprite)
void animObject::draw() {

}

// loop through all object sprites and draw them (at certain fps)
void animObject::animate(int fps) {

}





