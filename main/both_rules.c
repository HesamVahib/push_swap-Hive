#include "push_swap.h"

void ss(t_stack_elem **stack_a, t_stack_elem **stack_b)
{
    if (!*stack_a || !((*stack_a)->next) || !*stack_b || !((*stack_b)->next))
        return;
    sa(stack_a);
    sb(stack_b);
    ft_putendl_fd("ss", 1);
}

void rr(t_stack_elem **stack_a, t_stack_elem **stack_b)
{
    if (!*stack_a || !((*stack_a)->next) || !*stack_b || !((*stack_b)->next))
        return;
    ra(stack_a);
    rb(stack_b);
    ft_putendl_fd("rr", 1);
}

void rrr(t_stack_elem **stack_a, t_stack_elem **stack_b)
{
    if (!*stack_a || !((*stack_a)->next) || !*stack_b || !((*stack_b)->next))
        return;
    rra(stack_a);
    rrb(stack_b);
    ft_putendl_fd("rrr", 1);
}
