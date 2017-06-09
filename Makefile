CC = clang++

FLAGS = -Wall -Wextra -Werror

NAME = Snake

SRC = main.cpp game.cpp apples.cpp player.cpp

$(NAME): all

all:
	@$(CC) $(FLAGS) $(SRC) -o $(NAME)

clean:
	@rm $(NAME)
