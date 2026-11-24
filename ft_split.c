/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoalami <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/09 17:22:53 by hoalami           #+#    #+#             */
/*   Updated: 2026/11/09 17:28:56 by hoalami          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	count_words(const char *str, char c)
{
	size_t	count;
	size_t	i;

	count = 0;
	i = 0;
	while (str[i])
	{
		while (str[i] && str[i] == c)
			i++;
		if (str[i])
		{
			count++;
			while (str[i] && str[i] != c)
				i++;
		}
	}
	return (count);
}

static void	free_all(char **array, size_t size)
{
	size_t	i;

	i = 0;
	while (i < size)
	{
		free(array[i]);
		i++;
	}
	free(array);
}

static char	**ft_helper(char const *s, char c, char **array)
{
	size_t	i;
	size_t	word;
	size_t	start;

	i = 0;
	word = 0;
	while (s[i])
	{
		while (s[i] && s[i] == c)
			i++;
		if (s[i])
		{
			start = i;
			while (s[i] && s[i] != c)
				i++;
			array[word] = ft_substr(s, start, i - start);
			if (!array[word])
				return (free_all(array, word), NULL);
			word++;
		}
	}
	array[word] = NULL;
	return (array);
}

char	**ft_split(char const *s, char c)
{
	char	**array;

	if (!s)
		return (NULL);
	array = malloc(sizeof(char *) * (count_words(s, c) + 1));
	if (!array)
		return (NULL);
	return (ft_helper(s, c, array));
}
