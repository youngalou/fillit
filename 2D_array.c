/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   2D_array.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyoung <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/23 11:25:31 by lyoung            #+#    #+#             */
/*   Updated: 2017/03/23 11:51:38 by lyoung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

char	*set_str(char *file)
{
	int		fd;
	char	buff[545];
	char	*str;
	int		i;

	fd = open(file, O_RDONLY, S_IRUSR);
	read(fd, &buff, 545);
	str = ft_strdup(buff);
	i = 0;
	while (str[i])
	{
		if ((i + 1) % 21 == 0 && str[i] == '\n')
			str[i] = '%';
		i++;
	}
	return (str);
}

char	**set_2D_array(char *str)
{
	char	**map;

	map = ft_strsplit(str, '%');
	return (map);
}

int		main(int argc, char **argv)
{
	char	**map;
	if (argc != 2)
	{
		ft_putstr("usage: ./fillit source_file\n");
		return (0);
	}
	map = set_2D_array(set_str(argv[1]));
	while (*map)
	{
		ft_putstr(*map);
		ft_putchar('\n');
		map++;
	}
	return (0);
}
