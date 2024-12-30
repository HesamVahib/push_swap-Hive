#include "push_swap.h"
#include <stdio.h>

void ft_sa(t_stack   a)
{
    int temp;

    if (a.size < 2)
        return ;
    temp = a.stack[0];
    a.stack[0] = a.stack[1];
    a.stack[1] = temp;
}

void ft_sb(t_stack   b) // might have a problem!, I suppose I got the problem for the size of b.
{
    int temp;

    if (b.size < 2)
        return ;
    temp = b.stack[0];
    b.stack[0] = b.stack[1];
    b.stack[1] = temp;
}

void    ft_ss(t_stack   a, t_stack  b)
{
    ft_sa(a);
    ft_sb(b);
}