#include "fillit.h"

void	place_tet(char **square, char *tet, int y, int x)
{
	int		init_x;
	int		i;

	init_x = x;
	i = 0;
	while (tet[i])
	{
		if (i != 0 && (i % 4 == 0))
		{
			x = init_x;
			y++;
		}
		if (tet[i] && tet[i] != '.')
			square[y][x] = tet[i];
		i++;
		x++;
	}
}

int		check_place(char **square, char *tet, int y, int x)
{
	int		init_x;
	int		i;

	init_x = x;
	i = 0;
	while (tet[i])
	{
		if (i != 0 && (i % 4 == 0))
		{
			x = init_x;
			y++;
		}
		if (!square[y][x] && tet[i] != '.')
			return (0);
		i++;
		x++;
	}
	return (1);
}

void	reset_square(char **square)
{
	int		i;
	int		j;
	
	i = 0;
	while (i < 5)
	{
		j = 0;
		while (j < 5)
		{
			if (square[i][j] != '\0')
				square[i][j] = '.';
			j++;
		}
		i++;
	}
}

/*void	remove_tet(char **square, char c)
{
	int		y;
	int		x;

	y = 0;
	while (square[y])
	{
		x = 0;
		while (square[y][x])
		{
			if (square[y][x] == c)
				square[y][x] = '.';
			x++;
		}
		y++;
	}
}

void	algorithm(char **map)
{
	int		y;
	int		x;
	char	**square;

	y = 0;
	x = 0;
	square = set_min_square(map);
	while (check_solution(square))
	{
		if (check_placement(square, map[i], y, x))
		{
			place_tet(square, map[i], y, x);
		}
	}
} */
