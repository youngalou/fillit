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
		if (square[y][x] && square[y][x] != '.' && tet[i] != '.')
			return (0);
		i++;
		x++;
	}
	return (1);
}

void	remove_tet(char **square, char c)
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

int		algorithm(char **square, char **map, int size, int i)
{
	int		y;
	int		x;

	if (!map[i])
		return (1);
	y = 0;
	while (y < size)
	{
		x = 0;
		while (x < size)
		{
			if (check_place(square, map[i], y, x))
			{
				place_tet(square, map[i], y, x);
				if (algorithm(square, map, size, i + 1))
					return (1);
				else
					remove_tet(square, i + 65);
			}
			x++;
		}
		y++;
	}
	return (0);
}

void	find_solution(char **map, int size)
{
	char	**square;

	square = new_square(size);
	print_square(square, size);
	while (algorithm(square, map, size, 0) == 0)
	{
		delete_square(square);
		size++;
		square = new_square(size);
	}
	print_square(square, size);
	delete_square(square);
}
