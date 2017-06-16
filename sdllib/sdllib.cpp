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
		while (SDL_PollEvent(&event) != -1) {
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
		for (std::list<Vector>::iterator point = snakePoints.begin(); point != snakePoints.end(); ++point) {
				next = point;
				next++;

				if (next != snakePoints.end()) {
						if (next->x > point->x) {
								for (int x = point->x; x != next->x; x++)
								{
										r.y = point->y + 1;
										r.x = x + 1;
										SDL_RenderFillRect(ren, &r);
								}
						}
						else if (next->x < point->x) {
								for (int x = next->x; x != point->x; x++)
								{
										r.y = point->y + 1;
										r.x = x + 1;
										SDL_RenderFillRect(ren, &r);
								}
						}
						else if (next->y > point->y) {
								for (int y = point->y; y != next->y; y++) 
								{
										r.y = y + 2;
										r.x = point->x + 1;
										SDL_RenderFillRect(ren, &r);
								}
						}
						else if (next->y < point->y) {
								for (int y = next->y; y != point->y; y++)
								{
										r.y = y + 1;
										r.x = point->x + 1;
										SDL_RenderFillRect(ren, &r);
								}
						}
				}
				else {
						r.y = point->y + 1;
						r.x = point->x + 1;
						SDL_RenderFillRect(ren, &r);
				}

		}
}

void Sdllib::drawFrame(Vector mapsize, std::list<Vector> apples, std::list<Vector> playerCords, int) {
		int y = mapsize.y;
		int x = mapsize.x;
		SDL_Rect	food_rec;
		SDL_Rect	frame_rec;
		frame_rec.h = 5;
		frame_rec.w = 5;

		SDL_SetRenderDrawColor(ren, 0, 0, 255, 0);
		RenderClear(ren);
		for (int i = 0; i != x + 1; i++) {
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
				food_rec.h = 5;
				food_rec.w = 5;
				food_rec.y = apple->y + 1;
				food_rec.x = apple->x + 1;
				SDL_SetRenderDrawColor(ren, 255, 100, 0, 255);
				SDL_RenderFillRect(ren, &food_rec);
		}
		printPlayer(playerCords);
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
