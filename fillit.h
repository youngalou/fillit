/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyoung <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/15 13:53:25 by lyoung            #+#    #+#             */
/*   Updated: 2017/03/24 11:55:16 by lyoung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include "libft.h"

char	*ft_getstr(char *file);
int		ft_maincheck(char *str);
int		ft_nlcheck(char *str);
int		ft_shapecheck(char *str);
char	**set_array(char *str);
void	set_letter(char **map);
void	trim_nl(char **map);
void	isolate_tet(char **map);

#endif
