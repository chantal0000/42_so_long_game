/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chbuerge <chbuerge@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/13 13:08:49 by chbuerge          #+#    #+#             */
/*   Updated: 2024/01/15 12:27:40 by chbuerge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

// check that you can reach the exit and collectables from the pos of the player

/*
** Validates the 2D map represented by 't_map'.
** Checks: square validity, character correctness, player, exit, collectables,
** and map boundary conditions. If any issues are found, it exits with an error
** message.
**
** Parameters:
**   - map: Pointer to the 't_map' structure representing the map.
**
** Returns:
**   - 0 on successful map validation.
*/
void	map_check(t_map *map)
{
	int	x;
	int	y;

	y = 0;
	while (y < map->rows)
	{
		if (check_square(map, y) == 1)
			clean_up_1(map);
		x = 0;
		while (x < map->columns)
		{
			if (check_chars(map, y, x) == 1
				|| check_player_exit_collect(map, y, x) == 1
				|| first_last(map, y, x) == 1)
				clean_up_1(map);
			x++;
		}
		y++;
	}
	if (!(map->player) || !(map->exit) || !(map->collectable_total))
		clean_up_1(map);
}

//check that the first and last rows are all '1' / WALLS
int	first_last(t_map *map, int y, int x)
{
	int	last_row;
	int	last_col;

	last_row = map->rows - 1;
	last_col = map->columns - 1;
	if (map->map_array[0][x] != '1' || map->map_array[last_row][x] != '1')
		return (1);
	if (map->map_array[y][0] != '1' || map->map_array[y][last_col] != '1')
		return (1);
	return (0);
}

// check that not more than one player & exit exists
int	check_player_exit_collect(t_map *map, int y, int x)
{
	if (map->map_array[y][x] == 'P' && !(map->player))
		map->player = 1;
	else if (map->map_array[y][x] == 'P' && (map->player == 1))
		return (1);
	if (map->map_array[y][x] == 'E' && !(map->exit))
		map->exit = 1;
	else if (map->map_array[y][x] == 'E' && (map->exit == 1))
		return (1);
	return (0);
}

// check if square
int	check_square(t_map *map, int y)
{
	if ((ft_strlen(map->map_array[y]) - 1) != map->columns)
		return (1);
	return (0);
}

// check that only valid chars
int	check_chars(t_map *map, int y, int x)
{
	if ((map->map_array[y][x] == '1') || (map->map_array[y][x] == '0') ||
		(map->map_array[y][x] == 'P') || (map->map_array[y][x] == 'E') ||
		(map->map_array[y][x] == 'C'))
		return (0);
	else
		return (1);
}
