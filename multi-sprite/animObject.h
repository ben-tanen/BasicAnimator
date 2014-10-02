#ifndef ANIMOBJECT_H
#define ANIMOBJECT_H

#include <string>
using std::string;

class animObject {
	public:
		animObject(int img_num, int img_hgt, int img_wid);

		bool read();
		void draw();
		void animate(int fps);
		
	
	private:
		// max number of sprites per object
		static const int max_img = 15;
		static const int max_hgt = 50;
		static const int max_wid = 50;

		int img_num;
		int img_hgt;
		int img_wid;

		char images[max_img][max_hgt][max_wid];
};

#endif
