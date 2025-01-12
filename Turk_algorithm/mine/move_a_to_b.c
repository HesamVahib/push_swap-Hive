#include "push_swap.h"

void prepare_push(t_stack_elem **stack, t_stack_elem *target_elem, char stack_name)
{
    while (*stack != target_elem)
    {
        if (stack_name == 'a')
        {
            if (target_elem->above_median)
                ra(stack);
            else
                rra(stack);
        }
        else if (stack_name == 'b')
        {
            if (target_elem->above_median)
                rb(stack);
            else
                rrb(stack);
        }
    }
}

static void move_a_to_b(t_stack_elem **stack_a, t_stack_elem **stack_b)
{
    t_stack_elem *cheapest_to_push;

    cheapest_to_push = fetch_cheapest(*stack_a); // in stack_init
    if (cheapest_to_push->above_median && cheapest_to_push->target_elem->above_median)
        rotate_both(stack_a, stack_b, cheapest_to_push); // in sorting
    else if (!cheapest_to_push->above_median && !cheapest_to_push->target_elem->above_median)
        rev_rotate_both(stack_a, stack_b, cheapest_to_push); // in sorting
    prepare_push(stack_a, cheapest_to_push, 'a'); //ensuring that the toppest one is the proper one
    prepare_push(stack_b, cheapest_to_push, 'b');
    pb(stack_b, stack_a);
}

static void move_b_to_a(t_stack_elem **stack_a, t_stack_elem **stack_b)
{
    prepare_push(stack_b, (*stack_b)->target_elem, 'a');
    pa(stack_a, stack_b);
}



// I could not understand how prepare and how rotate work. i know how I cannot understand why.