/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hvahib <hvahib@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 22:58:01 by hvahib            #+#    #+#             */
/*   Updated: 2025/03/03 13:25:41 by hvahib           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	stack_errors(t_stack_elem **stack_a,
						char **argv,
						int *splitted_times)
{
	clear_stack(stack_a);
	if (*splitted_times)
		free_array(argv, *splitted_times);
	ft_putendl_fd("Error", 2);
	exit(1);
}

static void	process_stack(char **argv, int *splitted_times)
{
	t_stack_elem	*stack_a;
	t_stack_elem	*stack_b;
	int				init_result;

	stack_a = NULL;
	stack_b = NULL;
	init_result = init_stack_a(&stack_a, argv + 1);
	if (init_result != 0)
		stack_errors(&stack_a, argv, splitted_times);
	if (!is_sorted(stack_a))
	{
		if (stack_size(stack_a) == 2)
			sa(&stack_a, 1);
		else if (stack_size(stack_a) == 3)
			sort_three(&stack_a);
		else
			sort_stacks(&stack_a, &stack_b);
	}
	clear_stack(&stack_a);
	if (*splitted_times)
		free_array(argv, *splitted_times);
}

int	main(int argc, char **argv)
{
	int	splitted_times;

	splitted_times = 0;
	if (argc == 1)
		return (1);
	if (argc == 2 && !argv[1][0])
		return (error_out(NULL), 1);
	else if (argc == 2)
	{
		splitted_times = count_words(argv[1], ' ');
		argv = split(argv[1], ' ');
		if (!argv)
		{
			error_out(NULL);
			exit(1);
		}
	}
	process_stack(argv, &splitted_times);
	return (0);
}
