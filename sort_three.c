/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_three.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hvahib <hvahib@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 23:08:28 by hvahib            #+#    #+#             */
/*   Updated: 2025/02/19 17:03:58 by hvahib           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack_elem	*find_biggest_one(t_stack_elem *stack)
{
	t_stack_elem	*biggest_one;

	biggest_one = stack;
	stack = stack->next;
	while (stack)
	{
		if (stack->value > biggest_one->value)
			biggest_one = stack;
		stack = stack->next;
	}
	return (biggest_one);
}

void	sort_three(t_stack_elem **stack)
{
	t_stack_elem	*biggest_one;

	biggest_one = find_biggest_one(*stack);
	if (biggest_one == *stack)
		ra(stack, 1);
	else if (biggest_one == (*stack)->next)
		rra(stack, 1);
	if ((*stack)->value > (*stack)->next->value)
		sa(stack, 1);
}
