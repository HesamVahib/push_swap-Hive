/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   b_rules.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hvahib <hvahib@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 22:40:55 by hvahib            #+#    #+#             */
/*   Updated: 2025/02/22 16:26:09 by hvahib           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sb(t_stack_elem **stack_b, int i)
{
	t_stack_elem	*temp;

	if (!*stack_b || !((*stack_b)->next))
		return ;
	temp = *stack_b;
	*stack_b = (*stack_b)->next;
	temp->next = (*stack_b)->next;
	(*stack_b)->next = temp;
	temp->prev = *stack_b;
	if (temp->next)
		temp->next->prev = temp;
	if (i == 1)
		ft_putendl_fd("sb", 1);
}

void	pb(t_stack_elem **stack_b, t_stack_elem **stack_a)
{
	t_stack_elem	*temp;

	if (!*stack_a)
		return ;
	temp = *stack_b;
	*stack_b = *stack_a;
	*stack_a = (*stack_a)->next;
	if (*stack_a)
		(*stack_a)->prev = NULL;
	(*stack_b)->next = temp;
	if (temp)
		temp->prev = *stack_b;
	ft_putendl_fd("pb", 1);
}

void	rb(t_stack_elem **stack_b, int i)
{
	t_stack_elem	*temp;
	t_stack_elem	*last;

	if (!*stack_b || !((*stack_b)->next))
		return ;
	temp = *stack_b;
	*stack_b = (*stack_b)->next;
	(*stack_b)->prev = NULL;
	last = ft_lstlast(temp);
	last->next = temp;
	temp->prev = last;
	temp->next = NULL;
	if (i == 1)
		ft_putendl_fd("rb", 1);
}

void	rrb(t_stack_elem **stack_b, int i)
{
	t_stack_elem	*last;

	if (!*stack_b || !((*stack_b)->next))
		return ;
	last = ft_lstlast(*stack_b);
	if (last->prev)
		last->prev->next = NULL;
	last->prev = NULL;
	last->next = *stack_b;
	(*stack_b)->prev = last;
	*stack_b = last;
	if (i == 1)
		ft_putendl_fd("rrb", 1);
}
