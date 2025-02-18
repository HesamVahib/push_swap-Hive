/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   a_rules.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hvahib <hvahib@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 22:40:05 by hvahib            #+#    #+#             */
/*   Updated: 2025/02/18 21:22:27 by hvahib           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sa(t_stack_elem **stack_a)
{
	t_stack_elem	*temp;
	
	if (!*stack_a || !((*stack_a)->next))
		return ;
	temp = *stack_a;
	*stack_a = (*stack_a)->next;
	temp->next = (*stack_a)->next;
	(*stack_a)->next = temp;
	temp->prev = *stack_a;
	if (temp->next)
		temp->next->prev = temp;
	ft_putendl_fd("sa", 1);
}

void	pa(t_stack_elem **stack_a, t_stack_elem **stack_b)
{
	t_stack_elem	*temp;

	if (!*stack_b)
		return ;
	temp = *stack_a;
	*stack_a = *stack_b;
	*stack_b = (*stack_b)->next;
	if (*stack_b)
		(*stack_b)->prev = NULL;
	(*stack_a)->next = temp;
	if (temp)
		temp->prev = *stack_a;
	ft_putendl_fd("pa", 1);
}

void	ra(t_stack_elem **stack_a)
{
	t_stack_elem	*temp;
	t_stack_elem	*last;

	if (!*stack_a || !((*stack_a)->next))
		return ;
	temp = *stack_a;
	*stack_a = (*stack_a)->next;
	(*stack_a)->prev = NULL;
	last = ft_lstlast(temp);
	last->next = temp;
	temp->prev = last;
	temp->next = NULL;
	ft_putendl_fd("ra", 1);
}

void	rra(t_stack_elem **stack_a)
{
	t_stack_elem	*last;

	if (!*stack_a || !((*stack_a)->next))
		return ;
	last = ft_lstlast(*stack_a);
	if (last->prev)
		last->prev->next = NULL;
	last->prev = NULL;
	last->next = *stack_a;
	(*stack_a)->prev = last;
	*stack_a = last;
	ft_putendl_fd("rra", 1);
}
