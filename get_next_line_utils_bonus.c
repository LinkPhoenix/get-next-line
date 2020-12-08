/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emlecerf <emlecerf@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/03 10:52:25 by emlecerf          #+#    #+#             */
/*   Updated: 2020/12/03 10:52:26 by emlecerf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_strlen(char *str)
{
	int i;

	i = 0;
	while (str && str[i])
		i++;
	return (i);
}

char	*ft_strjoin(char *s1, char *s2)
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
	if (s1)
		free(s1);
	return (tab);
}

char		*ft_substr(char *s, unsigned int start, int len, int f)
{
	char	*tab;
	int	i;

	i = 0;
	if (!s)
		return (NULL);
	if (!(tab = malloc(sizeof(char) * (len + 1))))
		return (NULL);
	while (s[start] && i < len)
		tab[i++] = s[start++];
	tab[i] = '\0';
	if (f)
		free(s);
	return (tab);
}

int	ft_strchr(char *str)
{
	int i;

	i = -1;
	while (str && str[++i])
		if (str[i] == '\n')
			return (i);
	return (-1);
}
