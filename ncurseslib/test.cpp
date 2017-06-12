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

  void drawFrame(Vector mapsize) {
    int y = mapsize.y + 1;
    int x = mapsize.x + 1;
    clear();
    for (int i = 0; i < mapsize.x; i++) {
      mvprintw(0, i, "*");
      mvprintw(y, i, "*");
    }
    for (int i = 0; i < mapsize.y; i++) {
      mvprintw(i, 0, "*");
      mvprintw(i, x, "*");
    }
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
