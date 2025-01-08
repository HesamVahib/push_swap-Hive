#include "push_swap.h"

void    current_index(t_stack_elem *stack)
{
    int i;
    int median;

    i = 0;
    if (!stack)
        return ;
    median = stack_len(stack) / 2;
    while (stack)
    {
        stack->index = i;
        if (i <= median)
            stack->above_median = true;
        else
            stack->above_median = false
        stack = stack->next;
        ++i;
    }
}

static void set_target_a(t_stack_elem *stack_a, t_stack_elem *stack_b)
{
    t_stack_elem    *current_b;
    t_stack_elem    *target_elem;
    long            best_match_index;

    while (stack_a)
    {
        best_match_index = LONG_MIN;
        current_b = b;
        while (current_b)
        {
            if (current_b->value < a->value && current_b->value > best_match_index)
            {
                best_match_index = current_b->value;
                target_elem = current_b;
            }
            current_b = current_b->next;
        }
        if (best_match_index == LONG_MIN)
            stack_a->target_elem = find_max(stack_b);
        else
            stack_a->target_elem = target_elem;
        stack_a = stack_a->next;
    }
}

static void cost_to_push_a(t_stack_elem *stack_a, t_stack_elem *stack_b)
{
    int len_a;
    int len_b;

    len_a = stack_len(stack_a);
    len_b = stack_len(stack_b);
    while (stack_a)
    {
        stack_a->push_cost = stack_a->index;
        if (!(stack_a->above_median))
            stack_a->push_cost = len_a - (stack_a->index);
        if (stack_a->target_elem->above_median)
            a->push_cost += stack_a->target_elem->index;
        else
            stack_a->push_cost += len_b - (stack_a->target_elem->index);
        stack_a = stack_a->next;
    }
}

static void cost_to_push_a(t_stack_elem *stack_a, t_stack_elem *stack_b)
{
    int len_a;
    int len_b;

    len_a = stack_len(stack_a);
    len_b = stack_len(stack_b);
    while (stack_a)
    {
        stack_a->push_cost = stack_a->index;
        if (!(stack_a->above_median))
            stack_a->push_cost = len_a - (stack_a->index);
        if (stack_a->target_elem->above_median)
            stack_a->push_cost += stack_a->target_elem->index;
        else
            stack_a->push_cost += len_b - (stack_a->target_elem->index);
        stack_a = stack_a->next;
    }
}

void    find_cheapest(t_stack_elem  *stack)
{
    long            cheapest_value;
    t_stack_node    *cheapest_elem;

    if (!stack)
        return ;
    cheapest_value = LONG_MAX;
    while (stack)
    {
        if (stack->push_cost < cheapest_value)
        {
            cheapest_value = stack->push_cost;
            cheapest_elem = stack;
        }
        stack = stack->next;
    }
    cheapest_elem->cheapest = true;

}

void    init_nodes_a(t_stack_elem *stack_a, t_stack_elem *stack_b)
{
    current_index(stack_a);
    current_index(stack_b);
    set_target_a(stack_a, stack_b);
    cost_to_push_a(stack_a, stack_b);
    find_cheapest(stack_a);
}