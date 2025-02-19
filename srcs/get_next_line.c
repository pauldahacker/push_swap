/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pde-masc <pde-masc@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 13:10:37 by pde-masc          #+#    #+#             */
/*   Updated: 2023/10/31 11:40:47 by pde-masc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

static char	*getbufferline(char *s)
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

static int	myread(int fd, char *buf)
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

static char	*assemble(int fd, char *buf, int readbytes)
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

char	*get_next_line(int fd)
{
	static char	*buf;
	char		*joined;
	int			readbytes;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	readbytes = BYTE_START;
	if (!buf)
	{
		buf = malloc((BUFFER_SIZE + 1) * sizeof(char));
		if (!buf)
			return (NULL);
		readbytes = myread(fd, buf);
		if (readbytes <= 0)
			return (destroy(&buf));
	}
	joined = assemble(fd, buf, readbytes);
	if (!joined)
		return (destroy(&buf));
	buf = tochr(buf, NEWLINE);
	return (joined);
}
