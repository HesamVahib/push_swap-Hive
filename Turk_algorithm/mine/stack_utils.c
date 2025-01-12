#include "push_swap.h"

int    is_sorted(t_stack_elem *stack)
{
    t_stack_elem *tmp;

    if (!stack)
        return (1);
    tmp = stack;
    while (tmp->next)
    {
        if (tmp->value > tmp->next->value)
            return (0);
        tmp = tmp->next;
    }
    return (1);
}

int stack_size(t_stack_elem *stack)
{
    int i;

    i = 0;
    while (stack->next != NULL)
    {
        i++;
        stack = stack->next;
    }
    return (i);
}

t_stack_elem *find_last_elem(t_stack_elem *stack)
{
    if (stack == NULL)
        return NULL;

    while (stack->next != NULL)
        stack = stack->next;

    return stack;
}

t_stack_elem *find_min(t_stack_elem *stack)
{
    if (stack == NULL)
        return NULL;

    t_stack_elem *min_elem = stack;

    while (stack != NULL)
    {
        if (stack->value < min_elem->value)
            min_elem = stack;
        stack = stack->next;
    }

    return min_elem;
}

t_stack_elem *find_max(t_stack_elem *stack)
{
    if (stack == NULL)
        return NULL;

    t_stack_elem *max_elem = stack;

    while (stack != NULL)
    {
        if (stack->value > max_elem->value)
            max_elem = stack;
        stack = stack->next;
    }

    return max_elem;
}