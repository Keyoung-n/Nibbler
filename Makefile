CC = g++

FLAGS = -Wall -Wextra -Werror -ldl

NAME = snake

SRC = main.cpp game.cpp apples.cpp player.cpp gui.cpp

$(NAME): all

all:
	@$(CC) $(FLAGS) $(SRC) -o $(NAME)

clean:
	@rm $(NAME)

run: all
	./$(NAME) 50 25
