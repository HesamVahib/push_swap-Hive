#include "push_swap.h"
#include <stdio.h>

void    fewer_three_a(t_stack a)
{
    //printf("I am here at fewer A\n");
    int minimum_index;

    if (a.size == 1 || a.size > 3)
        return ;
    while (!(is_sorted_asc(a)))
    {
        if (a.size == 2)
            return (ft_sa(a));
        minimum_index = min_index(a);
        if (minimum_index == 0)
            return (ft_sa(a), ft_ra(a));
        else if (minimum_index == 1 && a.stack[0] >= a.stack[2])
            ft_ra(a);
        else if (minimum_index == 1 && (a.stack[0] < a.stack[2]))
            ft_sa(a);
        else if (minimum_index == 2 && (a.stack[0] <= a.stack[1]))
            ft_rra(a);
        else if (minimum_index == 2 && !(a.stack[0] <= a.stack[1]))
            return (ft_sa(a), ft_rra(a));
    }
}

void    fewer_three_b(t_stack b)
{
    //printf("I am here at fewer B and b.size: %d\n", b.size);
    int maximum_index;

    if (b.size == 1 || b.size > 3)
        return ;
    //printf("I am here after here and is sorted desc: %d\n", is_sorted_desc(b));
    if (!(is_sorted_desc(b)))
    {
        //printf("I am here at fewer B, inside\n");
        if (b.size == 2)
            return (ft_sb(b));
        maximum_index = max_index(b);
        if (maximum_index == 2)
            return (ft_sb(b), ft_rb(b));
        else if (maximum_index == 1 && b.stack[0] <= b.stack[2])
            ft_rb(b);
        else if (maximum_index == 1 && (b.stack[0] > b.stack[2]))
            ft_sb(b);
        else if (maximum_index == 0 && !(b.stack[1] < b.stack[2]))
            return (ft_sb(b), ft_rb(b));
    }
}