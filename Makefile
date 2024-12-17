SRC =	get_next_line_utils.c	\
		get_next_line.c

OBJ = $(SRC:.c=.o)

CC = cc

HEADER = get_next_line.h

HEADER_BONUS = get_next_line_bonus.h

HEADER_D = .

NAME = get_next_line.a

OBJ_D = obj/

CFLAGS = -Wall -Wextra -Werror

$(OBJ_D)%.o: %.c $(HEADER) | $(OBJ_D)
		$(CC) $(CFLAGS) -I$(HEADER_D) -c $< -o $@

all:	$(NAME)

$(NAME): $(OBJ) Makefile
		ar rcs $@ $^

$(OBJ_D):
			@mkdir -p $(OBJ_D)

clean:
		@rm -rf $(OBJ) $(OBJ_D)
		@echo "C tout prop' !"

fclean: clean
			rm -f $(NAME)
			@echo "C tout prop' mais mieux !!"

re: fclean all

.PHONY: all clean fclean re