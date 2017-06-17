#include "allegrolib.hpp"

allegrolib::allegrolib() {
  if(!al_init()) {
    std::cout << "failed to initialize allegro!\n";
    exit(0);
  }
  if (!al_init_primitives_addon()) {
    std::cout << "failed to initialize primitives addon!\n";
    exit(0);
  }
  display = al_create_display(1300, 700);
  if(!display) {
    std::cout << "failed to create display!\n";
    exit(0);
  }
  if(!al_install_keyboard()) {
   std::cout << "failed to initialize the keyboard!\n";
   exit(0);
  }
  event_queue = al_create_event_queue();
  if (!event_queue) {
    std::cout << "Failed to create event queue";
    exit(0);
  }
  al_register_event_source(event_queue, al_get_keyboard_event_source());
  scale = 10;
}

allegrolib::~allegrolib() {
  al_destroy_display(display);
  al_shutdown_primitives_addon();
}

int allegrolib::userResponse() {
  ALLEGRO_EVENT event;
  bool trueevent;

//  al_wait_for_event(event_queue, &event);
  trueevent = al_get_next_event(event_queue, &event);
  if(trueevent) {
    switch(event.keyboard.keycode) {
     case ALLEGRO_KEY_UP:
       return (1);
       break;

     case ALLEGRO_KEY_DOWN:
       return (2);
       break;

     case ALLEGRO_KEY_LEFT:
       return (3);
       break;

     case ALLEGRO_KEY_RIGHT:
       return (4);
       break;

     case ALLEGRO_KEY_ESCAPE:
       return (-1);
       break;
	 case 49:
		return (5);
		break;
   }
  }
  return (0);
}

void allegrolib::printPlayer(std::list<Vector> snakePoints) {
  std::list<Vector>::iterator next;
  ALLEGRO_COLOR snake_color = al_map_rgb(56, 142, 60);
  ALLEGRO_COLOR head_color = al_map_rgb(100, 255, 218);

  for (std::list<Vector>::iterator point = snakePoints.begin(); point != snakePoints.end(); ++point) {
    next = point;
    next++;

    if (next != snakePoints.end()) {
      if (next->x > point->x) {
        al_draw_line((point->x + 1) * scale, (point->y + 1) * scale, (next->x + 1) * scale, (point->y + 1) * scale, snake_color, 5);
      }
      else if (next->x < point->x) {
        al_draw_line((next->x + 1) * scale, (point->y + 1) * scale, (point->x + 1) * scale, (point->y + 1) * scale, snake_color, 5);
      }
      else if (next->y > point->y) {
        al_draw_line((point->x + 1) * scale, (point->y + 1) * scale, (point->x + 1) * scale, (next->y + 1) * scale, snake_color, 5);
      }
      else if (next->y < point->y) {
        al_draw_line((point->x + 1) * scale, (next->y + 1) * scale, (point->x + 1) * scale, (point->y + 1) * scale, snake_color, 5);
      }
    }
    else
      al_draw_filled_circle((point->x + 1) * scale, (point->y + 1) * scale, 4, head_color);
  }
}

void allegrolib::drawFrame(Vector mapsize, std::list<Vector> apples, std::list<Vector> playerCords, int score) {
  int y = (mapsize.y + 2) * scale;
  int x = (mapsize.x + 2) * scale;

  if (score % 10 == 0)
    score = 10;
  al_clear_to_color(al_map_rgb(0,0,0));
  al_draw_rectangle(0, 0, x, y, al_map_rgb(255, 255, 255), 5);
  for (std::list<Vector>::iterator apple = apples.begin(); apple != apples.end() ; ++apple)
    al_draw_filled_circle((apple->x + 1) * scale, (apple->y + 1) * scale, 4, al_map_rgb(255, 8, 0));
  printPlayer(playerCords);
  al_flip_display();
}

extern "C" allegrolib *create_gl() {
    allegrolib *lib = new allegrolib;
    return (lib);
}

extern "C" void destroy_gl(allegrolib *lib) {
    delete lib;
}
