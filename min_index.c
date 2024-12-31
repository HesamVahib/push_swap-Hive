#include "push_swap.h"
#include <stdio.h>

int min_index(t_stack x)
{
    int i;
    int index;
    int min;

    i = 1;
    index = 0;
    min = x.stack[0];
    while (i < x.size)
    {
        if (min >= x.stack[i])
        {
            min = x.stack[i];
            index = i;
        }
        i++;
    }
    return  index;
}