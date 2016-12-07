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

	Plane cplane(width, height, 0, 0, 3.0 / 2.0, 3.0 / 2.0);

	for(int y = 0; y < height; y++)
	{
		for(int x = 0; x < width; x++)
		{
			Complex z((double)x / (double)width * 3.0 - 3.0 / 2.0, (double)y / (double) height * 3.0 - 3.0 / 2.0);
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