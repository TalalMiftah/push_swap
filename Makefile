SRC = mandatory/ft_printf.c \
		mandatory/parsing.c \
		mandatory/push_swap.c \
		mandatory/split.c \
		mandatory/start.c \
		mandatory/strjoin.c \
		mandatory/operations.c \
		mandatory/operationsII.c \
		mandatory/lbdya.c \
		mandatory/utils.c \
		mandatory/from_a_to_b.c

OBJ = ${SRC:%.c=%.o}

HEADER = push_swap.h

NAME = push_swap

CC = cc

CFLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $@

%.o: %.c $(HEADER)
	$(CC) $(CFLAGS) -c $< -o $@

re : fclean all

clean :
	rm -rf $(OBJ)

n9a : all clean

fclean : clean
	rm -rf $(NAME)
