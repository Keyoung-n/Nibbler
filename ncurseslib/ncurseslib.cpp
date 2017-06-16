#include "../GUIInterface.hpp"
#include <ncurses.h>
#include <string>
#include <list>
#include <iterator>

class ncurseslib: public DynamicGUI {
private:
  /* data */

public:
  ncurseslib () {
    initscr();
	start_color();
	init_pair(1, COLOR_BLACK, COLOR_RED);
	init_pair(2, COLOR_BLACK, COLOR_GREEN);
	init_pair(3, COLOR_YELLOW, COLOR_BLACK);
	init_pair(4, COLOR_BLUE, COLOR_BLACK);
  	curs_set(FALSE);
  	keypad(stdscr, TRUE);
  	noecho();
    nodelay(stdscr, TRUE);
  }

  virtual ~ncurseslib () {
    endwin();
  }

  int  userResponse() {
		int ch = getch();
		if (ch != -1) {
      switch(ch) {
    		case KEY_UP:
    			return (1);
    			break;
    		case KEY_DOWN:
    			return (2);
    			break;
    		case KEY_LEFT:
    			return (3);
    			break;
    		case KEY_RIGHT:
    			return (4);
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
    		case 27:
    			return (-1);
    			break;
    	}
    }
    return (0);
  }

  void printPlayer(std::list<Vector> snakePoints) {
	attron(COLOR_PAIR(1));
    std::list<Vector>::iterator next;
    for (std::list<Vector>::iterator point = snakePoints.begin(); point != snakePoints.end(); ++point) {
      next = point;
      next++;

      if (next != snakePoints.end()) {
        if (next->x > point->x) {
			for (int x = point->x; x != next->x; x++)
			{
            	mvaddch(point->y + 1, x + 1, ACS_CKBOARD);
            	mvaddch(point->y + 1, x + 2, ACS_CKBOARD);
            	mvaddch(point->y + 1, x + 3, ACS_CKBOARD);
			}
        }
        else if (next->x < point->x) {
			for (int x = next->x; x != point->x; x++)
            {
				mvaddch(point->y + 1, x + 1, ACS_CKBOARD);
				mvaddch(point->y + 1, x + 2, ACS_CKBOARD);
				mvaddch(point->y + 1, x + 3, ACS_CKBOARD);
			}
        }
        else if (next->y > point->y) {
   			for (int y = point->y; y != next->y; y++) 
			{
				 mvaddch(y + 2, point->x + 1, ACS_CKBOARD);
				 mvaddch(y + 2, point->x + 2, ACS_CKBOARD);
			}
        }
        else if (next->y < point->y) {
          	for (int y = next->y; y != point->y; y++)
			{
            	mvaddch(y + 1, point->x + 1, ACS_CKBOARD);
            	mvaddch(y + 1, point->x + 2, ACS_CKBOARD);
			}
        }
      }
      else {
		attron(COLOR_PAIR(2));
        mvaddch(point->y + 1, point->x + 1, ACS_CKBOARD);
        mvaddch(point->y + 1, point->x + 2, ACS_CKBOARD);
	  }

    }
  }

  void drawFrame(Vector mapsize, std::list<Vector> apples, std::list<Vector> playerCords, int score) {
    int y = mapsize.y + 2;
    int x = mapsize.x + 2;

    clear();
	attron(COLOR_PAIR(4));
	mvprintw(y + 1, 0, "score: %d", score);
    for (int i = 0; i != x + 1; i++) {
      mvaddch(0, i, ACS_CKBOARD);
      mvaddch(y, i, ACS_CKBOARD);
    }
    for (int i = 0; i != y; i++) {
      mvaddch(i, 0, ACS_CKBOARD);
      mvaddch(i, x, ACS_CKBOARD);
    }
	attron(COLOR_PAIR(3));
    for (std::list<Vector>::iterator apple = apples.begin(); apple != apples.end() ; ++apple)
      mvaddch(apple->y + 1, apple->x + 1, ACS_DIAMOND);
    printPlayer(playerCords);
    refresh();
  }
};

extern "C" ncurseslib *create_gl() {
    ncurseslib *lib = new ncurseslib;
    return (lib);
}

extern "C" void destroy_gl(ncurseslib *lib) {
    delete lib;
}
