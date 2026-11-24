/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoalami <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/08 18:15:09 by hoalami           #+#    #+#             */
/*   Updated: 2026/11/08 18:15:20 by hoalami          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char	*copy;
	size_t	len;

	len = ft_strlen(s1);
	copy = malloc(len + 1);
	if (!copy)
		return (NULL);
	ft_memcpy(copy, s1, len + 1);
	return (copy);
}
