#ifndef __PLANEHPP__
#define __PLANEHPP__

#include "graphics.hpp"
#include <iostream>

class Plane
{
public:
	Plane(int _width, int _height, double _center_x, double _center_y, double _hwidth, double _hheight);
	~Plane();

	void setPoint(double x, double y, char r, char g, char b, char a);

	SDL_Texture* createTexture(Graphics *g);

private:
	int width, height;
	double center_x, center_y, hwidth, hheight;
	char * PixelData; //array of size 4 * width * height - 
};


#endif