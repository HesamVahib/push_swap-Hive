#include "push_swap.h"

void  rotate_both(t_stack_elem **stack_a, t_stack_elem **stack_b, t_stack_elem *cheapest_to_push)
{
    while (*stack_b != cheapest_to_push->target_elem && *stack_a != cheapest_to_push) // it might have a problem since the amount of rotation in both stack might be different
        rr(stack_a, stack_b); // in both_rules
    current_index_median(*stack_a); // in stack_init
    current_index_median(*stack_b);
}

void rev_rotate_both(t_stack_elem **stack_a, t_stack_elem **stack_b, t_stack_elem *cheapest_to_push)
{
    while (*stack_b != cheapest_to_push->target_elem && *stack_a != cheapest_to_push)
        rrr(stack_a, stack_b);
    current_index_median(*stack_a);
    current_index_median(*stack_b);
}