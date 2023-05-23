NAME = push_swap

DEF_COLOR =		\033[0;39m
RED =			\033[0;91m
GREEN =			\033[0;92m
YELLOW =		\033[0;93m
BLUE =			\033[0;94m
MAGENTA =		\033[0;95m
CYAN =			\033[0;96m
ORANGE =		\033[38;5;209m
BROWN =			\033[38;2;184;143;29m
DARK_YELLOW =	\033[38;5;143m
DARK_GREEN =	\033[38;2;75;179;82m

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
	@echo "\n$(DARK_GREEN)$(NAME) created ✓$(DEF_COLOR)\n"

%.o : %.c
	@echo "$(DARK_YELLOW)Compiling  ${ORANGE}→  $(DARK_GREEN)$< $(DEF_COLOR)"
	@$(CC) $(FLAGS) -c $< -o $@

clean:
	@rm -f $(OBJ)
	@echo "\n$(BROWN)All objects cleaned successfully$(DEF_COLOR)\n"

fclean: 
	@rm -f $(OBJ)
	@rm -f $(NAME)
	@echo "\n$(BROWN)All objects and executable cleaned successfully$(DEF_COLOR)\n"

re: fclean all

.PHONY: all, clean, fclean, re
