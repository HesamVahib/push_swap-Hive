#include "push_swap.h"
#include <stdio.h>

void    ft_pa(t_stack   *a, t_stack *b)
{
    if (b->size < 1)
        return ;
    int i;

    i = a->size;
    while (i >= 0)
    {
        a->stack[i] = a->stack[i - 1];
        i--;
    }
    a->stack[0] = b->stack[0];
    i = 0;
    while (b->stack[i] != '\0')
    {
        b->stack[i] = b->stack[i + 1];
        i++;
    }
    b->stack[i] = 0;
    a->size += 1; //Increasing size of a
    b->size -= 1;
    printf("pa\n");
}

void    ft_pb(t_stack   *a, t_stack *b)
{
    if (a->size < 1)
        return ;
    int i;

    i = b->size;
    while (i >= 0)
    {
        b->stack[i] = b->stack[i - 1];
        i--;
    }
    b->stack[0] = a->stack[0];
    i = 0;
    while (a->stack[i] != '\0')
    {
        a->stack[i] = a->stack[i + 1];
        i++;
    }
    a->stack[i] = 0;
    b->size += 1;
    a->size -= 1;
    printf("pb\n"); //Increasing size of b
}