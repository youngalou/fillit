/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvinnako <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/17 12:14:03 by rvinnako          #+#    #+#             */
/*   Updated: 2017/03/17 12:45:59 by rvinnako         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include <stdio.h>

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

int		ft_checktet(char *str)
{
	int i;
	int	line_flag;
	int block_flag;
	int count;

	i = 0;
	line_flag = 0;
	block_flag = 0;
	count = 0;
	while (i < 84)
	{
		printf("%c", str[i]);
		if (str[i] != '\n' && str[i] != '.' && str[i] != '#')
			return (0);
		if (line_flag == 4 && (str[i] != '\n'))
			return (0);
		if (block_flag == 4 && (str[i] && str[i + 1] != '\n'))
			return (0);
		if (line_flag == 4)
		{
			block_flag++;
			line_flag = 0;
		}
		i++;
		line_flag++;
	}
	return (1);
}	

/*The logic is still a bit off, but this is what I'd like to work from*/

int		main(int ac, char **av)
{
	char *res;

	if (ac == 2)
	{
		res = ft_getstr(av[1]);
		printf("%d\n", ft_checktet(res));
	}
}
