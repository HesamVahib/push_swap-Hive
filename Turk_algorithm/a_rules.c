#include "push_swap.h"

void	sa(t_stack_elem **list_a)
{
	t_stack_elem	*temp;

	if (!*list_a || !((*list_a)->next))
		return ;
	temp = *list_a;
	*list_a = (*list_a)->next;
	temp->next = (*list_a)->next;
	(*list_a)->next = temp;
	ft_putendl_fd("sa", 1);
}

void	pa(t_stack_elem **list_a, t_stack_elem **list_b)
{
	t_stack_elem	*temp;

	if (!*list_b)
		return ;
	temp = *list_a;
	*list_a = *list_b;
	*list_b = (*list_b)->next;
	(*list_a)->next = temp;
	ft_putendl_fd("pa", 1);
}

void	ra(t_stack_elem **list_a)
{
	t_stack_elem	*temp;

	if (!*list_a || !((*list_a)->next))
		return ;
	temp = *list_a;
	*list_a = ft_lstlast(*list_a);
	(*list_a)->next = temp;
	*list_a = temp->next;
	temp->next = NULL;
	ft_putendl_fd("ra", 1);
}

void	rra(t_stack_elem **list_a)
{
	t_stack_elem	*temp;
	int			j;

	if (!*list_a || !((*list_a)->next))
		return ;
	j = 0;
	temp = *list_a;
	while ((*list_a)->next)
	{
		*list_a = (*list_a)->next;
		j++;
	}
	(*list_a)->next = temp;
	while (j > 1)
	{
		temp = temp->next;
		j--;
	}
	temp->next = NULL;
	ft_putendl_fd("rra", 1);
}