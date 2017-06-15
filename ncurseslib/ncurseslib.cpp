#include "ncurseslib.hpp"

ncurseslib::ncurseslib () {
  initscr();
  curs_set(FALSE);
  keypad(stdscr, TRUE);
  noecho();
  nodelay(stdscr, TRUE);
}

ncurseslib::~ncurseslib() {
  endwin();
}

int ncurseslib::userResponse() {
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

void ncurseslib::printPlayer(std::list<Vector> snakePoints) {
  std::list<Vector>::iterator next;
  for (std::list<Vector>::iterator point = snakePoints.begin(); point != snakePoints.end(); ++point) {
    next = point;
    next++;

    if (next != snakePoints.end()) {
      if (next->x > point->x) {
        for (int x = point->x; x != next->x; x++)
          mvprintw(point->y + 1, x + 1, "+");
      }
      else if (next->x < point->x) {
        for (int x = next->x; x != point->x; x++)
          mvprintw(point->y + 1, x + 1, "+");
      }
      else if (next->y > point->y) {
        for (int y = point->y; y != next->y; y++)
          mvprintw(y + 1, point->x + 1, "+");
      }
      else if (next->y < point->y) {
        for (int y = next->y; y != point->y; y++)
          mvprintw(y + 1, point->x + 1, "+");
      }
    }
    else
      mvprintw(point->y + 1, point->x + 1, "#");
  }
}

void ncurseslib::drawFrame(Vector mapsize, std::list<Vector> apples, std::list<Vector> playerCords) {
  int y = mapsize.y + 2;
  int x = mapsize.x + 2;

  clear();
  for (int i = 0; i != x + 1; i++) {
    mvprintw(0, i, "*");
    mvprintw(y, i, "*");
  }
  for (int i = 0; i != y; i++) {
    mvprintw(i, 0, "*");
    mvprintw(i, x, "*");
  }
  for (std::list<Vector>::iterator apple = apples.begin(); apple != apples.end() ; ++apple)
    mvprintw(apple->y + 1, apple->x + 1, "$");
  printPlayer(playerCords);
  refresh();
}

extern "C" ncurseslib *create_gl() {
    ncurseslib *lib = new ncurseslib;
    return (lib);
}

extern "C" void destroy_gl(ncurseslib *lib) {
    delete lib;
}
