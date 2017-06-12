#include "../GUIInterface.hpp"
#include <iostream>
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
  	noecho();
  	curs_set(FALSE);
  	keypad(stdscr, TRUE);
  }

  virtual ~ncurseslib () {
    endwin();
  }

  int  playerMovment() {
    return (1);
  }

  void printPlayer(std::list<Vector> snakePoints) {
    for (std::list<Vector>::iterator point = snakePoints.begin(); point != snakePoints.end(); ++point) {
      Vector next = *(std::next(point, 1));
      if (next.x > point->x) {
        for (int i = point->x - 1; i < next.x; i++)
          mvprintw(point->y + 1, i + 1, "-");
      }
      else if (next.x < point->x){
        for (int i = next.x - 1; i < point->x ; i++)
          mvprintw(point->y + 1, i + 1, "!");
      }
      if (point == snakePoints.end()) {
        mvprintw(point->y + 1, point->x + 1, ">");
      }
    }
  }

  void drawFrame(Vector mapsize, std::list<Vector> apples, std::list<Vector> playerCords) {
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
      mvprintw(apple->x + 1, apple->y + 1, "$");
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
