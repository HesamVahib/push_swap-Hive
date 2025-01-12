#include "push_swap.h"

void	sb(t_stack_elem **list_b)
{
	t_stack_elem	*temp;

	if (!*list_b || !((*list_b)->next))
		return ;
	temp = *list_b;
	*list_b = (*list_b)->next;
	temp->next = (*list_b)->next;
	(*list_b)->next = temp;
	ft_putendl_fd("sb", 1);
}

void	pb(t_stack_elem **list_b, t_stack_elem **list_a)
{
	t_stack_elem	*temp;

	if (!*list_a)
		return ;
	temp = *list_b;
	*list_b = *list_a;
	*list_a = (*list_a)->next;
	(*list_b)->next = temp;
	ft_putendl_fd("pb", 1);
}

void	rb(t_stack_elem **list_b)
{
	t_stack_elem	*temp;

	if (!*list_b || !((*list_b)->next))
		return ;
	temp = *list_b;
	*list_b = ft_lstlast(*list_b);
	(*list_b)->next = temp;
	*list_b = temp->next;
	temp->next = NULL;
	ft_putendl_fd("rb", 1);
}

void	rrb(t_stack_elem **list_b)
{
	t_stack_elem	*temp;
	int			j;

	if (!*list_b || !((*list_b)->next))
		return ;
	j = 0;
	temp = *list_b;
	while ((*list_b)->next)
	{
		*list_b = (*list_b)->next;
		j++;
	}
	(*list_b)->next = temp;
	while (j > 1)
	{
		temp = temp->next;
		j--;
	}
	temp->next = NULL;
	ft_putendl_fd("rrb", 1);
}