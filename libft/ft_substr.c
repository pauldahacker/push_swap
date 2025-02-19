/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pde-masc <pde-masc@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/22 15:42:03 by pde-masc          #+#    #+#             */
/*   Updated: 2023/10/02 12:46:53 by pde-masc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*sub;
	size_t	sublen;
	size_t	slen;

	if (!s)
		return (NULL);
	slen = ft_strlen((char *)s);
	if (start >= (unsigned int)slen)
		sublen = 0;
	else if ((unsigned int)slen - (unsigned int)start >= (unsigned int)len)
		sublen = len;
	else
		sublen = slen - start;
	sub = (char *)malloc((sublen + 1) * sizeof(char));
	if (!sub)
		return (NULL);
	if (slen <= start)
		ft_bzero(sub, sublen + 1);
	else
		ft_strlcpy(sub, s + start, sublen + 1);
	return (sub);
}
