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
