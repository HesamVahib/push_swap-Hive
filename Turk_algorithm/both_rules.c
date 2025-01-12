#include "push_swap.h"

void	ss(t_stack_elem **list_a, t_stack_elem **list_b)
{
	if (!*list_a || !((*list_a)->next) || !*list_b || !((*list_b)->next))
		return ;
	sa(list_a, 0);
	sb(list_b, 0);
	ft_putendl_fd("ss", 1);
}

void	rr(t_stack_elem **list_a, t_stack_elem **list_b)
{
	if (!*list_a || !((*list_a)->next) || !*list_b || !((*list_b)->next))
		return ;
	ra(list_a, 0);
	rb(list_b, 0);
	ft_putendl_fd("rr", 1);
}

void	rrr(t_stack_elem **list_a, t_stack_elem **list_b)
{
	if (!*list_a || !((*list_a)->next) || !*list_b || !((*list_b)->next))
		return ;
	rra(list_a, 0);
	rrb(list_b, 0);
	ft_putendl_fd("rrr", 1);
}