CC			= c++
CFLAGS		= -Wall -Wextra -Werror -g -fsanitize=address -std=c++98
NAME		= ex02
SRCS		= main.cpp			\
			  Animal.cpp		\
			  Cat.cpp 			\
			  Dog.cpp			\
			  Brain.cpp

OBJS		= $(SRCS:.cpp=.o)

%.o			: %.cpp
	$(CC) -c $(CFLAGS) $< -o $@

all			: $(NAME)

$(NAME)	: $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

clean		:
	rm -f $(OBJS)

fclean		: clean
	rm -f $(NAME)

re			: fclean all

.PHONY		: all clean fclean re

