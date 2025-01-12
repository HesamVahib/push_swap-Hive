#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdbool.h>
# include <limits.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_stack_elem
{
    int                value;
    int                index;
    int                push_cost;
    bool               above_median;
    bool               cheapest;
    struct s_stack_elem *target_elem;
    struct s_stack_elem *next;
    struct s_stack_elem *prev;
}	t_stack_elem;

void	ft_putendl_fd(char *s, int fd);


void    current_index_median(t_stack_elem *stack);
// static void set_target_a(t_stack_elem *stack_a, t_stack_elem *stack_b);
// static void cost_to_push_a(t_stack_elem *stack_a, t_stack_elem *stack_b);
void    find_cheapest(t_stack_elem  *stack);
void    init_elems_a(t_stack_elem *stack_a, t_stack_elem *stack_b);
// static void set_target_b(t_stack_elem *stack_a, t_stack_elem *stack_b);
// static void move_a_to_b(t_stack_elem **stack_a, t_stack_elem **stack_b);
// static void move_b_to_a(t_stack_elem **stack_a, t_stack_elem **stack_b);
void    sort_stacks(t_stack_elem **stack_a, t_stack_elem **stack_b);
// static void min_on_top(t_stack_elem **stack_a);
t_stack_elem    *find_biggest_one(t_stack_elem *stack);
void    sort_three(t_stack_elem **stack);
char **ft_split(char const *s, char c);
int	ft_atoi(const char *str);
void init_stack_a(t_stack_elem **stack_a, char **argv);
int    is_sorted(t_stack_elem *stack);
int stack_size(t_stack_elem *stack);
void free_stack(t_stack_elem **stack);

void	sa(t_stack_elem **list_a);
void	pa(t_stack_elem **list_a, t_stack_elem **list_b);
void	ra(t_stack_elem **list_a);
void	rra(t_stack_elem **list_a);

void	sb(t_stack_elem **list_b);
void	pb(t_stack_elem **list_b, t_stack_elem **list_a);
void	rb(t_stack_elem **list_b);
void	rrb(t_stack_elem **list_b);

void	ss(t_stack_elem **list_a, t_stack_elem **list_b);
void	rr(t_stack_elem **list_a, t_stack_elem **list_b);
void	rrr(t_stack_elem **list_a, t_stack_elem **list_b);

t_stack_elem *find_min(t_stack_elem *stack);
t_stack_elem *find_max(t_stack_elem *stack);
t_stack_elem *find_last_elem(t_stack_elem *stack);

t_stack_elem	*ft_lstlast(t_stack_elem *lst);
int	ft_lstsize(t_stack_elem *lst);

void    error_out(t_stack_elem **stack_a);
int is_duplicated(t_stack_elem *stack_a, int num);

#endif
