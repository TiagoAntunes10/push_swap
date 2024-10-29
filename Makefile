PRE = ./
HEADER = ./
FUNCTION = ./libft
BONUS = ./bonus/

SOURCE = push_swap.c utils.c checker.c moveset_cross.c \
		moveset_mult.c moveset_stack.c sorters.c cost.c \
		final_steps.c sync_moves.c cost_utils.c final_utils.c

SOURCE_BON = checker_bonus.c push_swap_bonus.c utils_bonus.c \
			 moveset_cross_bonus.c moveset_mult_bonus.c \
			 moveset_stack_bonus.c

SOURCES = ${addprefix $(PRE), $(SOURCE)}
SOURCES_BON = ${addprefix $(BONUS), $(SOURCE_BON)}

NAME = push_swap
NAME_BONUS = checker
LIB = $(FUNCTION)/libftprintf.a

CC = cc
FLAGS = -Wall -Wextra -Werror -g

OBJ = $(SOURCES:.c=.o)
OBJ_BON = $(SOURCES_BON:.c=.o)

all: $(NAME)

$(NAME): $(OBJ) $(LIB)
	cc $(FLAGS) -o $@ $^

$(LIB):
	$(MAKE) -C $(FUNCTION)

.c.o:
		$(CC) $(FLAGS) -I $(HEADER) -c $< -o $(<:.c=.o)

bonus: $(NAME_BONUS)

$(NAME_BONUS): $(OBJ_BON) $(LIB)
	cc $(FLAGS) -o $@ $^

.c.o2:
	$(CC) $(FLAGS) -I $(BONUS) -c $< -o $(<:.c=.o)

clean: 
	rm -f $(OBJ) $(OBJ_BON)
	$(MAKE) clean -C $(FUNCTION)
        
fclean: clean
	rm -f $(NAME) $(NAME_BONUS)
	$(MAKE) fclean -C $(FUNCTION)

re: fclean all
