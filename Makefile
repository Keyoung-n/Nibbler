CC = g++

FLAGS = -Wall -Wextra -Werror -ldl

NAME = Snake

SRC = main.cpp game.cpp apples.cpp player.cpp gui.cpp

$(NAME): all

all:
	@$(CC) $(FLAGS) $(SRC) -o $(NAME)

clean:
	@rm $(NAME)
