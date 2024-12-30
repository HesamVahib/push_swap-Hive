#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>

typedef struct s_stack
{
    int	*stack;
    int	size;
}	t_stack;

void	push_swap(int argc, char **argv);

#endif