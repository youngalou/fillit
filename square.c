/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   square.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyoung <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/24 13:49:24 by lyoung            #+#    #+#             */
/*   Updated: 2017/03/24 14:38:12 by lyoung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		count_tets(char *file)
{
	int		fd;
	int		bytes;
	char	buff[545];

	fd = open(file, O_RDONLY, S_IRUSR);
	bytes = read(fd, &buff, 545);
	close(fd);
	return (bytes / 20);
}

int		min_square_size(int nb_tets)
{
	int		min;
	int		area;

	min = 2;
	area = nb_tets * 4;
	while (area > (min * min))
		min++;
	return (min);

}

char	**new_square(int size)
{
	char	**square;
	int		i;
	int		j;

	square = (char**)malloc(sizeof(square) * (size + 3));
	i = 0;
	while (i < size + 3)
	{
		square[i] = (char*)malloc(sizeof(*square) * (size + 3));
		ft_bzero(square[i], size + 3);
		i++;
	}
	i = 0;
	while (i < size)
	{
		j = 0;
		while (j < size)
		{
			square[i][j] = '.';
			j++;
		}
		i++;
	}
	return (square);
}

void	print_square(char **square, int size)
{
	int		i;

	i = 0;
	while (i < size)
	{
		ft_putstr(square[i]);
		ft_putchar('\n');
		i++;
	}
}
