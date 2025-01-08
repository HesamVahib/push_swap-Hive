static void move_a_to_b(t_stack_elem **stack_a, t_stack_elem **stack_b)
{
    t_stack_elem *cheapest_to_push;

    cheapest_to_push = find_cheapest(*stack_a);
    if (cheapest_to_push->above_median && cheapest_to_push->target_elem->above_median)
        rotate_both(stack_a, stack_b, cheapest_to_push);
    else if (!cheapest_to_push->above_median && !cheapest_to_push->target_elem->above_median)
        rev_rotate_both(stack_a, stack_b, cheapest_to_push);
    prepare_push(stack_a, cheapest_to_push, 'a');
    prepare_push(stack_b, cheapest_to_push, 'b');
    pb(stack_b, stack_a, false);
}

static void move_b_to_a(t_stack_elem **stack_a, t_stack_elem **stack_b)
{
    prepare_push(stack_b, (*stack_b)->target_elem, 'a');
    pa(stack_a, stack_b, false);
}