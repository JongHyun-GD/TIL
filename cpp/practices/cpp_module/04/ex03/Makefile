CC			= c++
CFLAGS		= -Wall -Wextra -Werror -g -fsanitize=address -std=c++98
NAME		= ex03
SRCS		= main.cpp			\
			  AMateria.cpp		\
			  Ice.cpp			\
			  Cure.cpp			\
			  Character.cpp		\
			  MateriaSource.cpp

OBJS		= $(SRCS:.cpp=.o)

%.o			: %.c
	$(CC) -c $(CFLAGS) $(INC_LINK) $< -o $@

all			: $(NAME)

$(NAME)	: $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) $(LIBFT) -o $(NAME) $(LFLAGS)

clean		:
	rm -f $(OBJS)

fclean		: clean
	rm -f $(NAME)

re			: fclean all

.PHONY		: all clean fclean re
