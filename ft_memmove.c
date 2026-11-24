/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoalami <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/29 16:13:24 by hoalami           #+#    #+#             */
/*   Updated: 2026/10/29 17:45:13 by hoalami          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char		*d;
	const unsigned char	*s;
	size_t				x;

	d = (unsigned char *)dest;
	s = (const unsigned char *)src;
	x = n;
	if (n == 0 || dest == src)
		return (dest);
	if ((uintptr_t)dest > (uintptr_t)src)
	{
		while (x > 0)
		{
			x--;
			d[x] = s[x];
		}
	}
	else
		ft_memcpy(dest, src, n);
	return (dest);
}
