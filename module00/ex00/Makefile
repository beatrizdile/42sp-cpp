NAME 			= megaphone
CC 				= c++
FLAGS 			= -Wall -Wextra -Werror -std=c++98
VALGRIND 		= valgrind --leak-check=full --show-leak-kinds=all ./$(NAME)

SRC 			= $(wildcard *.cpp)

all: $(NAME)

$(NAME): $(SRC)
	$(CC) $(FLAGS) $(SRC) -o $(NAME)

clean:
	rm -rf $(NAME)

fclean: clean

re: fclean all

valgrind: all
	@$(VALGRIND)

v: valgrind