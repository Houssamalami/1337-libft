/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoalami <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/08 20:25:37 by hoalami           #+#    #+#             */
/*   Updated: 2026/11/08 20:31:29 by hoalami          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	start;
	size_t	end;
	char	*trimmed;

	if (s1 == NULL)
		return (NULL);
	if (set == NULL)
		return (ft_strdup(s1));
	start = 0;
	while (s1[start]
		&& ft_memchr(set, s1[start], ft_strlen(set)) != NULL)
		start++;
	end = ft_strlen(s1);
	while (end > start
		&& ft_memchr(set, s1[end - 1], ft_strlen(set)) != NULL)
		end--;
	trimmed = malloc(end - start + 1);
	if (trimmed == NULL)
		return (NULL);
	ft_memcpy(trimmed, &s1[start], end - start);
	trimmed[end - start] = '\0';
	return (trimmed);
}
