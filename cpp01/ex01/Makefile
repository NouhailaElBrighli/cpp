NAME =  Moar_brainz

CC = c++

RM = rm -rf

CFLAGS = -Wall -Werror -Wextra -std=c++98

SRC =	main.cpp\
		Zombie.cpp\
		zombieHorde.cpp\

OBJ = $(SRC:.cpp=.o)

all : $(NAME)

$(NAME) : $(OBJ)
		$(CC) $(CFLAGS) $(OBJ) -o $(NAME)

clean :
		@$(RM) $(OBJ)

fclean : clean
		@$(RM) $(NAME)

re : fclean all