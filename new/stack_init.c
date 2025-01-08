

void push_node(t_stack_elem **stack, int data)
{
    t_stack_elem *new_node;
    t_stack_elem *last_node;

    if (!stack)
        return ;
    new_node = (t_stack_elem *)malloc(sizeof(t_stack_elem));
    if (!new_node)
        return ;
    new_node->data = data;
    new_node->next = NULL;
    if (!(*stack))
    {
        stack = new_node;
        node->prev = NULL;
    }
    else
    {
        last_node = find_last_node(*stack);
        last_node->next = new_node;
        new_node->prev = last_node;
    }
}

void init_stack_a(t_stack_elem **stack_a, char **argv)
{
    long num;
    int i;

    i = 0;
    while (argv[i])
    {
        if (error_check(argv[i]))
            free_stack(stack_a);
        num = ft_atoi(argv[i]);
        if (num > INT_MAX || num < INT_MIN)
            free_stack(stack_a);
        push_node(stack_a, (int)num);
        i++;
    }
}

void prepare_push(t_stack_elem **stack, t_stack_elem *target_elem, char stack_name)
{

    while (*stack)
    {
        if (stack_name == 'a')
        {
            if (top_elem->above_mediadn)
                ra(stack, false);
            else
                rra(stack, false);
        }
        else
        {
            if (top_elem->above_median)
                rb(stack, false);
            else
                rrb(stack, false);
        }
    }
}