/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setarray.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyoung <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/15 13:52:41 by lyoung            #+#    #+#             */
/*   Updated: 2017/03/16 13:38:05 by lyoung           ###   ########.fr       */
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
//	int		i;
//	int		y;

	array = (char***)malloc(count * (sizeof(char**) + 1));
/*	i = 0;
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
	}*/
	array[count] = 0;
	return (array);
}

void	fill_array(int fd, int count, char ***array)
{
	char	*buff;
	int		i;

	i = 0;
	while (count > 0)
	{
		printf("count = %d\n", count);
		read(fd, &buff, 21);
		printf("%s", buff);
//		*array = ft_strsplit(buff, '\n');
		array++;
		count--;
	}
}

int		main(int argc, char **argv)
{
	int		count;
	int		fd;
	int		i;
	int		j;
	char	***array;

	if (argc != 2)
	{
		printf("Invalid number of arguments.\n");
		return (0);
	}
	fd = open(argv[1], O_RDONLY, S_IRUSR);
	count = count_tetriminos(fd);
	printf("# of tetriminos: %d\n", count);
	array = set_3D_array(count);
	close(fd);
	fd = open(argv[1], O_RDONLY, S_IRUSR);
	fill_array(fd, count, array);
	/**
	i = -1;
	while (++i < 4)
	{
		j = -1;
		while (++j < 4)
			printf("%s\n", array[i][j]);
	}
	**/
	return (0);
}
