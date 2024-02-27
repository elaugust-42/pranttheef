
NAME = libftprintf.a

CC = cc

CFLAGS = -Wall -Werror -Wextra -g

SRCS = 	ft_printf.c \
		ft_utils.c \
		ft_hex_conv.c

OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
		ar -r $(NAME) $(OBJS)

clean:
		rm -f $(OBJS)
	
fclean: clean
		rm -f $(NAME)
	
re: fclean all