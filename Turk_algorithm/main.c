#include "push_swap.h"

int main(int argc, char **argv)
{
    t_stack_elem *stack_a;
    t_stack_elem *stack_b;

    stack_a = NULL;
    stack_b = NULL;
    if (argc == 1 || (argc == 2 && !argv[1][0]))
        return (1);
    else if (argc == 2)
        argv = ft_split(argv[1], ' ');
    if (!argv)
        return (1);
    init_stack_a(&stack_a, argv);
    if (!is_sorted(stack_a))
    {
        if (stack_size(stack_a) == 2)
            sa(&stack_a);
        else if (stack_size(stack_a) == 3)
            sort_three(&stack_a);
        else
            sort_stacks(&stack_a, &stack_b);
    }
    free_stack(&stack_a);
    return (0);
}
