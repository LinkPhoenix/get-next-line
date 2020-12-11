/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emlecerf <emlecerf@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/03 10:51:59 by emlecerf          #+#    #+#             */
/*   Updated: 2020/12/11 11:21:18 by emlecerf         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

int			get_next_line(int fd, char **line)
{
	static char	*buffer[OPEN_MAX];
	char		bf_tmp[BUFFER_SIZE + 1];
	int			bread;
	int			nl;

	if (fd < 0 || read(fd, bf_tmp, 0) || !line || BUFFER_SIZE <= 0)
		return (-1);
	while (((nl = ft_strchr(buffer[fd])) == -1) &&
		(bread = read(fd, bf_tmp, BUFFER_SIZE)))
	{
		bf_tmp[bread] = '\0';
		if (!(buffer[fd] = ft_strjoin(buffer[fd], bf_tmp)))
			return (-1);
	}
	if (nl != -1)
	{
		*line = ft_substr(buffer[fd], 0, nl, 0);
		buffer[fd] = ft_substr(buffer[fd], (nl + 1),
			(ft_strlen(buffer[fd]) - nl), 1);
		return (1);
	}
	*line = buffer[fd];
	buffer[fd] = malloc(sizeof(char) * 1);
	buffer[fd][0] = '\0';
	return (0);
}
