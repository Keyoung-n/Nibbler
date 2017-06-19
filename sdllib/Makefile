CC = clang++
MACFLAGS = -dynamiclib -flat_namespace
LINUXFLAGS = -fPIC -shared
GDB = -ggdb
SDL_LIB = $(shell sdl2-config --libs)
SDL_INCLUDE = $(shell sdl2-config --cflags)
SDL_ALL = $(shell sdl2-config --cflags --libs)
FLAGS = -Wall -Wextra -Werror -std=c++11
LIBFLAGS = $(SDL_LIB)
NAME = lib1.so

SRC = sdllib.cpp

OBJ = $(SRC:.cpp=.o)

$(NAME): all

all:
	$(CC) -shared -fPIC $(FLAGS) -o $(NAME) $(SRC) $(SDL_ALL)
#	$(CC) $(GDB) $(FLAGS) -c -fPIC $(SRC)

link:
	@echo $(SDL_LIB)
	@echo $(SDL_INCLUDE)

.PHONY: clean

clean:
	@rm $(OBJ)
	@rm $(NAME)
