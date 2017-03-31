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
char	**set_array(char *str);
char	**isolate_tet(char **map);
char	**set_letter(char **map);
int		count_tets(char *file);
int		min_square_size(int nb_tets);
char	**new_square(int size);
void	delete_square(char **square);
void	print_square(char **square, int size);
void	reset_square(char **square);
void	place_tet(char **square, char *tet, int y, int x);
int		check_place(char **square, char *tet, int y, int x);
void	find_solution(char **map, int size);

#endif
