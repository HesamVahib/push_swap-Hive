/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hvahib <hvahib@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 23:12:15 by hvahib            #+#    #+#             */
/*   Updated: 2025/01/17 23:13:04 by hvahib           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_sorted(t_stack_elem *stack)
{
	t_stack_elem	*tmp;

	if (!stack)
		return (1);
	tmp = stack;
	while (tmp->next)
	{
		if (tmp->value > tmp->next->value)
			return (0);
		tmp = tmp->next;
	}
	return (1);
}

int	stack_size(t_stack_elem *stack)
{
	int	size;

	size = 0;
	while (stack)
	{
		size++;
		stack = stack->next;
	}
	return (size);
}

t_stack_elem	*find_last_elem(t_stack_elem *stack)
{
	if (!stack)
		return (NULL);
	while (stack->next)
		stack = stack->next;
	return (stack);
}

t_stack_elem	*find_min(t_stack_elem *stack)
{
	t_stack_elem	*min_elem;

	if (!stack)
		return (NULL);
	min_elem = stack;
	while (stack)
	{
		if (stack->value < min_elem->value)
			min_elem = stack;
		stack = stack->next;
	}
	return (min_elem);
}

t_stack_elem	*find_max(t_stack_elem *stack)
{
	t_stack_elem	*max_elem;

	if (!stack)
		return (NULL);
	max_elem = stack;
	while (stack)
	{
		if (stack->value > max_elem->value)
			max_elem = stack;
		stack = stack->next;
	}
	return (max_elem);
}
