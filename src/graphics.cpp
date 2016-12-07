#include "graphics.hpp"

Graphics::Graphics():
	quit(false)
{

}

Graphics::~Graphics()
{

}

bool Graphics::init(int width, int height)
{
	if(SDL_Init(SDL_INIT_EVERYTHING) < 0)
		return false;
		//log something


	window = SDL_CreateWindow("Complex Plane", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, width, height, 0);

	if(window == 0)
		return false;

	renderer = SDL_CreateRenderer(window, -1, 0);

	if(renderer == 0)
		return false;

	return true;

}

void Graphics::close()
{
	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(window);

	SDL_Quit();
}

void Graphics::captureEvents()
{
	SDL_Event e;
	while(SDL_PollEvent(&e))
	{
		if(e.type == SDL_QUIT)
			quit = true;
	}
}

void Graphics::draw()
{
	setRenderTarget();
	SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
	SDL_RenderClear(renderer);

	for(int i = 0; i < textures.size(); i++)
	{
		SDL_RenderCopy(renderer, textures[i], NULL, NULL);
	}

	SDL_RenderPresent(renderer);	
}

void Graphics::drawPoint(int x, int y, char r, char g, char b, char a)
{
	SDL_SetRenderDrawColor(renderer, r, g, b, a);
	SDL_RenderDrawPoint(renderer, x, y);
}