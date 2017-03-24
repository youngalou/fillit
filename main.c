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
	char	**map;
	if (argc != 2)
	{
		ft_putstr("usage: ./fillit source_file\n");
		return (0);
	}
	map = set_array(ft_getstr(argv[1]));
	trim_nl(map);
	isolate_tet(map);
	set_letter(map);
	while (*map)
	{
		ft_putstr(*map);
		ft_putchar('\n');
		map++;
	}
	return (0);
}
