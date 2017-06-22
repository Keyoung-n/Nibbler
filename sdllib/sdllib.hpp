#ifndef SDLLIB_HPP
# define SDLLIB_HPP

#include "../Game/GUIInterface.hpp"
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
		Sdllib(Sdllib const & copy);
		Sdllib& operator=(Sdllib const &);
		SDL_Event			get_event();
		SDL_Rect			get_r();
		SDL_Renderer*	get_ren();
		SDL_Surface*	get_bmp();
		SDL_Texture*	get_tex();
		SDL_Window*		get_win();
		int		create_window_sdl(SDL_Window *win);
		int		init_sdl();
		int		sdl_render(SDL_Window *win, SDL_Renderer *ren);
		int		userResponse();
		void	Delay(int delay);
		void	Destroy(SDL_Window *win, SDL_Renderer *ren);
		void	printPlayer(std::list<Vector> snakePoints);
		void	RenderClear(SDL_Renderer *ren);
		void	RenderCopy(SDL_Renderer *ren, SDL_Texture *tex);
		void	RenderPresent(SDL_Renderer *ren);
		void 	drawFrame(Vector mapsize, std::list<Vector> apples, std::list<Vector> playerCords, int score);
		void set_bmp(SDL_Surface*);
		void set_event(SDL_Event);
		void set_r(SDL_Rect);
		void set_ren(SDL_Renderer*);
		void set_tex(SDL_Texture*);
		void set_win(SDL_Window*);
};

std::ostream & operator<<(std::ostream & o, Sdllib const & rhs);
#endif
