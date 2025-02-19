/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pde-masc <pde-masc@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/18 16:05:18 by pde-masc          #+#    #+#             */
/*   Updated: 2023/10/02 12:41:36 by pde-masc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*res;
	size_t	len1;
	size_t	len2;

	if (!s1 || !s2)
		return (NULL);
	len1 = ft_strlen((char *)s1);
	len2 = ft_strlen((char *)s2);
	res = malloc((len1 + len2) * sizeof(char) + 1);
	if (!res)
		return (NULL);
	ft_strlcpy(res, (char *)s1, len1 + 1);
	ft_strlcat(res, (char *)s2, len1 + len2 + 1);
	return (res);
}
