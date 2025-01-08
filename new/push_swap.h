#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdbool.h>
# include <limits.h>

typedef struct s_stack_elem
{
    int                value;
    int                index;
    int                push_cost;
    bool               above_median;
    bool               cheapest;
    struct s_stack_elem *target_elem;
    struct s_stack_elem *next;
    struct s_stack_elem *prev;
}	t_stack;



#endif