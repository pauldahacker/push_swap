/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pde-masc <pde-masc@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/14 14:15:18 by pde-masc          #+#    #+#             */
/*   Updated: 2023/09/18 17:19:16 by pde-masc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t	pos;
	size_t	dstlen;
	size_t	i;

	pos = ft_strlen(dest);
	dstlen = pos;
	i = 0;
	if (size <= dstlen)
		return (ft_strlen(src) + size);
	while (src[i] && i < size - dstlen - 1)
	{
		dest[pos] = src[i];
		++pos;
		++i;
	}
	dest[pos] = '\0';
	return (dstlen + ft_strlen(src));
}
