/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyoung <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/23 11:25:31 by lyoung            #+#    #+#             */
/*   Updated: 2017/04/14 12:57:54 by lyoung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

char	*ft_getstr(char *file)
{
	int		fd;
	char	*res;
	char	buff[545];

	fd = open(file, O_RDONLY, S_IRUSR);
	read(fd, &buff, 545);
	res = ft_strdup(buff);
	return (res);
}

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

char	**set_letter(char **map)
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
	return (map);
}
