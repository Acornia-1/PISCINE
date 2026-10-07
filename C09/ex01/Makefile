NAME = libft.a
MY_SOURCES =  srcs/ft_putchar.c \
			srcs/ft_swap.c \
			srcs/ft_putstr.c \
			srcs/ft_strlen.c \
			srcs/ft_strcmp.c
MY_OBJECTS = $(MY_SOURCES:%.c=%.o)
CFLAGS += -Wall -Wextra -Werror

all:$(NAME)

$(NAME):$(MY_OBJECTS)
	ar rcs $@ $^

%.o:%.c
	cc $(CFLAGS) -c -I includes $< -o $@

clean:
	rm -f *.o

fclean: clean
	rm $(NAME)

re: fclean all

.PHONY: all clean fclean re