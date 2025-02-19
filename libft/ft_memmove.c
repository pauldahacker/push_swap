/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pde-masc <pde-masc@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/14 13:20:02 by pde-masc          #+#    #+#             */
/*   Updated: 2023/09/18 13:03:02 by pde-masc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t n)
{
	unsigned char	*d;
	unsigned char	*s;
	size_t			i;

	d = (unsigned char *)dst;
	s = (unsigned char *)src;
	i = 0;
	if (!dst && !src)
		return (NULL);
	if (d < s)
	{
		while (i < n)
		{
			d[i] = s[i];
			++i;
		}
	}
	else if (s < d)
	{
		while (n-- > 0)
			d[n] = s[n];
	}
	return (dst);
}
