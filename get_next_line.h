/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emlecerf <emlecerf@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/03 10:52:30 by emlecerf          #+#    #+#             */
/*   Updated: 2020/12/16 14:34:22 by emlecerf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <sys/types.h>
# include <sys/uio.h>
# include <unistd.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

int			get_next_line(int fd, char **line);
int			ft_strlen(char *str);
char		*ft_strjoin(char *s1, char *s2);
char		*ft_substr(char *s, unsigned int start, int len, int f);
int			ft_strchr(char *str);

#endif
