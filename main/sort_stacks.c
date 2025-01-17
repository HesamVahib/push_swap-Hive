/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_stacks.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hvahib <hvahib@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 23:06:23 by hvahib            #+#    #+#             */
/*   Updated: 2025/01/17 23:08:22 by hvahib           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	min_push_to_top(t_stack_elem **stack_a)
{
	while ((*stack_a)->index != find_min(*stack_a)->index)
	{
		if (find_min(*stack_a)->above_median)
			ra(stack_a);
		else
			rra(stack_a);
	}
}

void	sort_stacks(t_stack_elem **stack_a, t_stack_elem **stack_b)
{
	int	len_a;

	len_a = stack_size(*stack_a);
	if (len_a-- > 3 && !is_sorted(*stack_a))
		pb(stack_b, stack_a);
	if (len_a-- > 3 && !is_sorted(*stack_a))
		pb(stack_b, stack_a);
	while (len_a > 3 && !is_sorted(*stack_a))
	{
		init_elems_a(*stack_a, *stack_b);
		move_a_to_b(stack_a, stack_b);
		len_a--;
	}
	sort_three(stack_a);
	while (*stack_b)
	{
		init_b_to_a(*stack_a, *stack_b);
		move_b_to_a(stack_a, stack_b);
	}
	current_index_median(*stack_a);
	min_push_to_top(stack_a);
}
