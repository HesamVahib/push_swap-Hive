/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_a_to_b.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hvahib <hvahib@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 22:59:45 by hvahib            #+#    #+#             */
/*   Updated: 2025/01/17 23:03:07 by hvahib           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	prep_for_push(t_stack_elem **stack,
						t_stack_elem *top_node,
						char stack_name)
{
	while ((*stack)->value != top_node->value)
	{
		if (stack_name == 'a')
		{
			if (top_node->above_median)
				ra(stack);
			else
				rra(stack);
		}
		else if (stack_name == 'b')
		{
			if (top_node->above_median)
				rb(stack);
			else
				rrb(stack);
		}
	}
}

void	move_a_to_b(t_stack_elem **stack_a, t_stack_elem **stack_b)
{
	t_stack_elem	*cheapest_to_push;

	cheapest_to_push = fetch_cheapest(*stack_a);
	if (cheapest_to_push->above_median
		&& cheapest_to_push->target_elem->above_median)
		rotate_both(stack_a, stack_b, cheapest_to_push);
	else if (!(cheapest_to_push->above_median)
		&& !(cheapest_to_push->target_elem->above_median))
		rev_rotate_both(stack_a, stack_b, cheapest_to_push);
	prep_for_push(stack_a, cheapest_to_push, 'a');
	prep_for_push(stack_b, cheapest_to_push->target_elem, 'b');
	pb(stack_b, stack_a);
}

void	move_b_to_a(t_stack_elem **stack_a, t_stack_elem **stack_b)
{
	prep_for_push(stack_a, (*stack_b)->target_elem, 'a');
	pa(stack_a, stack_b);
}
