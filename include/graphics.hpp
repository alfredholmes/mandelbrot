#ifndef __GRAPHICSHPP__
#define __GRAPHICSHPP__

#include <SDL2/SDL.h>
#include <vector>


class Graphics
{
public:
	Graphics();
	~Graphics();

	bool init(int width, int height);
	void close();

	bool shouldClose() { return quit; }

	void captureEvents();

	void draw();
	void addtoframe(SDL_Texture* t) { textures.push_back(t); }

	void drawPoint(int x, int y, char r, char g, char b, char a);

	SDL_Texture* createTexture(int width, int height) { return SDL_CreateTexture(renderer, SDL_PIXELFORMAT_RGBA8888, SDL_TEXTUREACCESS_TARGET, width, height); }

	void setRenderTarget(SDL_Texture* tex) { SDL_SetRenderTarget(renderer, tex); }
	void setRenderTarget() { SDL_SetRenderTarget(renderer, NULL); }
private:
	SDL_Window* window;
	SDL_Renderer* renderer;

	std::vector<SDL_Texture*> textures;

	bool quit;

};

#endif