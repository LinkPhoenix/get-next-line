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

#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/uio.h>
#include <unistd.h>
#include <fcntl.h>
#ifndef BUFFER_SIZE
#define BUFFER_SIZE 42
#endif

static int	ft_strlen(const char *str)
{
	int i;

	i = 0;
	while (str && str[i])
		i++;
	return (i);
}

static char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*tab;
	int		tab_len;
	int		i;
	int		j;

	i = 0;
	j = 0;
	tab_len = ft_strlen(s1) + ft_strlen(s2) + 1;
	if (!(tab = (char *)malloc(sizeof(char) * tab_len)))
		return (NULL);
	while (s1 && s1[j])
		tab[i++] = s1[j++];
	j = 0;
	while (s2[j])
		tab[i++] = s2[j++];
	tab[i] = 0;
	return (tab);
}

static int	len_max(const char *str)
{
	int i;

	i = -1;
	while (str[++i])
		if (str[i] == '\n')
			return(i);
	return (i);
}

char		*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*tab;
	size_t	i;

	i = 0;
	if (!s)
		return (NULL);
	if (!(tab = malloc(sizeof(char) * (len + 1))))
		return (NULL);
	while (s[start] && i < len)
		tab[i++] = s[start++];
	tab[i] = '\0';
	return (tab);
}

int			get_next_line(int fd, char **line)
{
	static char	*buffer;
	char		bf_tmp[BUFFER_SIZE + 1];
	int			i;
	int			nl;

	if (fd < 0)
		return (-1);
// IF BUFFER_SIZE is little (ex:2) I need "while" for read
// all the line	
	while ((i = read(fd, bf_tmp, BUFFER_SIZE)))
	{
		if (i == 0)
		{
			printf("i = 0\n");
			return (0);
		}
		bf_tmp[i] = '\0';
		if (!(buffer = ft_strjoin(buffer, bf_tmp)))
			return (-1);
	}
	nl = len_max(buffer);
	*line = ft_substr(buffer, 0, nl);
	buffer = ft_substr(buffer, (nl + 1), (ft_strlen(buffer) - nl));
	if (*line[0] == '\0')
		return (0);
	return (1);
}

int			main(int argc, char **argv)
{
	(void)argc;
	int fd = open(argv[1], O_RDONLY);
	char *line;

	printf("FILE DESCRIPTOR : %d\n", fd);
	// int i = 0;
	// while (++i < 10)
	while (get_next_line(fd, &line))
	{
		get_next_line(fd, &line);
		printf("LINE : %s\n", line);
	}
	free(line);
	close(fd);
}
