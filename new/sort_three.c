t_stack_elem    *find_biggest_one(t_stack_elem *stack)
{
    t_stack_elem *biggest_one;

    biggest_one = stack;
    stack = stack->next;
    while (stack)
    {
        if (stack->data > biggest_one->data)
            biggest_one = stack;
        stack = stack->next;
    }
    return (biggest_one);
}

void    sort_three(t_stack_elem **stack)
{
    t_stack_elem *biggest_one;

    biggest_one = find_biggest_one(*stack);
    if (biggest_one == *stack)
        ra(stack, false);
    else if (biggest_one == (*stack)->next)
        rra(stack, false);
    if ((*stack)->data > (*stack)->next->data)
        sa(stack, false);
}