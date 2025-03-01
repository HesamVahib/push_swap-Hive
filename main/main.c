/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hvahib <hvahib@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 22:58:01 by hvahib            #+#    #+#             */
/*   Updated: 2025/03/01 18:33:49 by hvahib           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	process_stack(char **argv, int *splitted_times)
{
	t_stack_elem	*stack_a;
	t_stack_elem	*stack_b;

	stack_a = NULL;
	stack_b = NULL;
	init_stack_a(&stack_a, argv + 1);
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
	if (argc == 1 || (argc == 2 && !argv[1][0]))
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
