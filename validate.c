/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvinnako <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/17 12:14:03 by rvinnako          #+#    #+#             */
/*   Updated: 2017/03/24 11:31:23 by lyoung           ###   ########.fr       */
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

int		ft_maincheck(char *str)
{
	int		i;
	int		j;
	int		count;
	char	*sub;

	i = 0;
	while (str[i] != '\0')
	{
		sub = ft_strsub(str, i, 21);
		j = 0;
		count = 0;
		while (sub[j] != '\0')
		{
			if (sub[j] != '#' && sub[j] != '.' && sub[j] != '\n')
				return (0);
			if (sub[j] == '#')
				count++;
			j++;
		}
		if (ft_nlcheck(sub) == 0 || ft_shapecheck(sub) == 0 || count != 4)
			return (0);
		i = i + 21;
	}
	return (1);
}

int		ft_nlcheck(char *str)
{
	int		i;

	i = 4;
	while (i != 19)
	{
		if (str[i] != '\n')
			return (0);
		i += 5;
	}
	if (i == 19 && str[i] != '\n' && (str[i + 1] != '\n' || str[i + 1] != '\0'))
		return (0);
	return (1);
}

int		ft_shapecheck(char *str)
{
	int		count;
	int		i;

	count = 0;
	i = 0;
	while (i < 20)
	{
		if (str[i] == '#')
		{
			if ((i + 1) < 20 && str[i + 1] == '#')
				count++;
			if ((i - 1) >= 0 && str[i - 1] == '#')
				count++;
			if ((i + 5) < 20 && str[i + 5] == '#')
				count++;
			if ((i - 5) >= 0 && str[i - 5] == '#')
				count++;
		}
		i++;
	}
	if (count == 6 || count == 8)
		return (1);
	return (0);
}
