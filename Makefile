NAME = libftprintf.a
HEAD = libftprintf.h

SRCS =	conversion.c spetificator.c \
		parser.c ft_printf.c \
		help_function.c \
		help_function2.c 
		
OBJS = $(SRCS:%.c=%.o)

%.o : %.c $(HEAD)
	gcc -Wall -Wextra -Werror -c $< -o $@

all: $(OBJS)
	ar rcs $(NAME) $(OBJS)

clean:
	rm -f *.o

fclean: clean
	rm -f $(NAME);

re: fclean all

.PHONY: all clean fclean re
