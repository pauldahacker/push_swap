/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pde-masc <pde-masc@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/14 15:50:24 by pde-masc          #+#    #+#             */
/*   Updated: 2023/09/18 13:07:11 by pde-masc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	const char	*h;
	const char	*n;
	size_t		i;

	if (!*needle)
		return ((char *)haystack);
	while (*haystack && len > 0)
	{
		h = haystack;
		n = needle;
		i = len;
		while (*h && *n && *h == *n)
		{
			if (i == 0)
				return (NULL);
			++h;
			++n;
			--i;
		}
		if (!*n)
			return ((char *)haystack);
		++haystack;
		--len;
	}
	return (NULL);
}
