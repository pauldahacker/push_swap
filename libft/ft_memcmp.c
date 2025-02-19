/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pde-masc <pde-masc@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/15 16:21:49 by pde-masc          #+#    #+#             */
/*   Updated: 2023/09/18 15:28:07 by pde-masc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char	*s1_copy;
	unsigned char	*s2_copy;

	s1_copy = (unsigned char *)s1;
	s2_copy = (unsigned char *)s2;
	if (n == 0)
		return (0);
	while (n > 1)
	{
		if (*s1_copy != *s2_copy)
			return (*s1_copy - *s2_copy);
		--n;
		++s1_copy;
		++s2_copy;
	}
	return (*s1_copy - *s2_copy);
}
