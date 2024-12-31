#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>

typedef struct s_stack
{
    int	*stack;
    int	size;
}	t_stack;

void	push_swap(int argc, char **argv);
int	ft_atoi(const char *str);
void    ft_sa(t_stack   a);
void    ft_sb(t_stack   b);
void    ft_ss(t_stack   a, t_stack  b);
void    ft_pa(t_stack   *a, t_stack *b);
void    ft_pb(t_stack   *a, t_stack *b);
void    ft_ra(t_stack  a);
void    ft_rb(t_stack  b);
void    ft_rr(t_stack  a, t_stack  b);
void    ft_rra(t_stack  a);
void    ft_rrb(t_stack  b);
void ft_rrr(t_stack  a, t_stack  b);
int min_index(t_stack x);
void    do_sorting(t_stack a, t_stack b);
int is_sorted(t_stack   x);

#endif