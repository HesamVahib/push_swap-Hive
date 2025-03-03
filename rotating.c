/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotating.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hvahib <hvahib@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 23:15:00 by hvahib            #+#    #+#             */
/*   Updated: 2025/02/19 17:03:47 by hvahib           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate_both(t_stack_elem **stack_a, t_stack_elem **stack_b,
					t_stack_elem *cheapest_to_push)
{
	while (*stack_b != cheapest_to_push->target_elem
		&& *stack_a != cheapest_to_push)
		rr(stack_a, stack_b);
	current_index_median(*stack_a);
	current_index_median(*stack_b);
}

void	rev_rotate_both(t_stack_elem **stack_a, t_stack_elem **stack_b,
						t_stack_elem *cheapest_to_push)
{
	while (*stack_b != cheapest_to_push->target_elem
		&& *stack_a != cheapest_to_push)
		rrr(stack_a, stack_b);
	current_index_median(*stack_a);
	current_index_median(*stack_b);
}
