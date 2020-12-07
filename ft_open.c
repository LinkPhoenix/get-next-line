/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_open.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emlecerf <emlecerf@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/04 11:28:58 by emlecerf          #+#    #+#             */
/*   Updated: 2020/12/05 21:08:22 by emlecerf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <stdio.h>

int	main(int agrc, char **argv)
{
	printf("OPEN : %d\n", open("*.txt", O_RDONLY));
	return (0);
}
