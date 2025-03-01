/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hvahib <hvahib@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 15:13:01 by havhib            #+#    #+#             */
/*   Updated: 2025/02/27 17:30:15 by hvahib           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_array(char **arr, int size)
{
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
