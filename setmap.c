/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setmap.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyoung <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/17 10:49:20 by lyoung            #+#    #+#             */
/*   Updated: 2017/03/17 11:44:59 by lyoung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include <stdio.h>

int		count_tetriminos(char *file)
{
	int		fd;
	int		bytes;
	char	buff[545];

	fd = open(file, O_RDONLY, S_IRUSR);
	bytes = read(fd, &buff, 545);
	close(fd);
	return (bytes / 20);
}

void	fill_map(char *file, char ***map, int count)
{
	int		i;
	int		fd;
	char	buff[21];

	i = 0;
	fd = open(file, O_RDONLY, S_IRUSR);
	while (i < count)
	{
		read(fd, &buff, 21);
		map[i] = ft_strsplit(buff, '\n');
		i++;
	}
}

int		main(int argc, char **argv)
{
	int		count;
	char	***map;
	int		i;
	int		j;

	if (argc != 2)
	{
		printf("Invalid number of arguments.\n");
		return (0);
	}
	count = count_tetriminos(argv[1]);
	printf("# of tetriminos: %d\n", count);
	map = (char***)malloc((count * sizeof(map)) + 1);
	map[count] = NULL;
	fill_map(argv[1], map, count);
	i = 0;
	while (map[i])
	{
		j = 0;
		printf("tetrimino #%d\n", (i + 1));
		while (j < 4)
		{
			printf("%s\n", map[i][j]);
			j++;
		}
		i++;
	}
	return (0);
}
