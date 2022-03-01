CC			= c++
CFLAGS		= -Wall -Wextra -Werror -g -std=c++98 -Wshadow -Wno-shadow
NAME		= DiamondTrap
SRCS		= main.cpp \
			  ClapTrap.cpp \
			  ScavTrap.cpp \
			  FragTrap.cpp \
			  DiamondTrap.cpp
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
