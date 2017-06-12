#include "../GUIInterface.hpp"
#include <iostream>
#include <ncurses.h>
#include <string>

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

  void drawFrame(Vector mapsize, std::list<Vector> apples) {
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
      mvprintw(apple->x + 1, apple->y + 1, "+");
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
