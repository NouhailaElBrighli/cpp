NAME = array

CC = c++

RM = rm -rf

CPPFLAGS = -Wall -Werror -Wextra -std=c++98

SRC =	main.cpp\

OBJ = $(SRC:.cpp=.o)

all : $(NAME)

$(NAME) : $(OBJ)
		$(CC) $(CPPFLAGS) $(OBJ) -o $(NAME)

clean :
		@$(RM) $(OBJ)

fclean : clean
		@$(RM) $(NAME)

re : fclean all