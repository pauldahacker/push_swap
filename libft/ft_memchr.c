/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pde-masc <pde-masc@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/15 14:47:04 by pde-masc          #+#    #+#             */
/*   Updated: 2023/09/18 17:35:08 by pde-masc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *str, int c, size_t n)
{
	unsigned char	*s;
	unsigned char	c1;

	s = (unsigned char *)str;
	c1 = (unsigned char)c;
	while (n > 0)
	{
		if (*s == c1)
			return (s);
		++s;
		--n;
	}
	return (NULL);
}
