NAME 			= Bureaucrat
CC 				= c++
FLAGS 			= -Wall -Wextra -Werror -std=c++98
VALGRIND 		= valgrind --leak-check=full --show-leak-kinds=all ./$(NAME)

SRC 			= $(wildcard src/*.cpp)
SRC 			+= $(wildcard src/exception/*.cpp)
INCLUDE_FILES 	= $(wildcard inc/*.hpp)
INCLUDE_FLAG 	= -Iinc -Iinc/exception

all: $(NAME)

$(NAME): $(SRC) $(INCLUDE_FILES)
	$(CC) $(FLAGS) $(INCLUDE_FLAG) $(SRC) -o $(NAME)

clean:
	rm -rf $(NAME)

fclean: clean

re: fclean all

valgrind: all
	@$(VALGRIND)

v: valgrind
