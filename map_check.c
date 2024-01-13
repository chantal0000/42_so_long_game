/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chbuerge <chbuerge@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/13 13:08:49 by chbuerge          #+#    #+#             */
/*   Updated: 2024/01/13 17:16:50 by chbuerge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

// check if .ber file

// check that its sourrounded by walls


// check that you can reach the exit and collectables from the pos of the player


// loop through the array and apply all the checks above
// if anything returns 1 ft_error?
int	map_check(t_map *map)
{
	int x;
	int y;

	x = 0;
	y = 0;
	while(y < map->rows)
	{
		// check_square?
		if(check_square(map, y) == 1)
			clean_up_1(map);
		// if (check_walls(map, y, x) == 1)
		// 	clean_up_1(map);
		x = 0;
		while(x < map->columns)
		{
			if(check_chars(map, y, x) == 1)
				clean_up_1(map);
			if (check_player_exit_collect(map, y, x) == 1)
				clean_up_1(map);
			// if (check_walls(map, y, x) == 1)
			// 	clean_up_1(map);
		x++;
		}
	y++;
	}
	// check here to make sure player, exit and price exist
	if (!(map->player) || !(map->exit) || !(map->collectable_total))
		clean_up_1(map);
	return (0);
}
// check that exactly one player exists
// check that exactly one exit exists
// check that at least one collect exist
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
	// if (map->map_array[y][x] == 'C' && !(map->collectable))
	// 	map->collectable = 1;
	return (0);
}

// check if square
int	check_square(t_map *map, int y)
{
		if ((ft_strlen(map->map_array[y]) - 1) != map->columns)
			return(1);
		return (0);
}
// check that it only has allowed chars
int	check_chars(t_map *map, int y, int x)
{
	if	((map->map_array[y][x] == '1') || (map->map_array[y][x] == '0') ||
		(map->map_array[y][x] == 'P') || (map->map_array[y][x] == 'E') ||
		(map->map_array[y][x] == 'C'))
		return (0);
	else
		return (1);
}
// if first line and last line and first and last of every line
// int	check_walls(t_map *map, int y, int x)
// {
// 	y = 0;

// 	if (map->map_array[y] == map->map_array[0])
// 	{
// 		printf("%c",map->map_array[y][x]);
// 		printf("x\n");
// 		if (map->map_array[y][x] != '1')
// 			return (1);
// 	}
// 	return (0);
// }
