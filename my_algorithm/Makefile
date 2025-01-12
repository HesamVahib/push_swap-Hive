NAME = push_swap
FLAGS = -Wall -Werror -Wextra
CC = cc

SRC_PART = 	main.c \
			fewer_three_x.c \
			ft_atoi.c \
			ft_px.c \
			ft_rrx.c \
			ft_rx.c \
			ft_sx.c \
			is_sorted.c \
			min_index.c \
			operations.c

OBJ_PART = $(SRC_PART:.c=.o)

%.o: %.c
	@$(CC) $(FLAGS) -o $@ -c $<
	@echo "\033[90m[\033[32mOK\033[90m]\033[34m Compiling $<\033[0m"

$(NAME): $(OBJ_PART)
	@ar rcs $(NAME) $(OBJ_PART)
	@echo "\033[90m[\033[32mSuccess\033[90m]\033[32m Successfully compiled push_swap\033[0m"

all: $(NAME)

clean:
	@/bin/rm -f $(OBJ_PART)
	@echo "\033[90m[\033[91mDeleting\033[90m]\033[31m Object files deleted\033[0m"

fclean: clean
	@/bin/rm -f $(NAME) push_swap
	@echo "\033[90m[\033[91mDeleting\033[90m]\033[31m push_swap is deleted.\033[0m"

re: fclean all

.PHONY: all clean fclean re