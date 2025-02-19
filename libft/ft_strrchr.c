/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pde-masc <pde-masc@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/14 14:45:36 by pde-masc          #+#    #+#             */
/*   Updated: 2023/10/02 12:54:39 by pde-masc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *str, int c)
{
	int	len;

	if (!str)
		return (NULL);
	len = ft_strlen(str);
	while (*str)
		++str;
	if ((char)c == '\0')
		return ((char *)str);
	--str;
	while (len)
	{
		if (*str == (char)c)
			return ((char *)str);
		--str;
		--len;
	}
	return (NULL);
}
