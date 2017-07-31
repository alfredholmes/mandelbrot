#include "graphics.hpp"
#include "plane.hpp"
#include "complex.hpp"
#include <math.h>


int main(int argc, char** argv)
{
	//display object to handle window management and rendering
	int width = 768;
	int height = 768;

	Graphics display;


	display.init(width, height);


	double center_x = 0;
	double center_y = 0;
	double plane_height = 3.0;
	double plane_width = 3.0;

	Plane cplane(width, height, center_x, center_y, plane_width / 2.0, plane_height / 2.0);

	for(int y = 0; y < height; y++)
	{
		for(int x = 0; x < width; x++)
		{
		  double c_x = ((double)x / (double)width) * plane_width - plane_width / 2.0 + center_x;
			double c_y = (double)y / (double) height * plane_height - plane_height / 2.0 + center_y;
			Complex z(c_x, c_y);
			bool inf = false;
			Complex result;
			int tries = 0;
			for(int i = 0; i < 255; i++)
			{
				result = result.multiply(result).add(z);
				if(result.mag2() > 255)
				{
					inf = true;
					break;
				}
				tries++;
			}


			cplane.setPoint(z.re(), z.im(), tries, tries, tries, tries);


		}
	}



	SDL_Texture* texture = cplane.createTexture(&display);
	display.addtoframe(texture);

	while(!display.shouldClose())
	{
		display.captureEvents();
		display.draw();
		//update function etc
	}

	display.close();

	return 0;

}
