/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyoung <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/21 12:12:00 by lyoung            #+#    #+#             */
/*   Updated: 2017/03/23 11:24:56 by lyoung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

char	**set_min_square(int count)
{
	char	**square;
	int		i;

	square = (char**)malloc(sizeof(square) * (count + 1));
	i = 0;
	while (i <= count)
	{
		square[i] = (char*)malloc(sizeof(char*) * (count + 1));
		i++;
	}
	return (square);
}

char	**trim_tet_x(char **map)
{
	int		y;
	int		x;
	int		dot;

	y = 0;
	while (y < 4)
	{
		x = 0;
		dot = 0;
		while (x < 4)
		{
			if (map[y][x] == '.')
				dot++;
			x++;
		}
		if (dot == 4)
			bzero(map[y], 4);
		y++;
	}
	return (map);
}

char	**trim_tet_y(char **map)
{
	int		x;
	int		y;
	int		dot;

	x = 0;
	while (x < 4)
	{
		y = 0;
		dot = 0;
		while (y < 4)
		{
			if (map[y][x] == '.')
				dot++;
			y++;
		}
		if (dot == 4)
		{
			y = 0;
			while (y < 4)
			{
				map[y][x] = '0';
				y++;
			}
		}
		x++;
	}
	return (map);
}

void	place_tet(char **square, char **map)
{
	int		x;
	int		y;
	int		i;
	int		j;

	x = 0;
	while (x < 4)
	{
		y = 0;
		while (y < 4)
		{
			if (map[y][x] == '#')
			{
				square[i][j] = map[y][x];
			}
			y++;
		}
		x++;
	}
}
