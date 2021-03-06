/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emlecerf <emlecerf@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/03 10:51:59 by emlecerf          #+#    #+#             */
/*   Updated: 2020/12/16 14:42:52 by emlecerf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static int	last_line(char **line, char **buffer)
{
	if (*buffer)
		*line = *buffer;
	else
	{
		if (!(*line = malloc(sizeof(char) * 1)))
			return (0);
		*line[0] = '\0';
	}
	*buffer = NULL;
	return (1);
}

int			get_next_line(int fd, char **line)
{
	static char	*buffer;
	char		bf_tmp[BUFFER_SIZE + 1];
	int			nbytes;
	int			nl;

	if (fd < 0 || read(fd, bf_tmp, 0) || !line || BUFFER_SIZE <= 0)
		return (-1);
	while (((nl = ft_strchr(buffer)) == -1) &&
		(nbytes = read(fd, bf_tmp, BUFFER_SIZE)))
	{
		bf_tmp[nbytes] = '\0';
		if (!(buffer = ft_strjoin(buffer, bf_tmp)))
			return (-1);
	}
	if (nl != -1)
	{
		*line = ft_substr(buffer, 0, nl, 0);
		buffer = ft_substr(buffer, (nl + 1), (ft_strlen(buffer) - nl), 1);
		return (1);
	}
	if (!(last_line(line, &buffer)))
		return (-1);
	return (0);
}
