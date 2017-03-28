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

int		algorithm(char **square, char **map, int y, int x)
{
	int		i;

	i = 0;
	if (!map[i])
		return (1);
	ft_putstr("--------------\n");
	while (square[y])
	{
		x = 0;
		while (square[y][x])
		{
			printf("y = %d, x = %d | tet = %s\n", y, x, map[i]);
			if (check_place(square, map[i], y, x))
			{
				place_tet(square, map[i], y, x);
				print_square(square, 5);
				if (algorithm(square, &map[i + 1], 0, 0))
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
	while (!algorithm(square, map, 0, 0))
	{
		delete_square(square);
		size++;
		square = new_square(size);
		print_square(square, size);
	}
	print_square(square, size);
}
