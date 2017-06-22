CC = clang++
LINUXFLAGS = -fPIC -shared
GDB = -ggdb
FLAGS = -Wall -Wextra -Werror -std=c++11
LIBFLAGS = -I/usr/include/SFML/ -lsfml-graphics -lsfml-window -lsfml-system
NAME = lib2.so

SRC = sfmllib.cpp

OBJ = $(SRC:.cpp=.o)

$(NAME): all

all:
	$(CC) -shared -fPIC $(FLAGS) -o $(NAME) $(SRC) $(LIBFLAGS)

.PHONY: clean

clean:
	@rm $(OBJ)
	@rm $(NAME)
