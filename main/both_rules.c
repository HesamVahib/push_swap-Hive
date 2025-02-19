/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   both_rules.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hvahib <hvahib@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 22:43:18 by hvahib            #+#    #+#             */
/*   Updated: 2025/02/19 16:49:47 by hvahib           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ss(t_stack_elem **stack_a, t_stack_elem **stack_b)
{
	if (!*stack_a || !((*stack_a)->next) || !*stack_b || !((*stack_b)->next))
		return ;
	sa(stack_a, 0);
	sb(stack_b, 0);
	ft_putendl_fd("ss", 1);
}

void	rr(t_stack_elem **stack_a, t_stack_elem **stack_b)
{
	if (!*stack_a || !((*stack_a)->next) || !*stack_b || !((*stack_b)->next))
		return ;
	ra(stack_a, 0);
	rb(stack_b, 0);
	ft_putendl_fd("rr", 1);
}

void	rrr(t_stack_elem **stack_a, t_stack_elem **stack_b)
{
	if (!*stack_a || !((*stack_a)->next) || !*stack_b || !((*stack_b)->next))
		return ;
	rra(stack_a, 0);
	rrb(stack_b, 0);
	ft_putendl_fd("rrr", 1);
}
