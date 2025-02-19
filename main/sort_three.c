/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_three.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hvahib <hvahib@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 23:08:28 by hvahib            #+#    #+#             */
/*   Updated: 2025/02/19 16:55:32 by hvahib           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack_elem	*find_biggest_one(t_stack_elem *stack)
{
	t_stack_elem	*biggest_one;

	biggest_one = stack;
	// printf("biggest initially is: %d\n", biggest_one->value);
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

	// printf("before sorting in three head is: %d\n", (*stack)->value);
	biggest_one = find_biggest_one(*stack);
	// printf("biggest value is: %d\n", biggest_one->value);
	if (biggest_one == *stack)
		ra(stack, 1);
	else if (biggest_one == (*stack)->next)
		rra(stack, 1);
	// printf("stack head is: %d\n", (*stack)->value);
	if ((*stack)->value > (*stack)->next->value)
		sa(stack, 1);
}
