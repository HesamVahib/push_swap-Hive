#include "push_swap.h"

void ft_rra(t_stack  a)
{
    if (a.size <= 1)
        return ;
    int i;
    int temp;

    i = 0;
    temp = a.stack[i];
    while (i < a.size)
    {
        a.stack[i] = a.stack[i + 1];
        i++;
    }
    a.stack[a.size - 1] = temp;
}

void ft_rrb(t_stack  b)
{
    if (b.size <= 1)
        return ;
    int i;
    int temp;

    i = 0;
    temp = b.stack[i];
    while (i < b.size)
    {
        b.stack[i] = b.stack[i + 1];
        i++;
    }
    b.stack[b.size - 1] = temp;
}

void ft_rrr(t_stack  a, t_stack  b) //should the else of a t_stack be zero, nothing or !unintended!???
{
    ft_rra(a);
    ft_rrb(b);
}