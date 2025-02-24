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

char	*getbufferline(char *s)
{
	char	*ret;
	int		i;

	if (!s)
		return (NULL);
	i = 0;
	while (s[i])
	{
		if (s[i++] == NEWLINE)
			break ;
	}
	ret = malloc((i + 1) * sizeof(char));
	if (!ret)
		return (NULL);
	ret[i] = 0;
	while (--i >= 0)
		ret[i] = s[i];
	return (ret);
}

int	myread(int fd, char *buf)
{
	int	readbytes;

	if (!buf)
		return (-1);
	readbytes = read(fd, buf, BUFFER_SIZE);
	if (readbytes >= 0)
		buf[readbytes] = 0;
	return (readbytes);
}

char	*destroy(char **s)
{
	free(*s);
	*s = NULL;
	return (NULL);
}

char	*assemble(int fd, char *buf, int readbytes)
{
	char	*current;
	char	*joined;

	current = getbufferline(buf);
	if (!current)
		return (NULL);
	joined = ft_strdup(current);
	if (!joined)
		return (destroy(&current));
	while (!ft_strchr(joined, NEWLINE) && readbytes)
	{
		destroy(&current);
		readbytes = myread(fd, buf);
		if (readbytes == -1)
			return (destroy(&joined));
		current = getbufferline(buf);
		if (!current)
			return (destroy(&joined));
		joined = ft_strjoin(joined, current);
		if (!joined)
			return (destroy(&current));
	}
	destroy(&current);
	return (joined);
}