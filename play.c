/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   play.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chbuerge <chbuerge@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 14:28:35 by chbuerge          #+#    #+#             */
/*   Updated: 2024/01/10 18:57:26 by chbuerge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

// function when key pressed figure out which tile to check next
// send map and location of tile to check_next_tile
// 1. key handle

int update_pos(t_map *map)
{
	int i = map->pos_player_x;
	int j = map->pos_player_y;
	printf("1starting pos: %d\n", i);
	printf("1starting pos: %d\n", j);
	//int cur_x = map->pos_player_x;
	//int cur_y = map->pos_player_y;
	printf("hi\n");
	// if key_hook == LEFT
		// map->pos_player_x = map->pos_player_x - 1;
		// check_next_fields(map);
	return(0);
}

int	key_hook(int keycode, t_map *map)
{
	if (keycode == LEFT || keycode == A)
	{
		my_test_function(map);
	}
	else if(keycode == UP || keycode == W)
		printf("UP\n");
	else if(keycode == RIGHT || keycode == D)
		{
			printf("RIGHT\n");
			//check_next_field(map->map_array[y][x + 1]);
		}
	else if(keycode == DOWN || keycode == S)
		printf("DOWN\n");
	return (0);
}
void my_test_function(t_map *map)
{
	printf("testing left: %d\n", map->columns);
	printf("hello lefti\n");
	printf("Xstarting pos: %d\n", map->pos_player_x);
	printf("Xstarting pos: %d\n", map->pos_player_y);

}


// move player
// when key pressed check next tile
	// if != '1'
		// if == '0


