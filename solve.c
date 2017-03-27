void	place_tet(char **square, char *tet, int y, int x)
{
	int		init_x;
	int		i;

	init_x = x;
	i = 0;
	while (tet[i] == '.')
	{
		init_x--;
		i++;
	}
	while (tet[i])
	{
		if ((i + 1) % 4 == 0)
		{
			x = init_x;
			y++;
		}
		if (tet[i] != '.')
			square[y][x] = tet[i];
		i++;
		x++;
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
}
