#include "sdllib.hpp"

Sdllib::Sdllib(void)
{
		init_sdl();
		win = SDL_CreateWindow("snake", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 640, 480, 0);
		ren = SDL_CreateRenderer(win, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
		create_window_sdl(win);
		sdl_render(win, ren);
}

Sdllib::~Sdllib(void)
{
		Destroy(win, ren);
}

int	Sdllib::init_sdl()
{
		if (SDL_Init(SDL_INIT_VIDEO) != 0){
				std::cout << "SDL_Init Error: " << SDL_GetError() << std::endl;
				return 1;
		}
		return (0);
}

int	Sdllib::userResponse()
{
		while (SDL_PollEvent(&event) != 0) {
			switch(event.type) {
				case SDL_QUIT:
				Destroy(win, ren);
				return (-1);
				break;

				case SDL_KEYDOWN:
					switch (event.key.keysym.sym) {
						case SDLK_UP:
						return (1);
						break;

						case SDLK_DOWN:
						return (2);
						break;

						case SDLK_LEFT:
						return (3);
						break;

						case SDLK_RIGHT:
						return (4);
						break;

						case SDLK_ESCAPE:
						Destroy(win, ren);
						return (-1);
						break;

						case 49:
						return (5);
						break;

						case 50:
						return (6);
						break;

						case 51:
						return (7);
						break;

				}
				break;
			}
		}
		return (0);
}

void Sdllib::printPlayer(std::list<Vector> snakePoints) {
		r.h = 10;
		r.w = 10;
		std::list<Vector>::iterator next;

		SDL_SetRenderDrawColor(ren, 57, 73, 171, 255);
		for (std::list<Vector>::iterator point = snakePoints.begin(); point != snakePoints.end(); ++point) {
				next = point;
				next++;

				if (next != snakePoints.end()) {
						if (next->x > point->x) {
								for (int x = point->x; x != next->x; x++)
								{
										r.y = ((point->y + 1) << 3) + ((point->y + 1) << 1);
										r.x = ((x + 1) << 3) + ((x + 1) << 1);
										SDL_RenderFillRect(ren, &r);
								}
						}
						else if (next->x < point->x) {
								for (int x = next->x; x != point->x; x++)
								{
										r.y = ((point->y + 1) << 3) + ((point->y + 1) << 1);
										r.x = ((x + 1) << 3) + ((x + 1) << 1);
										SDL_RenderFillRect(ren, &r);
								}
						}
						else if (next->y > point->y) {
								for (int y = point->y; y != next->y; y++)
								{
										r.y = ((y + 2) << 3) + ((y + 2) << 1);
										r.x = ((point->x + 1) << 3) + ((point->x + 1) << 1);
										SDL_RenderFillRect(ren, &r);
								}
						}
						else if (next->y < point->y) {
								for (int y = next->y; y != point->y; y++)
								{
										r.y = ((y + 1) << 3) + ((y + 1) << 1);
										r.x = ((point->x + 1) << 3) + ((point->x + 1) << 1);
										SDL_RenderFillRect(ren, &r);
								}
						}
				}
				else {
						SDL_SetRenderDrawColor(ren, 0, 150, 136, 255);
						r.y = ((point->y + 1) << 3) + ((point->y + 1) << 1);
						r.x = ((point->x + 1) << 3) + ((point->x + 1) << 1);
						SDL_RenderFillRect(ren, &r);
				}

		}
}

void Sdllib::drawFrame(Vector mapsize, std::list<Vector> apples, std::list<Vector> playerCords, int) {
		int y = ((mapsize.y + 2) << 3) + ((mapsize.y + 2) << 1);
		int x = ((mapsize.x + 2) << 3) + ((mapsize.x + 2) << 1);
		SDL_Rect	food_rec;
		SDL_Rect	frame_rec;
		frame_rec.h = 1;
		frame_rec.w = 1;

		RenderClear(ren);
		SDL_SetRenderDrawColor(ren, 97, 97, 97, 255);
		for (int i = 0; i != x + 1; i++) {
				SDL_SetRenderDrawColor(ren, 79, 195, 247, 255);
				frame_rec.y = 0;
				frame_rec.x = i;
				SDL_RenderFillRect(ren, &frame_rec);
				frame_rec.y = y;
				frame_rec.x = i;
				SDL_RenderFillRect(ren, &frame_rec);
		}
		for (int i = 0; i != y; i++) {
				frame_rec.y = i;
				frame_rec.x = 0;
				SDL_RenderFillRect(ren, &frame_rec);
				frame_rec.y = i;
				frame_rec.x = x;
				SDL_RenderFillRect(ren, &frame_rec);
		}
		for (std::list<Vector>::iterator apple = apples.begin(); apple != apples.end() ; ++apple) {
				SDL_SetRenderDrawColor(ren, 244, 67, 54, 255);
				food_rec.h = 10;
				food_rec.w = 10;
				food_rec.y = ((apple->y + 1) << 3) + ((apple->y + 1) << 1);
				food_rec.x = ((apple->x + 1) << 3) + ((apple->x + 1) << 1);
				SDL_RenderFillRect(ren, &food_rec);
		}
		printPlayer(playerCords);
		SDL_SetRenderDrawColor(ren, 55, 71, 79, 255);
		RenderPresent(ren);
}

int	Sdllib::create_window_sdl(SDL_Window *win)
{
		if (win == nullptr){
				std::cout << "SDL_CreateWindow Error: " << SDL_GetError() << std::endl;
				SDL_Quit();
				return 1;
		}
		return (0);
}

int	Sdllib::sdl_render(SDL_Window *win, SDL_Renderer *ren)
{
		if (ren == nullptr){
				SDL_DestroyWindow(win);
				std::cout << "SDL_CreateRenderer Error: " << SDL_GetError() << std::endl;
				SDL_Quit();
				return 1;
		}
		return (0);
}

void	Sdllib::Destroy(SDL_Window *win, SDL_Renderer *ren)
{
		SDL_DestroyRenderer(ren);
		SDL_DestroyWindow(win);
		SDL_Quit();
}

void	Sdllib::RenderClear(SDL_Renderer *ren)
{
		SDL_RenderClear(ren);
}

void	Sdllib::RenderCopy(SDL_Renderer *ren, SDL_Texture *tex)
{
		SDL_RenderCopy(ren, tex, NULL, NULL);
}

void	Sdllib::RenderPresent(SDL_Renderer *ren)
{
		SDL_RenderPresent(ren);
}

void	Sdllib::Delay(int delay)
{
		SDL_Delay(delay);
}

extern "C" Sdllib *create_gl() {
		Sdllib *lib = new Sdllib;
		return (lib);
}

extern "C" void destroy_gl(Sdllib *lib) {
		delete lib;
}

// Canonical stuff

Sdllib::Sdllib(Sdllib const & copy) {
	*this = copy;
}

Sdllib& Sdllib::operator=(Sdllib const & copy) {
	if ( this != &copy ) {
 		Sdllib new_gui(copy);
		set_bmp(new_gui.get_bmp());
		set_event(new_gui.get_event());
		set_r(new_gui.get_r());
		set_ren(new_gui.get_ren());
		set_tex(new_gui.get_tex());
		set_win(new_gui.get_win());
	}
	return *this;
}

SDL_Event			Sdllib::get_event() { return event; }
SDL_Rect			Sdllib::get_r() 		{ return r; }
SDL_Renderer*	Sdllib::get_ren() 	{ return ren; }
SDL_Surface*	Sdllib::get_bmp() 	{ return bmp; }
SDL_Texture*	Sdllib::get_tex()	 	{ return tex; }
SDL_Window*		Sdllib::get_win() 	{ return win; }

void Sdllib::set_bmp(SDL_Surface* new_bmp) 	{ bmp = new_bmp; }
void Sdllib::set_event(SDL_Event new_event) { event = new_event; }
void Sdllib::set_r(SDL_Rect new_r) 					{ r = new_r; }
void Sdllib::set_ren(SDL_Renderer* new_ren) { ren = new_ren; }
void Sdllib::set_tex(SDL_Texture* new_tex) 	{ tex = new_tex; }
void Sdllib::set_win(SDL_Window* new_win) 	{ win = new_win; }
