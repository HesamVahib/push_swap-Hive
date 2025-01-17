/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hvahib <hvahib@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 22:46:45 by hvahib            #+#    #+#             */
/*   Updated: 2025/01/17 22:46:57 by hvahib           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_duplicated(t_stack_elem *stack_a, int num)
{
	if (!stack_a)
		return (0);
	while (stack_a)
	{
		if (stack_a->value == num)
			return (1);
		stack_a = stack_a->next;
	}
	return (0);
}

void	free_stack(t_stack_elem **stack)
{
	t_stack_elem	*current;
	t_stack_elem	*temp;

	if (stack == NULL || *stack == NULL)
		return ;
	current = *stack;
	while (current != NULL)
	{
		temp = current;
		current = current->next;
		free(temp);
	}
	*stack = NULL;
}

void	error_out(t_stack_elem **stack_a)
{
	free_stack(stack_a);
	ft_putendl_fd("Error", 1);
	exit(1);
}
