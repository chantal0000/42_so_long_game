/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chbuerge <chbuerge@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/13 13:08:49 by chbuerge          #+#    #+#             */
/*   Updated: 2024/01/17 11:30:44 by chbuerge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

/*
** Validates the 2D map represented by 't_map'.
** Checks: square validity, character correctness, player, exit, collectables,
** and map boundary conditions. If any issues are found, it exits with an error
** message.
*/
void	map_check(t_map *map)
{
	int	x;
	int	y;

	y = 0;
	while (y < map->rows)
	{
		if (check_square(map, y) == 1)
			clean_up_map("Error\nThe Map is not square\n", map);
		x = 0;
		while (x < map->columns)
		{
			if (check_chars(map, y, x) == 1
				|| check_player_exit(map, y, x) == 1
				|| first_last(map, y, x) == 1)
				clean_up_map("", map);
			x++;
		}
		y++;
	}
	if (!(map->player) || !(map->exit) || !(map->collectable_total))
		clean_up_map("Error\nPlayer, Exit or Collectible missing\n", map);
}

/*
** checks if all is surrounded by walls
*/
int	first_last(t_map *map, int y, int x)
{
	int	last_row;
	int	last_col;

	last_row = map->rows - 1;
	last_col = map->columns - 1;
	if (map->map_array[0][x] != '1' || map->map_array[last_row][x] != '1')
	{
		ft_printf("Error\nThe map is not sourrounded by walls\n");
		return (1);
	}
	if (map->map_array[y][0] != '1' || map->map_array[y][last_col] != '1')
	{
		ft_printf("Error\nThe map is not sourrounded by walls\n");
		return (1);
	}
	return (0);
}

/*
** check that not more than one player & exit exists
*/
int	check_player_exit(t_map *map, int y, int x)
{
	if (map->map_array[y][x] == 'P' && !(map->player))
		map->player = 1;
	else if (map->map_array[y][x] == 'P' && (map->player == 1))
	{
		ft_printf("Error\nToo many Players\n");
		return (1);
	}
	if (map->map_array[y][x] == 'E' && !(map->exit))
		map->exit = 1;
	else if (map->map_array[y][x] == 'E' && (map->exit == 1))
	{
		ft_printf("Error\nToo many Exits\n");
		return (1);
	}
	return (0);
}

/*
** check that the map is square/ all rows should have the same length
*/
int	check_square(t_map *map, int y)
{
	if ((ft_strlen(map->map_array[y]) - 1) != map->columns)
		return (1);
	return (0);
}

/*
** allow only the chars: '1' '0' 'P' 'E' 'C'
*/
int	check_chars(t_map *map, int y, int x)
{
	if ((map->map_array[y][x] == '1') || (map->map_array[y][x] == '0') ||
		(map->map_array[y][x] == 'P') || (map->map_array[y][x] == 'E') ||
		(map->map_array[y][x] == 'C'))
		return (0);
	else
	{
		ft_printf("Error\nInvalid characters\n");
		return (1);
	}
}
