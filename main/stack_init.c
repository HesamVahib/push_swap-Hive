/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hvahib <hvahib@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 23:10:27 by hvahib            #+#    #+#             */
/*   Updated: 2025/01/17 23:12:10 by hvahib           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	create_node(t_stack_elem **stack, int value)
{
	t_stack_elem	*new_node;
	t_stack_elem	*last_node;

	if (!stack)
		return ;
	new_node = (t_stack_elem *)malloc(sizeof(t_stack_elem));
	if (!new_node)
		return ;
	new_node->value = value;
	new_node->next = NULL;
	new_node->cheapest = 0;
	if (!(*stack))
	{
		*stack = new_node;
		new_node->prev = NULL;
	}
	else
	{
		last_node = find_last_elem(*stack);
		last_node->next = new_node;
		new_node->prev = last_node;
	}
}

void	init_stack_a(t_stack_elem **stack_a, char **argv)
{
	long	num;
	int		i;

	i = 1;
	while (argv[i])
	{
		num = ft_atoi(argv[i]);
		if (num <= 0 || num > INT_MAX
			|| num < INT_MIN
			|| is_duplicated(*stack_a, (int)num))
			return (error_out(stack_a));
		create_node(stack_a, (int)num);
		i++;
	}
}

t_stack_elem	*fetch_cheapest(t_stack_elem *stack)
{
	while (stack)
	{
		if (stack->cheapest)
			return (stack);
		stack = stack->next;
	}
	return (NULL);
}