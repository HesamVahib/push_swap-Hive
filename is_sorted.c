#include "push_swap.h"
#include <stdio.h>

int is_sorted_asc(t_stack   x)
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

int is_sorted_desc(t_stack   x)
{
    //printf("I am here in sorted Desc\n");
    int maximum;
    int i;

    maximum = x.stack[0];
    i = 0;
    while (x.stack[i + 1])
    {
        if (maximum >= x.stack[i + 1])
        {
            maximum = x.stack[i + 1];
            i++;
        }
        else
            return (0);
    }
    //printf("I am here in sorted Desc at the end and maximum is: %d\n", maximum);
    return (1);
}