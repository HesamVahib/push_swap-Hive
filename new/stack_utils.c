bool    stack_sorted(t_stack_elem *stack)
{
    t_stack_elem *tmp;

    if (!stack)
        return (1);
    tmp = stack;
    while (tmp->next)
    {
        if (tmp->data > tmp->next->data)
            return (false);
        tmp = tmp->next;
    }
    return (true);
}

