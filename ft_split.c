/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muakbas <muakbas@student.42kocaeli.com.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/06 10:41:49 by muakbas           #+#    #+#             */
/*   Updated: 2025/07/06 10:41:49 by muakbas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static int	word_count(const char *s, char delim)
{
	int count = 0;
	int in_word = 0;

	while (*s)
	{
		if (*s != delim && !in_word)
		{
			in_word = 1;
			count++;
		}
		else if (*s == delim)
			in_word = 0;
		s++;
	}
	return (count);
}

static char	*copy_word(const char *start, size_t len)
{
	char *word = malloc(len + 1);
	if (!word)
		return (NULL);
	ft_strlcpy(word, start, len + 1);
	return (word);
}

static void	free_all(char **arr, int filled)
{
	while (filled--)
		free(arr[filled]);
	free(arr);
}

char	**ft_split(char const *s, char c)
{
	char	**result;
	int		i = 0;
	const char *word_start;
	size_t	word_len;

	if (!s)
		return (NULL);
	result = malloc(sizeof(char *) * (word_count(s, c) + 1));
	if (!result)
		return (NULL);

	while (*s)
	{
		if (*s != c)
		{
			word_start = s;
			word_len = 0;
			while (*s && *s != c)
			{
				word_len++;
				s++;
			}
			result[i] = copy_word(word_start, word_len);
			if (!result[i++])
			{
				free_all(result, i - 1);
				return (NULL);
			}
		}
		else
			s++;
	}
	result[i] = NULL;
	return (result);
}
