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
	return (bytes / 20); // fix so that you are dividing by 21
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

	square = (char**)malloc(sizeof(square) * (size + 4));
	i = 0;
	while (i < size + 3)
	{
		square[i] = (char*)malloc(sizeof(*square) * (size + 3));
		ft_bzero(square[i], size + 3);
		i++;
	}
	square[i] = 0;
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

void	delete_square(char **square)
{
	int		i;

	i = 0;
	while (square[i])
	{
		free(square[i]);
		i++;
	}
	free(square);
}

void	reset_square(char **square)
{
	int		i;
	int		j;
	
	i = 0;
	while (i < 5)
	{
		j = 0;
		while (j < 5)
		{
			if (square[i][j] != '\0')
				square[i][j] = '.';
			j++;
		}
		i++;
	}
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
