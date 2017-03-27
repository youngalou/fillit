/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fix_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyoung <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/23 11:55:12 by lyoung            #+#    #+#             */
/*   Updated: 2017/03/24 11:40:33 by lyoung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	store_shapes(char tab[20][15])
{
	int		i;

	i = 0;
	while (i < 20)
	{
		ft_bzero(tab[i], 15);
		i++;
	}
	ft_strcpy(tab[0], "####");
	ft_strcpy(tab[1], "#...#...#...#");
	ft_strcpy(tab[2], "##..#...#");
	ft_strcpy(tab[3], "###...#");
	ft_strcpy(tab[4], ".#...#..##");
	ft_strcpy(tab[5], "#...###");
	ft_strcpy(tab[6], "##...#...#");
	ft_strcpy(tab[7], "..#.###");
	ft_strcpy(tab[8], "#...#...##");
	ft_strcpy(tab[9], "###.#");
	ft_strcpy(tab[10], "#...##..#");
	ft_strcpy(tab[11], "###..#");
	ft_strcpy(tab[12], ".#..##...#");
	ft_strcpy(tab[13], ".#..###");
	ft_strcpy(tab[14], ".#..##..#");
	ft_strcpy(tab[15], "##...##");
	ft_strcpy(tab[16], ".##.##");
	ft_strcpy(tab[17], "#...##...#");
	ft_strcpy(tab[18], "##..##");
}

int		find_shape(const char *big, const char *little)
{
	int		i;
	int		j;

	i = 0;
	if (!*little)
		return (0);
	while (big[i])
	{
		j = 0;
		while (big[i + j] == little[j])
		{
			if (!little[j + 1])
				return (1);
			j++;
		}
		i++;
	}
	return (0);
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

char	**isolate_tet(char **map)
{
	char	tab[20][15];
	int		i;
	int		j;

	store_shapes(tab);
	trim_nl(map);
	i = 0;
	while (map[i])
	{
		j = 0;
		while (j < 19)
		{
			if (find_shape(map[i], tab[j]))
			{
				ft_bzero(map[i], 20);
				ft_strcpy(map[i], tab[j]);
			}
			j++;
		}
		i++;
	}
	return (map);
}
