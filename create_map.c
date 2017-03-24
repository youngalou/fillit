/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyoung <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/23 11:25:31 by lyoung            #+#    #+#             */
/*   Updated: 2017/03/24 11:53:42 by lyoung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

char	**set_array(char *str)
{
	int		i;
	char	**map;

	i = 0;
	while (str[i])
	{
		if ((i + 1) % 21 == 0 && str[i] == '\n')
			str[i] = '%';
		i++;
	}
	map = ft_strsplit(str, '%');
	return (map);
}

void	set_letter(char **map)
{
	int		i;
	int     j;
	char	c;

	i = 0;
	c = 'A';
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == '#')
				map[i][j] = c; 
			j++;
		}
		c = c + 1;
		i++;
	}
}

void	trim_nl(char **map)
{
	int		i;
	int		j;
	int		a;
	char	tmp[20];

	i = 0;
	while (map[i])
	{
		ft_bzero(tmp, 20);
		j = 0;
		a = 0;
		while (map[i][j])
		{
			if (map[i][j] == '\n')
				j++;
			tmp[a] = map[i][j];
			j++;
			a++;
		}
		ft_bzero(map[i], 20);
		ft_strcpy(map[i], tmp);
		i++;
	}
}
