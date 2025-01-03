#include "push_swap.h"
#include <stdio.h>

void    do_reverse(t_stack  *a, t_stack *b)
{
    int i, z;

    z = 0;
    while (b->stack[z])// || b.stack[z])
    {
        printf("b[%i]:%d\n", z+1, b->stack[z]);//, z+1, b->stack[z]);
        z++;
    }
    i = b->size;
    while (i >= 0)
    {
        ft_pa(a, b);
        i--;
    }
    printf("Just finished reverse\n");
    z = 0;
    while (a->stack[z])// || b.stack[z])
    {
        printf("a[%i]:%d\n", z+1, a->stack[z]);//, z+1, b->stack[z]);
        z++;
    }
}

void    do_pushing(t_stack  a, t_stack  b, int  index)
{
    //printf("I am in do_pushing\n");
    int a_size;

    a_size = a.size;
    // printf("a.size: %d\n", a.size);
    // return;
    while (a.size == a_size && (index < a_size - 1))
    {
        //printf("I am in do_pushing inside and index is: %d\n", index);
        if (a.stack[0] >= b.stack[0] && a.stack[0] <= b.stack[a_size - 1])
            return (ft_pb(&a, &b));
        else if (index == 1)
            ft_rb(b);
        else if (index <= ((b.size-1)/2))
        {
            ft_rb(b);
            index -= 1;
        }
        else
        {
            //printf("index is: %d and b-size: %d\n", index, b.size);
            ft_rrb(b);
            index += 1;
        }
    }
}

void do_calculated_swap(t_stack *a, t_stack *b)
{
    int ref;
    int i;
    int a_size;

    ref = a->stack[0]; // Access stack using pointer
    a_size = a->size;  // Access size using pointer
    i = 1;

    while (a->size == a_size)
    {
        if (is_sorted_desc(*b) && a->stack[0] >= b->stack[0])
        {
            ft_pb(a, b); // Push operation, passing pointers directly
            return;
        }
        else
        {
            if (i < (b->size) && ref >= b->stack[i] && ref <= b->stack[i - 1])
            {
                do_pushing(*a, *b, i); // Execute pushing
                return;
            }
            i++;
        }

        if (i == b->size)
        {
            if (b->size == 2)
            {
                ft_pb(a, b);
                fewer_three_b(*b); // Handle fewer than three elements
            }
            else
            {
                ft_rrb(*b);  // Reverse rotate b
                ft_pb(a, b); // Push a to b
                ft_rb(*b);    // Rotate b
                ft_rb(*b);    // Rotate b again
            }
        }
    }
}


void    do_sorting(t_stack  a, t_stack  b)
{
    int a_size;

    a_size = a.size;
    if (a.size <= 3)
        fewer_three_a(a);
    else
    {
        printf("a.size: %d and b.size: %d\n", a.size, b.size);
        ft_pb(&a, &b);
        printf("a.size: %d and b.size: %d\n", a.size, b.size);
        ft_pb(&a, &b);
        printf("a.size: %d and b.size: %d\n", a.size, b.size);
        while (a.size != a_size)
        {
            printf("I am here 1 and a.size is: %d\n", a.size);
            if (a.size == 0)
                return (do_reverse(&a, &b));
            if (is_sorted_asc(a) && is_sorted_desc(b) && (a.stack[0] >= b.stack[0]))
                return (do_reverse(&a, &b));
            
            if (a.size <= 3 || b.size <= 3)
            {
                if (a.size <= 3)
                    fewer_three_a(a);
                if (b.size <= 3)
                    fewer_three_b(b);
            }
            
            do_calculated_swap(&a, &b);
            //printf("EXITING b.size here is: %d\n", b.size);
            //break;
            //printf("I am here at the end\n");
        }
    }
        
}