/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyoung <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/15 13:53:25 by lyoung            #+#    #+#             */
/*   Updated: 2017/03/17 12:12:15 by rvinnako         ###   ########.fr       */
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
char	*set_str(char *str);
char	**set_2D_array(char *str);
char	**set_letter(char **map);

#endif
