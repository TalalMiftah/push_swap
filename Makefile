SRC =	mandatory/ft_printf.c \
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

BSRC =	bonus/ft_printf.c \
		bonus/start_bonus.c \
		bonus/split.c \
		bonus/operations_bonus.c \
		bonus/operationsII_bonus.c \
		bonus/parsingI_bonus.c \
		bonus/parsingII_bonus.c \
		bonus/get_next_line.c \
		bonus/get_next_line_utils.c \
		bonus/checker.c

OBJ = ${SRC:%.c=%.o}

BOBJ = ${BSRC:%.c=%.o}

HEADER = push_swap.h

NAME = push_swap

BNAME = checker

CC = cc

CFLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $@

bonus: $(BNAME)

$(BNAME): $(BOBJ)
	$(CC) $(CFLAGS) $(BOBJ) -o $@

%.o: %.c $(HEADER)
	$(CC) $(CFLAGS) -c $< -o $@

re : fclean all

clean :
	rm -rf $(OBJ) $(BOBJ)

fclean : clean
	rm -rf $(NAME) $(BNAME)
