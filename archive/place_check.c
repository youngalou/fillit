/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyoung <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/23 15:40:24 by lyoung            #+#    #+#             */
/*   Updated: 2017/03/24 11:54:24 by lyoung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include <stdio.h>

int		main(int argc, char **argv)
{
	int		i;
	int		size;
	char	**map;
	char	**square;
	int		y;
	int		x;

	if (argc != 2)
	{
		ft_putstr("usage: ./fillit source_file\n");
		return (0);
	}
	map = set_letter(isolate_tet(set_array(ft_getstr(argv[1]))));
	i = 0;
	while (map[i])
	{
		ft_putstr(map[i]);
		ft_putchar('\n');
		i++;
	}
	ft_putstr("---------------------\n");
	size = min_square_size(count_tets(argv[1]));
	square = new_square(size);
	y = 0;
	while (y < 5)
	{
		x = 0;
		while (x < 5)
		{
			if (check_place(square, map[2], y, x))
			{
				printf("x = %d, y = %d\n", x, y);
				place_tet(square, map[2], y, x);
				print_square(square, size);
				ft_putstr("---------------------\n");
				reset_square(square);
			}
			x++;
		}
		y++;
	}
	return (0);
}
