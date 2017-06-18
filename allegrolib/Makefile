CC = clang++
FLAGS = -Wall -Wextra -Werror
NAME = liballegro.so
SRC = allegrolib.cpp
OBJ = $(SRC:.cpp=.o)

all:
	@echo "compiling liballegro..."
	clang++ -Wall -Wextra -Werror -o liballegro1.so allegrolib.cpp `pkg-config --cflags --libs allegro-5 allegro_main-5 allegro_primitives-5`
	$(CC) -shared $(FLAGS) -o $(NAME) $(SRC) `pkg-config --cflags --libs allegro-5 allegro_primitives-5`

clean:
		@rm $(OBJ)

fclean: clean
		@rm $(NAME)

re: clean all
