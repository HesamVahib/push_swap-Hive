NAME = push_swap
FLAGS = -Wall -Werror -Wextra
CC = cc

SRC_PART = 	main.c \
			a_rules.c \
            b_rules.c \
            both_rules.c \
			errors.c \
            ft_atoi.c \
            init_a_pushing.c \
            init_b_returning.c \
			libft.c \
            move_a_to_b.c \
			sort_stacks.c \
			sort_three.c \
			rotating.c \
			split.c \
			stack_init.c \
			stack_utils.c


OBJ_PART = $(SRC_PART:.c=.o)

%.o: %.c
	@$(CC) $(FLAGS) -o $@ -c $<
	@echo "\033[90m[\033[32mOK\033[90m]\033[34m Compiling $<\033[0m"

$(NAME): $(OBJ_PART)
	@$(CC) $(FLAGS) -o $(NAME) $(OBJ_PART)
	@echo "\033[90m[\033[32mSuccess\033[90m]\033[32m Successfully compiled push_swap executable\033[0m"

all: $(NAME)

clean:
	@/bin/rm -f $(OBJ_PART)
	@echo "\033[90m[\033[91mDeleting\033[90m]\033[31m Object files deleted\033[0m"

fclean: clean
	@/bin/rm -f $(NAME)
	@echo "\033[90m[\033[91mDeleting\033[90m]\033[31m Executable $(NAME) is deleted.\033[0m"

re: fclean all

.PHONY: all clean fclean re

