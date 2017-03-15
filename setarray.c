/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setarray.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyoung <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/15 13:52:41 by lyoung            #+#    #+#             */
/*   Updated: 2017/03/15 15:34:14 by lyoung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include <stdio.h>

int		count_tetriminos(int fd)
{
	int		count;
	char	buff[21];

	count = 0;
	while (read(fd, &buff, 21))
		count++;
	return (count);
}

char	***set_3D_array(int count)
{
	char	***array;
	int		i;
	int		y;

	array = (char***)malloc(count * sizeof(array));
	i = 0;
	while (i < count)
	{
		array[i] = (char**)malloc(4);
		y = 0;
		while (y < 4)
		{
			array[i][y] = (char*)malloc(4);
			y++;
		}
		i++;
	}
	return (array);
}

void	fill_array(int fd, char ***array)
{
	int		i;
	int		y;
	int		x;
	char	*buff;

	i = 0;
	while (read(fd, &buff, 1))
	{
		y = 0;

		i++;
	}
}

int		main(int argc, char **argv)
{
	int		count;
	int		fd;

	(void)argc;
	fd = open(argv[1], O_RDONLY, S_IRUSR);
	count = count_tetriminos(fd);
	printf("# of tetriminos: %d\n", count);
	fill_array(fd, set_3D_array(count));
	return (0);
}
