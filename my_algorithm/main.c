#include "push_swap.h"
#include <stdio.h>

int    main(int   argc, char **argv)
{
    t_stack a;
    t_stack b;
    int i;
    int isError;

    if (argc < 2)
        return 0;
    a.size = argc - 1;
    a.stack = (int *)malloc(sizeof(int) * a.size);
    if (!a.stack)
        return 0;
    b.size = 0;
    b.stack = (int *)malloc(sizeof(int) * a.size);
    if (!b.stack)
        return (free(a.stack), 0);
    i = 0;
    isError = 0;
    while (i < a.size)
    {
        if (!(a.stack[i] = atoi(argv[i + 1]))) //zero has problem and big ints has not been provised
        {
            write(1, "Error\n", 6);
            isError = 1;
            return 0;
        }
        i++;
    }
    do_sorting(a, b);
    free(a.stack);
    free(b.stack);
    return (0);
}

