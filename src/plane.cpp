#include "plane.hpp"

Plane::Plane(int _width, int _height, double _center_x, double _center_y, double _hwidth, double _hheight):
	width(_width), height(_height), center_x(_center_x), center_y(_center_y), hwidth(_hwidth), hheight(_hheight)
{
	PixelData = new char[(1 + width) * (1 + height) * 4];
	memset(PixelData, 0, (width * height * 4) * sizeof(char));
	for(int i = 0; i < width * height * 4; i += 4)
		PixelData[i + 3] = 255;
}

Plane::~Plane()
{
	delete PixelData;
}

SDL_Texture* Plane::createTexture(Graphics *g)
{

	SDL_Texture* t = g->createTexture(width, height);
	g->setRenderTarget(t);

	for(int i = 0; i < width * height; i++)
	{
		int x, y;
		x = i % width;
		y = (i - x) / width;
		g->drawPoint(x, y, PixelData[i * 4 + 0], PixelData[i * 4 + 1], PixelData[i * 4 + 2], PixelData[i * 4 + 3]);
	}

	return t;
}

void Plane::setPoint(double x, double y, char r, char g, char b, char a)
{
	int renderx = (double)((double)x * 0.5 / (double)hwidth * (double)width) + width / 2;
	//int renderx = width / 2;
	int rendery = (double)((double)y * -0.5 / (double)hheight * (double)height) + height / 2;;

	std::cout << renderx << " " << rendery << std::endl;

	if(renderx < 0 || renderx > width)
		return;

	if(rendery < 0 || rendery > height)
		return;

	int id = 4 * (renderx + rendery * width) ;

	PixelData[id + 0] = r;
	PixelData[id + 1] = g;
	PixelData[id + 2] = b;
	PixelData[id + 3] = a;

	//std::cout << id << " " << 4 * width * height << std::endl;
}
