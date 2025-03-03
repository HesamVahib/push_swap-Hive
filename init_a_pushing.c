/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_a_pushing.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hvahib <hvahib@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 22:53:44 by hvahib            #+#    #+#             */
/*   Updated: 2025/02/19 16:59:58 by hvahib           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	current_index_median(t_stack_elem *stack)
{
	int					i;
	int					median;

	i = 1;
	if (!stack)
		return ;
	median = ft_lstsize(stack) / 2;
	while (stack)
	{
		stack->index = i;
		if (i <= median + 1)
			stack->above_median = true;
		else
			stack->above_median = false;
		stack = stack->next;
		i++;
	}
}

static void	set_target_a(t_stack_elem *stack_a, t_stack_elem *stack_b)
{
	t_stack_elem	*current_b;
	t_stack_elem	*target_elem;
	long			match_index;

	while (stack_a)
	{
		match_index = LONG_MIN;
		current_b = stack_b;
		while (current_b)
		{
			if (current_b->value < stack_a->value
				&& current_b->value > match_index)
			{
				match_index = current_b->value;
				target_elem = current_b;
			}
			current_b = current_b->next;
		}
		if (match_index == LONG_MIN)
			stack_a->target_elem = find_max(stack_b);
		else
			stack_a->target_elem = target_elem;
		stack_a = stack_a->next;
	}
}

static void	cost_to_push_a(t_stack_elem *stack_a, t_stack_elem *stack_b)
{
	int			len_a;
	int			len_b;

	len_a = ft_lstsize(stack_a);
	len_b = ft_lstsize(stack_b);
	while (stack_a)
	{
		stack_a->push_cost = stack_a->index;
		if (!(stack_a->above_median))
			stack_a->push_cost = len_a - stack_a->index;
		if (stack_a->target_elem->above_median)
			stack_a->push_cost += stack_a->target_elem->index;
		else
			stack_a->push_cost += len_b - stack_a->target_elem->index;
		stack_a = stack_a->next;
	}
}

void	find_cheapest(t_stack_elem *stack)
{
	long			cheapest_value;
	t_stack_elem	*cheapest_elem;

	if (!stack)
		return ;
	cheapest_elem = NULL;
	cheapest_value = LONG_MAX;
	while (stack)
	{
		if (stack->push_cost < cheapest_value)
		{
			cheapest_value = stack->push_cost;
			cheapest_elem = stack;
		}
		stack = stack->next;
	}
	if (cheapest_elem)
		cheapest_elem->cheapest = true;
}

void	init_elems_a(t_stack_elem *stack_a, t_stack_elem *stack_b)
{
	current_index_median(stack_a);
	current_index_median(stack_b);
	set_target_a(stack_a, stack_b);
	cost_to_push_a(stack_a, stack_b);
	find_cheapest(stack_a);
}
