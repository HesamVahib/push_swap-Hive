#include "push_swap.h"
#include <stdio.h>

void    push_swap(int   argc, char **argv)
{
    t_stack a;
    t_stack b;
    int i;
    int isError;

    if (argc < 2)
        return ;
    a.size = argc - 1;
    printf("a.size: %i\n", a.size);
    a.stack = (int *)malloc(sizeof(int) * a.size);
    if (!a.stack)
        return ;
    b.size = 0;
    b.stack = (int *)malloc(sizeof(int) * a.size);
    if (!b.stack)
        return (free(a.stack));
    i = 0;
    isError = 0;
    while (i < a.size)
    {
        if (!(a.stack[i] = ft_atoi(argv[i + 1]))) {
            write(1, "Error\n", 6);
            isError = 1;
            return ;
        }
        i++;
    }
    b.stack[0] = 1;
    b.stack[1] = 2;
    b.stack[2] = 3;
    b.size = 3;
    if (!isError)
        ft_rrr(a, b);
    i = 0;
    while (i < a.size)
    {
        printf("a[%i]:%d, b[%i]:%d\n", i+1, a.stack[i], i+1, b.stack[i]);
        i++;
    }


    
}

int     main(int argc, char **argv)
{
    push_swap(argc, argv);
    return (0);
}