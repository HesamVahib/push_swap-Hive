void    sort_stacks(t_stack_node **stack_a, t_stack_node **stack_b)
{
    int len_a;

    len_a = stack_size(*stack_a);
    if (len_a-- > 3 && !stack_sorted(*stack_a))
        pb(stack_b, stack_a, false);
    if (len_a-- > 3 && !stack_sorted(*stack_a))
        pb(stack_b, stack_a, false);
    while (len_a-- > 3 && !stack_sorted(*stack_a))
    {
        init_nodes_a(*stack_a, *stack_b);
        move_a_to_b(stack_a, stack_b);
    }
    sort_three(stack_a);
    while (*stack_b)
    {
        init_nodes_b(*stack_a, *stack_b);
        move_b_to_a(stack_a, stack_b);
    }
    current_index(*stack_a);
    min_push_to_top(stack_a);
}

static void min_on_top(t_stack_elem **stack_a)
{
    while ((*stack_a)->index != find_min(*stack_a)->index)
    {
        if (find_min(*stack_a)->above_median)
            ra(stack_a, true);
        else
            rra(stack_a, true);
    }
}