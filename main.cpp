#include <iostream>
#include <SDL2/SDL.h>

extern "C" int	init_sdl()
{
	if (SDL_Init(SDL_INIT_VIDEO) != 0){
		std::cout << "SDL_Init Error: " << SDL_GetError() << std::endl;
		return 1;
	}
	return (0);
}

extern "C" int	create_window_sdl(SDL_Window *win)
{
	if (win == nullptr){
		std::cout << "SDL_CreateWindow Error: " << SDL_GetError() << std::endl;
		SDL_Quit();
		return 1;
	}
	return (0);
}

extern "C" int	sdl_render(SDL_Window *win, SDL_Renderer *ren)
{
	if (ren == nullptr){
		SDL_DestroyWindow(win);
		std::cout << "SDL_CreateRenderer Error: " << SDL_GetError() << std::endl;
		SDL_Quit();
		return 1;
	}
	return (0);
}

extern "C" int	load_bmp(SDL_Window *win, SDL_Renderer *ren, SDL_Surface *bmp)
{
	//std::string imagePath = "hello.bmp";
	if (bmp == nullptr){
		SDL_DestroyRenderer(ren);
		SDL_DestroyWindow(win);
		std::cout << "SDL_LoadBMP Error: " << SDL_GetError() << std::endl;
		SDL_Quit();
		return 1;
	}
	return (0);
}

extern "C" int	load_texture(SDL_Window *win, SDL_Renderer *ren, SDL_Surface *bmp, SDL_Texture *tex)
{
	SDL_FreeSurface(bmp);
	if (tex == nullptr){
		SDL_DestroyRenderer(ren);
		SDL_DestroyWindow(win);
		std::cout << "SDL_CreateTextureFromSurface Error: " << SDL_GetError() << std::endl;
		SDL_Quit();
		return 1;
	}
	return (0);
}

extern "C" void	Destroy(SDL_Window *win, SDL_Renderer *ren, SDL_Texture *tex)
{
	SDL_DestroyTexture(tex);
	SDL_DestroyRenderer(ren);
	SDL_DestroyWindow(win);
	SDL_Quit();
}

extern "C" void	RenderClear(SDL_Renderer *ren)
{
	SDL_RenderClear(ren);
}

extern "C" void RenderCopy(SDL_Renderer *ren, SDL_Texture *tex)
{
	SDL_RenderCopy(ren, tex, NULL, NULL);
}

extern "C" void	RenderPresent(SDL_Renderer *ren)
{
	SDL_RenderPresent(ren);
}

extern "C" void Delay(int delay)
{
	SDL_Delay(delay);
}

int main(int, char**){

	init_sdl();
	SDL_Window *win = SDL_CreateWindow("Hello World!", 100, 100, 640, 480, SDL_WINDOW_SHOWN);
	SDL_Renderer *ren = SDL_CreateRenderer(win, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
	SDL_Surface *bmp = SDL_LoadBMP("hello.bmp");
	SDL_Texture *tex = SDL_CreateTextureFromSurface(ren, bmp);
	create_window_sdl(win);
	sdl_render(win, ren);
	load_bmp(win, ren, bmp);
	load_texture(win, ren, bmp, tex);
	for (int i = 0; i < 40; ++i){
		//First clear the renderer
		RenderClear(ren);
		//Draw the texture
		RenderCopy(ren, tex);
		//Update the screen
		RenderPresent(ren);
		//Take a quick break after all that hard work
		Delay(1000);
	}
	Destroy(win, ren, tex);
	return 0;
}
