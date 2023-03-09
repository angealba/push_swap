NAME = push_swap

SRC = push_swap.c \
	  cheapest_move.c cost.c stack_utils.c ft_split.c input_check.c \
	  long_sort.c push_moves.c reverse_rotate_moves.c rotate_moves.c \
	  short_sort.c swap_moves.c target_position.c utils.c

OBJ = $(SRC:.c=.o)

INCLUDE = push_swap.h

CC = gcc
FLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME) : $(OBJ) $(INCLUDE)
	@$(CC) $(SRC) -o $(NAME)
	@echo "\n $(NAME) created"

%.o : %.c
	$(CC) $(FLAGS) -c $< -o $@

clean:
	rm -f $(OBJ)
	@echo "\n All objects cleaned succesfully"

fclean: 
	rm -f $(NAME)
	@echo "\n All objects and executable cleaned succesfully"

re: fclean all

.PHONY: all, clean, fclean, re
