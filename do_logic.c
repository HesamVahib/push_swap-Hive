#include "push_swap.h"
#include <stdio.h>

int is_sorted(t_stack   x)
{
    int minimum;
    int i;

    minimum = x.stack[0];
    i = 0;
    while (x.stack[i + 1])
    {
        if (minimum <= x.stack[i + 1])
        {
            minimum = x.stack[i + 1];
            i++;
        }
        else
            return (0);
    }
    return (1);
}

void    do_sorting(t_stack  a, t_stack  b)
{
    int index;
    int i = 0;
    int j = 0, z = 0;

    while (a.size > 1 && !(is_sorted(a)))
    {
        index = min_index(a);
        if ((index == 0) && (a.size > 1))
            ft_pb(&a, &b);
        else if (index == 1)
            ft_sa(a);
        else if (index <= ((a.size-1)/2))
            ft_ra(a);
        else if (index <= a.size-1)
            ft_rra(a);
        else
            break ;
        i++;
    }
    while (b.size > 0)
    {
        ft_pa(&a, &b);
        j++;
    }

    while (a.stack[z+1] || b.stack[z+1])
    {
        printf("a[%i]:%d, b[%i]:%d\n", z+1, a.stack[z], z+1, b.stack[z]);
        z++;
    }
    printf("i:%d, j:%d\n", i, j);
}
    