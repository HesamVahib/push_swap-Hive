#include "push_swap.h"

void ft_ra(t_stack  a)
{
    if (a.size <= 1)
        return ;
    int i;
    int temp;

    i = a.size - 1;
    temp = a.stack[i];
    while (i > 0)
    {
        a.stack[i] = a.stack[i - 1];
        i--;
    }
    a.stack[0] = temp;
}

void ft_rb(t_stack  b)
{
    if (b.size <= 1)
        return ;
    int i;
    int temp;

    i = b.size - 1;
    temp = b.stack[i];
    while (i > 0)
    {
        b.stack[i] = b.stack[i - 1];
        i--;
    }
    b.stack[0] = temp;
}

void ft_rr(t_stack  a, t_stack  b) //should the else of a t_stack be zero, nothing or !unintended!???
{
    ft_ra(a);
    ft_rb(b);
}