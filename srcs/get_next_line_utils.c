/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pde-masc <pde-masc@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 13:18:34 by pde-masc          #+#    #+#             */
/*   Updated: 2023/10/31 11:44:06 by pde-masc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

size_t	ft_strlen(const char *s)
{
	if (!*s)
		return (0);
	return (1 + ft_strlen(s + 1));
}

char	*tochr(char *s, int c)
{
	char	*ret;
	int		i;
	int		j;

	if (!s)
		return (NULL);
	if (!ft_strchr(s, c))
		return (destroy(&s));
	i = 0;
	while ((s)[i++] != c)
	{
	}
	if (!(s)[i])
		return (destroy(&s));
	ret = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!ret)
		return (destroy(&s));
	j = 0;
	while ((s)[i])
		ret[j++] = (s)[i++];
	while (j <= BUFFER_SIZE)
		ret[j++] = 0;
	destroy(&s);
	return (ret);
}

char	*ft_strdup(const char *s1)
{
	char	*d;
	char	*p_s1;
	size_t	i;

	p_s1 = (char *)s1;
	i = 0;
	d = (char *)malloc(ft_strlen(p_s1) + 1);
	if (d == NULL)
		return (NULL);
	while (p_s1[i] != '\0')
	{
		d[i] = p_s1[i];
		i++;
	}
	d[i] = '\0';
	return (d);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*str;
	int		a;
	int		b;
	int		i;

	if (!s1 || !s2)
		return (NULL);
	a = ft_strlen(s1);
	b = ft_strlen(s2);
	i = 0;
	str = malloc((a + b + 1) * sizeof(char));
	if (!str)
		return (destroy(&s1));
	while (a--)
	{
		str[i] = s1[i];
		i++;
	}
	a = i;
	i = 0;
	while (b--)
		str[a++] = s2[i++];
	str[a] = '\0';
	destroy(&s1);
	return (str);
}

char	*ft_strchr(const char *str, int c)
{
	int	i;

	i = 0;
	while (((char *)str)[i] != '\0')
	{
		if (((char *)str)[i] == c)
			return ((char *)&str[i]);
		i++;
	}
	if (c == '\0')
		return ((char *)&str[i]);
	return (NULL);
}
