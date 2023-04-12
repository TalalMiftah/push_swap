SRC = ft_printf.c \
		parsingI.c \
		push_swap.c \
		split.c \
		start.c \
		strjoin.c \
		operations.c \
		operationsII.c \
		lbdya.c \
		utils.c \
		from_a_to_b.c \
		parsingII.c

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
