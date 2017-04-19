/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvinnako <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/17 12:14:03 by rvinnako          #+#    #+#             */
/*   Updated: 2017/04/19 11:01:16 by lyoung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

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
	if (i == 19 && (str[i] != '\n' ||
				(str[i + 1] != '\n' && str[i + 1] != '\0')))
		return (0);
	return (1);
}

int		ft_countcheck(char *str)
{
	int		i;
	int		count;

	i = 0;
	count = 0;
	while (str[i])
	{
		if (str[i] != '#' && str[i] != '.' && str[i] != '\n')
			return (0);
		if (str[i] == '#')
			count++;
		i++;
	}
	if (count == 4)
		return (1);
	return (0);
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

int		check_next(char *str)
{
	int		i;

	i = 0;
	while (i < 20)
	{
		if (!str[i])
			return (0);
		i++;
	}
	return (1);
}

int		ft_maincheck(char *str)
{
	int		i;
	int		j;
	char	*sub;

	if (!*str)
		return (0);
	if (str[ft_strlen(str) - 1] == '\n' && str[ft_strlen(str) - 2] == '\n')
		return (0);
	i = 0;
	while (str[i])
	{
		sub = ft_strsub(str, i, 21);
		j = 0;
		if (ft_nlcheck(sub) == 0 || ft_shapecheck(sub) == 0
				|| ft_countcheck(sub) == 0)
			return (0);
		i = i + 21;
	}
	return (1);
}
