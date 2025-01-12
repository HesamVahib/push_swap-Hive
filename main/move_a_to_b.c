#include "push_swap.h"


void	prep_for_push(t_stack_elem **stack,
						t_stack_elem *top_node,
						char stack_name) //Define a function that moves the required node to the top of the stack
{
	while (*stack != top_node) //Check if the required node is not already the first node
	{
		if (stack_name == 'a') //If not, and it is stack `a`, execute the following
		{
			if (top_node->above_median)
				ra(stack);
			else
				rra(stack);
		}
		else if (stack_name == 'b') //If not, and it is stack `b`, execute the following
		{
			if (top_node->above_median)
				rb(stack);
			else
				rrb(stack);
		}	
	}
}

void move_a_to_b(t_stack_elem **stack_a, t_stack_elem **stack_b)
{
    t_stack_elem *cheapest_to_push;

    cheapest_to_push = fetch_cheapest(*stack_a); // in stack_init
    if (cheapest_to_push->above_median && cheapest_to_push->target_elem->above_median)
        rotate_both(stack_a, stack_b, cheapest_to_push); // in sorting
    else if (!cheapest_to_push->above_median && !cheapest_to_push->target_elem->above_median)
        rev_rotate_both(stack_a, stack_b, cheapest_to_push); // in sorting
    prep_for_push(stack_a, cheapest_to_push, 'a'); //ensuring that the toppest one is the proper one
    prep_for_push(stack_b, cheapest_to_push->target_elem, 'b');
    pb(stack_b, stack_a);
}

void move_b_to_a(t_stack_elem **stack_a, t_stack_elem **stack_b) // used to be static
{
    prep_for_push(stack_b, (*stack_b)->target_elem, 'a');
    pa(stack_a, stack_b);
}



// I could not understand how prepare and how rotate work. i know how I cannot understand why.