NAME = Snake

SRC = main.cpp Game.cpp Draw.cpp

FLAGS = -Wall -Wextra -Werror

all:
	@clang++ $(FLAGS) $(SRC) -o $(NAME)

clean:
	@rm -rf $(NAME)

re: clean all

run: re
	./$(NAME)
