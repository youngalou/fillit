/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyoung <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/23 15:40:24 by lyoung            #+#    #+#             */
/*   Updated: 2017/04/14 12:37:39 by lyoung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		main(int argc, char **argv)
{
	int		size;
	char	**map;

	if (argc != 2)
	{
		ft_putstr("usage: ./fillit [source_file]\n");
		return (0);
	}
	if (ft_maincheck(ft_getstr(argv[1])) == 0)
	{
		ft_putstr("error\n");
		return (0);
	}
	map = set_letter(isolate_tet(set_array(ft_getstr(argv[1]))));
	size = min_square_size(count_tets(argv[1]));
	find_solution(map, size);
	return (0);
}
