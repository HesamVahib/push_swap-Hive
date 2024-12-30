#include "push_swap.h"
#include <stdio.h>

void    push_swap(int   argc, char **argv)
{
    t_stack a;
    t_stack b;
    int i;

    if (argc < 2)
        return ;
    a.size = argc - 1;
    a.stack = (int *)malloc(sizeof(int) * a.size);
    if (!a.stack)
        return ;
    b.size = 0;
    b.stack = (int *)malloc(sizeof(int) * a.size);
    if (!b.stack)
    {
        free(a.stack);
        return ;
    }
    i = 0;
    while (i < a.size)
    {
        a.stack[i] = ft_atoi(argv[i + 1]);
        i++;
    }
    
}

int     main(int argc, char **argv)
{
    push_swap(argc, argv);
    return (0);
}