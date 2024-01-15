/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chbuerge <chbuerge@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/13 13:08:49 by chbuerge          #+#    #+#             */
/*   Updated: 2024/01/15 10:23:10 by chbuerge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"


// check that you can reach the exit and collectables from the pos of the player


/*
** Function to check if the given filename has a .ber extension.
** It compares the last four characters of the filename with ".ber"
** and exits with an error message if the condition is not met.
**
** Parameters:
**   - filename: The name of the file to be checked.
*/
void	check_filetype(char *filename)
{
	int	len;

	len = ft_strlen(filename);
	if(len < 4 || ft_strcmp(filename + len - 4, ".ber") != 0)
	{
		printf("Error\n");
		exit (1);
	}
}



// loop through the array and apply all the checks above
// if anything returns 1 ft_error?
int	map_check(t_map *map)
{
	int x;
	int y;

	printf("map->col%d \n", map->columns);
	x = 0;
	y = 0;
	while(y < map->rows)
	{
		// check_square?
		if(check_square(map, y) == 1)
			clean_up_1(map);

		x = 0;
		while(x < map->columns)
		{
			if(check_chars(map, y, x) == 1)
				clean_up_1(map);
			if (check_player_exit_collect(map, y, x) == 1)
				clean_up_1(map);
			if(first_last_row(map, x) == 1)
				clean_up_1(map);
			if (first_last_col(map, y) == 1)
				clean_up_1(map);
		x++;
		}
	y++;
	}
	// check here to make sure player, exit and price exist
	if (!(map->player) || !(map->exit) || !(map->collectable_total))
		clean_up_1(map);
	return (0);
}


// check that its sourrounded by walls (first and last row)
int	first_last_row(t_map *map, int x)
{
	int	last_row;

	last_row = map->rows - 1;
	if(map->map_array[0][x] != '1' || map->map_array[last_row][x] != '1')
		return (1);
	return (0);
}
// check that its sourrounded by walls ( ever first and last of each row)
int	first_last_col(t_map *map, int y)
{
	int	last_col;

	last_col = map->columns - 1;
	if(map->map_array[y][0] != '1' || map->map_array[y][last_col] != '1')
		return (1);
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
