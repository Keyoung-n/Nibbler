#ifndef SDLLIB_HPP
# define SDLLIB_HPP

#include <iostream>
#include <SDL2/SDL.h>


class Sdllib : public Ilib {
	public:
		SDL_Window	*win;
		SDL_Renderer	*ren;
		SDL_Surface	*bmp;
		SDL_Texture	*tex;

		Sdllib(void);
		~Sdllib(void);
		int	init_sdl();
		int	create_window_sdl(SDL_Window *win);
		int	sdl_render(SDL_Window *win, SDL_Renderer *ren);
		int	load_bmp(SDL_Window *win, SDL_Renderer *ren, SDL_Surface *bmp);
		int	load_texture(SDL_Window *win, SDL_Renderer *ren, SDL_Surface *bmp, SDL_Texture *tex);
		void	Destroy(SDL_Window *win, SDL_Renderer *ren, SDL_Texture *tex);
		void	RenderClear(SDL_Renderer *ren);
		void	RenderCopy(SDL_Renderer *ren, SDL_Texture *tex);
		void	RenderPresent(SDL_Renderer *ren);
		void	Delay(int delay);
	
	
};

#endif
