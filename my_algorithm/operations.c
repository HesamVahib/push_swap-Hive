#include "push_swap.h"
#include <stdio.h>

void    do_reverse(t_stack  *a, t_stack *b)
{
    int i, z;

    i = b->size;
    z = 0;
    while (i > 0)
    {
        if (b->stack[0] <= a->stack[0])
            ft_pa(a, b);
        else
        {
            ft_rrb(*b);
            ft_pa(a, b);
            ft_ra(*a);
        }
        i--;
    }
}

void    do_pushing(t_stack  *a, t_stack  *b, int  index)
{
    int a_size;

    a_size = a->size;

    while (a->size == a_size && (index < b->size))
    {
        if (a->stack[0] >= b->stack[0] && (index == 0 || index == b->size))
            return (ft_pb(a, b));
        else if (a->stack[0] <= b->stack[b->size - 1] && is_sorted_desc(*b))
        {
            ft_pb(a, b);
            ft_rb(*b);
        }
        else if ((index <= ((b->size-1)/2)) && index > 0)
        {
            ft_rb(*b);
            index -= 1;
        }
        else if (((index > ((b->size-1)/2)) && index < b->size))
        {
            ft_rrb(*b);
            index += 1;
        }

    }
}

void do_calculated_swap(t_stack *a, t_stack *b)
{
    int ref;
    int i;
    int a_size;
    int maximum_index;

    ref = a->stack[0];
    a_size = a->size;
    i = 1;

    while (a->size == a_size)
    {
        if ((is_sorted_desc(*b) && a->stack[0] >= b->stack[0]) || (a->stack[0] >= b->stack[0] && a->stack[0] <= b->stack[b->size - 1]))
        {
            ft_pb(a, b);
            return;
        }
        else
        {
            if (i < (b->size) && ref >= b->stack[i] && ref <= b->stack[i - 1])

                return (do_pushing(a, b, i));
            i++;
        }
        if (i == b->size)
        {
            maximum_index = max_index(*b);
            do_pushing(a, b, maximum_index);
        }
    }
}


void    do_sorting(t_stack  a, t_stack  b)
{
    int a_size;

    a_size = a.size;
    if (a.size <= 3)
        fewer_three_a(a);
    else
    {
        ft_pb(&a, &b);
        ft_pb(&a, &b);
        ft_pb(&a, &b);
        if ((a.size <= 3 && b.size <= 3 && a.stack[0] < b.stack[0]) || b.size <= 3)
        {
            if (a.size <= 3 && b.size <= 3 && a.stack[0] < b.stack[0])
                fewer_three_a(a);
            if (b.size <= 3)
                fewer_three_b(b);
        }
        while (a.size != a_size)
        {
            if (a.size == 0 || (is_sorted_asc(a) && is_sorted_desc(b) && (a.stack[0] >= b.stack[0])))
                return (do_reverse(&a, &b));
            do_calculated_swap(&a, &b);
        }
    }
        
}