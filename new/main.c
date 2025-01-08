#include "push_swap.h"

int main(int argc, char **argv)
{
    t_stack_elem *stack_a;
    t_stack_elem *stack_b;

    a = NULL;
    b = NULL;
    if (argc == 1 || (argc == 2 && !argv[1][0]))
        return (1);
    else if (argc == 2)
        argv = ft_split(argv[1], ' ');
    if (!argv)
        return (1);
    init_stack(&a, argv);
    if (!stack_sorted(a))
    {
        if (stack_size(a) == 2)
            sa(&a, false);
        else if (stack_size(a) == 3)
            sort_three(&a);
        else
            sort_stack(&a, &b);
    }
    free_stack(&a);
    return (0);
}