/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   splitting.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hvahib <hvahib@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 20:30:07 by hvahib            #+#    #+#             */
/*   Updated: 2025/03/01 18:36:06 by hvahib           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	count_words(char *s, char c)
{
	int		count;
	int		inside_word;

	count = 0;
	while (*s)
	{
		inside_word = 0;
		while (*s == c)
			++s;
		while (*s != c && *s)
		{
			if (!inside_word)
			{
				++count;
				inside_word = 1;
			}
			++s;
		}
	}
	return (count);
}

static char	*get_next_word(char *s, char c)
{
	static int	cursor = 0;
	char		*next_word;
	int			len;
	int			i;

	len = 0;
	i = 0;
	while (s[cursor] == c)
		++cursor;
	while ((s[cursor + len] != c) && s[cursor + len])
		++len;
	next_word = (char *)ft_calloc(len + 1, sizeof(char));
	if (!next_word)
		return (NULL);
	while ((s[cursor] != c) && s[cursor])
		next_word[i++] = s[cursor++];
	return (next_word);
}

char	**allocate_split_array(char *s, char c)
{
	int		words_count;
	char	**result_array;

	words_count = count_words(s, c);
	if (!words_count)
		exit(1);
	result_array = (char **)ft_calloc(words_count + 2, sizeof(char *));
	if (!result_array)
		return (NULL);
	result_array[0] = (char *)ft_calloc(1, sizeof(char));
	if (!result_array[0])
		return (free(result_array), NULL);
	return (result_array);
}

char	**fill_split_array(char *s, char c, char **result_array)
{
	int	i;
	int	words_count;

	i = 1;
	words_count = count_words(s, c);
	while (words_count-- > 0)
	{
		result_array[i] = get_next_word(s, c);
		if (!result_array[i])
		{
			free_array(result_array, i - 1);
			return (NULL);
		}
		i++;
	}
	result_array[i] = NULL;
	return (result_array);
}

char	**split(char *s, char c)
{
	char	**result_array;

	result_array = allocate_split_array(s, c);
	if (!result_array)
		return (NULL);
	return (fill_split_array(s, c, result_array));
}
