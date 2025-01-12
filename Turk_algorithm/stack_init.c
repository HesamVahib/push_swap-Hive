#include "push_swap.h"

void create_node(t_stack_elem **stack, int value)
{
    t_stack_elem *new_node;
    t_stack_elem *last_node;

    if (!stack)
        return ;
    new_node = (t_stack_elem *)malloc(sizeof(t_stack_elem));
    if (!new_node)
        return ;
    new_node->value = value;
    new_node->next = NULL;
    new_node->cheapest = 0;
    if (!(*stack))
    {
        *stack = new_node;
        new_node->prev = NULL;
    }
    else
    {
        last_node = find_last_elem(*stack);
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
        num = ft_atoi(argv[i]);
        if (!num || ((num > INT_MAX || num < INT_MIN)) || is_duplicated(*stack_a, num))
            return(error_out(stack_a));
        create_node(stack_a, (int)num);
        i++;
    }
}





// void prepare_push(t_stack_elem **stack, t_stack_elem *target_elem, char stack_name)
// {

//     while (*stack)
//     {
//         if (stack_name == 'a')
//         {
//             if (top_elem->above_mediadn)
//                 ra(stack, false);
//             else
//                 rra(stack, false);
//         }
//         else
//         {
//             if (top_elem->above_median)
//                 rb(stack, false);
//             else
//                 rrb(stack, false);
//         }
//     }
// }