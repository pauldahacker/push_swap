/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pde-masc <pde-masc@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 17:40:00 by pde-masc          #+#    #+#             */
/*   Updated: 2023/09/26 14:31:53 by pde-masc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	getlen(char const *s, char c)
{
	size_t	i;
	int		is_word;

	i = 0;
	is_word = 0;
	while (*s)
	{
		if (*s == c && is_word)
			is_word = !is_word;
		if (*s != c && !is_word)
		{
			++i;
			is_word = !is_word;
		}
		++s;
	}
	return (i);
}

static size_t	getcurrentlen(char const *s, char c)
{
	size_t	i;

	i = 0;
	while (s[i])
	{
		if (s[i] == c)
			return (i);
		++i;
	}
	return (i);
}

static char	**destroy(char **arr)
{
	int	i;

	i = 0;
	while (arr[i])
	{
		free(arr[i]);
		++i;
	}
	free(arr);
	return (NULL);
}

char	**ft_split(char const *s, char c)
{
	char			**split;
	size_t			i;

	if (!s)
		return (NULL);
	split = (char **)malloc((getlen(s, c) + 1) * sizeof(char *));
	if (!split)
		return (NULL);
	i = 0;
	while (*s)
	{
		while (*s && *s == c)
			++s;
		if (!*s)
			break ;
		split[i] = (char *)malloc((getcurrentlen(s, c) + 1) * sizeof(char));
		if (!split[i])
			return (destroy(split));
		ft_strlcpy(split[i], s, getcurrentlen(s, c) + 1);
		s += getcurrentlen(s, c);
		++i;
	}
	split[i] = NULL;
	return (split);
}
