/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hvahib <hvahib@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 23:00:00 by hvahib            #+#    #+#             */
/*   Updated: 2025/02/18 18:19:20 by hvahib           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdbool.h>
# include <limits.h>
# include <stdlib.h>
# include <unistd.h>

# include <stdio.h>

typedef struct s_stack_elem
{
	int					value;
	int					index;
	int					push_cost;
	bool				above_median;
	bool				cheapest;
	struct s_stack_elem	*target_elem;
	struct s_stack_elem	*next;
	struct s_stack_elem	*prev;
}	t_stack_elem;

void			ft_putendl_fd(char *s, int fd);
void			current_index_median(t_stack_elem *stack);
void			find_cheapest(t_stack_elem *stack);
void			init_elems_a(t_stack_elem *stack_a, t_stack_elem *stack_b);
void			move_a_to_b(t_stack_elem **stack_a, t_stack_elem **stack_b);
void			sort_stacks(t_stack_elem **stack_a, t_stack_elem **stack_b);
t_stack_elem	*find_biggest_one(t_stack_elem *stack);
void			sort_three(t_stack_elem **stack);
char			**ft_split(char const *s, char c);
void			init_stack_a(t_stack_elem **stack_a, char **argv);
int				is_sorted(t_stack_elem *stack);
int				stack_size(t_stack_elem *stack);
void			clear_stack(t_stack_elem **stack);
int				check_syntax(char *str_n);
long			ft_atol(const char *s);

void			sa(t_stack_elem **list_a);
void			pa(t_stack_elem **list_a, t_stack_elem **list_b);
void			ra(t_stack_elem **list_a);
void			rra(t_stack_elem **list_a);

void			sb(t_stack_elem **list_b);
void			pb(t_stack_elem **list_b, t_stack_elem **list_a);
void			rb(t_stack_elem **list_b);
void			rrb(t_stack_elem **list_b);

void			ss(t_stack_elem **list_a, t_stack_elem **list_b);
void			rr(t_stack_elem **list_a, t_stack_elem **list_b);
void			rrr(t_stack_elem **list_a, t_stack_elem **list_b);

t_stack_elem	*find_min(t_stack_elem *stack);
t_stack_elem	*find_max(t_stack_elem *stack);
t_stack_elem	*find_last_elem(t_stack_elem *stack);

t_stack_elem	*ft_lstlast(t_stack_elem *lst);
int				ft_lstsize(t_stack_elem *lst);

void			error_out(t_stack_elem **stack_a);
int				has_duplicate(t_stack_elem *stack_a, int num);
t_stack_elem	*fetch_cheapest(t_stack_elem *stack);

void			init_b_to_a(t_stack_elem *stack_a, t_stack_elem *stack_b);
void			move_b_to_a(t_stack_elem **stack_a, t_stack_elem **stack_b);

void			rotate_both(t_stack_elem **stack_a, t_stack_elem **stack_b,
					t_stack_elem *cheapest_to_push);
void			rev_rotate_both(t_stack_elem **stack_a, t_stack_elem **stack_b,
					t_stack_elem *cheapest_to_push);

char			**split(char *s, char c);

#endif
