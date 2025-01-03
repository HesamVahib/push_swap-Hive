#include "push_swap.h"
#include <stdio.h>

void    push_swap(int   argc, char **argv)
{
    t_stack a;
    t_stack b;
    int i, z;
    int isError;

    if (argc < 2)
        return ;
    a.size = argc - 1;
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
        if (!(a.stack[i] = ft_atoi(argv[i + 1]))) //zero has problem and big ints has not been provised
        {
            write(1, "Error\n", 6);
            isError = 1;
            return ;
        }
        i++;
    }
    do_sorting(a, b);
    z = 0;
    while (a.stack[z] || b.stack[z])
    {
        printf("a[%i]:%d, b[%i]:%d\n", z+1, a.stack[z], z+1, b.stack[z]);
        z++;
    }
    //printf("i:%d, j:%d\n", i);

    //do_sorting(a, b);
}

int     main(int argc, char **argv)
{
    push_swap(argc, argv);
    return (0);
}