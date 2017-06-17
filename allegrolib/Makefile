CC = g++
FLAGS = -Wall -Wextra -Werror
NAME = liballegro.so
SRC = allegrolib.cpp
OBJ = $(SRC:.cpp=.o)

all:
	@echo "compiling liballegro..."
	@$(CC) $(FLAGS) -c -fPIC $(SRC)
	@$(CC) -shared -fPIC -o $(NAME) $(OBJ) `pkg-config --libs allegro-5.0 allegro_primitives-5.0`

clean:
		@rm $(OBJ)

fclean: clean
		@rm $(NAME)

re: clean all
