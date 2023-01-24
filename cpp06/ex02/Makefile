NAME =  RealType

CC = c++

RM = rm -rf

CFLAGS = -Wall -Werror -Wextra -std=c++98

SRC =	main.cpp\
		A.cpp\
		B.cpp\
		C.cpp\
		Base.cpp\

OBJ = $(SRC:.cpp=.o)

all : $(NAME)

$(NAME) : $(OBJ)
		$(CC) $(CFLAGS) $(OBJ) -o $(NAME)

clean :
		@$(RM) $(OBJ)
  
fclean : clean
		@$(RM) $(NAME)

re : fclean all