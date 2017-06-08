CC = clang++
SDL_LIB = -L/usr/local/lib -lSDL2 -Wl,-rpath=/usr/local/lib
SDL_INCLUDE = -I/usr/local/include
FLAGS = -Wall -Wextra -Werror -std=c++11 $(SDL_INCLUDE)
LIBFLAGS = $(SDL_LIB)
NAME = lib1

SRC = sdllib.cpp main.cpp

OBJ = $(SRC:.cpp=.o)

$(NAME): all

all:
	@$(CC) $(FLAGS) -o lib1 $(SRC) $(LIBFLAGS)

.PHONY: clean

clean:
	@rm $(OBJ)
	@rm $(NAME)

