CC = clang++

FLAGS = -Wall -Wextra -Werror -ldl

GDB = -ggdb

NAME = snake

SRC = main.cpp game.cpp apples.cpp player.cpp gui.cpp

$(NAME): all

all:
	@$(CC) $(GDB) $(SRC) $(FLAGS) -o $(NAME) --std=c++11

clean:
	@rm $(NAME)

run: all
	./$(NAME) 320 240
