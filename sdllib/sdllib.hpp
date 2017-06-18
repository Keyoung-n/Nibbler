#ifndef SDLLIB_HPP
# define SDLLIB_HPP

#include "../GUIInterface.hpp"
#include <iostream>
#include <string>
#include <list>
#include <iterator>
#include <SDL.h>


class Sdllib : public DynamicGUI {
	public:
		SDL_Window		*win;
		SDL_Renderer	*ren;
		SDL_Surface		*bmp;
		SDL_Texture		*tex;
		SDL_Event		event;
		SDL_Rect		r;

		Sdllib(void);
		virtual	~Sdllib(void);
		int		init_sdl();
		int		create_window_sdl(SDL_Window *win);
		int		sdl_render(SDL_Window *win, SDL_Renderer *ren);
		void	Destroy(SDL_Window *win, SDL_Renderer *ren);
		void	RenderClear(SDL_Renderer *ren);
		void	RenderCopy(SDL_Renderer *ren, SDL_Texture *tex);
		void	RenderPresent(SDL_Renderer *ren);
		void	Delay(int delay);
		int		userResponse();
		void	printPlayer(std::list<Vector> snakePoints);
		void 	drawFrame(Vector mapsize, std::list<Vector> apples, std::list<Vector> playerCords, int score);
		
};

#endif
