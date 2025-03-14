/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hvahib <hvahib@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 15:13:01 by havhib            #+#    #+#             */
/*   Updated: 2025/03/03 13:16:59 by hvahib           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_array(char **arr, int size)
{
	int	i;

	i = 0;
	while (size >= 0)
		free(arr[size--]);
	free(arr);
}

void	*ft_calloc(size_t num, size_t size)
{
	char	*s;
	int		len;
	int		i;

	len = num * size;
	s = (char *)malloc(len);
	if (s == NULL)
		return (NULL);
	i = 0;
	while (i < len)
	{
		s[i] = 0;
		i++;
	}
	return ((void *)s);
}
