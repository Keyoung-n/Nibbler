CC = clang++
FLAGS = -Wall -Wextra -Werror
NAME = libncurses.so
SRC = ncurseslib.cpp
OBJ = $(SRC:.cpp=.o)

all:
	@echo "compiling libncurses..."
	@$(CC) $(FLAGS) -c -fPIC $(SRC)
	@$(CC) -shared -fPIC -o $(NAME) $(OBJ) -lncurses

clean:
		@rm $(OBJ)

fclean: clean
		@rm $(NAME)

re: clean all
