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

int		main(int argc, char **argv)
{
	int		size;

	char	**map;
	if (argc != 2)
	{
		ft_putstr("usage: ./fillit source_file\n");
		return (0);
	}
	map = set_letter(isolate_tet(set_array(ft_getstr(argv[1]))));
	while (*map)
	{
		ft_putstr(*map);
		ft_putchar('\n');
		map++;
	}
	ft_putstr("---------------------\n");
	size = min_square_size(count_tets(argv[1]));
	print_square(new_square(size), size);
	return (0);
}
