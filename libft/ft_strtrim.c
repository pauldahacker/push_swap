/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pde-masc <pde-masc@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 14:17:31 by pde-masc          #+#    #+#             */
/*   Updated: 2023/10/02 12:56:58 by pde-masc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	is_in(int c, char const *set)
{
	while (*set)
	{
		if ((char)c == *set)
			return (1);
		++set;
	}
	return (0);
}

static unsigned int	startpos(char const *s1, char const *set)
{
	unsigned int	start;

	start = 0;
	while (*s1)
	{
		if (!is_in(*s1, set))
			return (start);
		++s1;
		++start;
	}
	return (start);
}

static size_t	tlen(char const *s1, char const *set)
{
	unsigned int	start;
	size_t			end;

	start = startpos(s1, set);
	end = ft_strlen(s1);
	s1 += (end - 1);
	while (end > 0)
	{
		if (!is_in(*s1, set))
			return (end - (size_t)start);
		--s1;
		--end;
	}
	if (end <= (size_t)start)
		return (0);
	return (end - (size_t)start);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	unsigned int	start;
	size_t			len;

	if (!s1)
		return (NULL);
	if (!set)
		return ((char *)s1);
	start = startpos(s1, set);
	len = tlen(s1, set);
	return (ft_substr(s1, start, len));
}
