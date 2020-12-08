/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emlecerf <emlecerf@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/03 10:51:59 by emlecerf          #+#    #+#             */
/*   Updated: 2020/12/07 19:40:11 by emlecerf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int			get_next_line(int fd, char **line)
{
	static char	*buffer[FD_MAX];
	char		bf_tmp[BUFFER_SIZE + 1];
	int			i;
	int			nl;

	if (fd < 0 || read(fd, bf_tmp, 0))
		return (-1);
	while (((nl = ft_strchr(&buffer[FD_MAX])) == -1) &&
		(i = read(fd, bf_tmp, BUFFER_SIZE)))
	{
		bf_tmp[i] = '\0';
		if (!(&buffer[FD_MAX] = ft_strjoin(&buffer[fd], bf_tmp)))
			return (-1);
	}
	if (nl != -1)
	{
		*line = ft_substr(&buffer[FD_MAX], 0, nl, 0);
		&buffer[FD_MAX] = ft_substr(&buffer[FD_MAX], (nl + 1),
			(ft_strlen(&buffer[FD_MAX]) - nl), 1);
		return (1);
	}
	*line = &buffer[fd];
	return (0);
}
