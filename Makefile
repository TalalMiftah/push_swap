SRC = mandatory/ft_printf.c \
		mandatory/parsingI.c \
		mandatory/push_swap.c \
		mandatory/split.c \
		mandatory/start.c \
		mandatory/strjoin.c \
		mandatory/operations.c \
		mandatory/operationsII.c \
		mandatory/lbdya.c \
		mandatory/utils.c \
		mandatory/from_a_to_b.c \
		mandatory/parsingII.c

OBJ = ${SRC:%.c=%.o}

HEADER = push_swap.h

NAME = push_swap

BNAME = checker

CC = cc

CFLAGS = -Wall -Wextra -Werror

all: $(NAME)

bonus: $(BNAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $@

$(BNAME): $(OBJB)
	$(CC) $(CFLAGS) $(OBJB) -o $@

%.o: %.c $(HEADER)
	$(CC) $(CFLAGS) -c $< -o $@

re : fclean all

clean :
	rm -rf $(OBJ) $(OBJB)

fclean : clean
	rm -rf $(NAME)
