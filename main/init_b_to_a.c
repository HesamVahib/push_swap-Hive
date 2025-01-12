#include "push_swap.h"

static void set_target_b(t_stack_elem *stack_a, t_stack_elem *stack_b)
{
    t_stack_elem    *current_a;
    t_stack_elem    *target_elem;
    long            best_match_index;

    while (stack_b)
    {
        best_match_index = LONG_MAX;
        current_a = stack_a;
        while (current_a)
        {
            if (current_a->value > stack_b->value && current_a->value < best_match_index)
            {
                best_match_index = current_a->value;
                target_elem = current_a;
            }
            current_a = current_a->next;
        }
        if (best_match_index == LONG_MIN)
            stack_b->target_elem = find_min(stack_a);
        else
            stack_b->target_elem = target_elem;
        stack_b = stack_b->next;
    }
}

void init_b_to_a(t_stack_elem *stack_a, t_stack_elem *stack_b)
{
    current_index_median(stack_a);
    current_index_median(stack_b);
    set_target_b(stack_a, stack_b);
}
