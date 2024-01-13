/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_play.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chbuerge <chbuerge@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 14:28:35 by chbuerge          #+#    #+#             */
/*   Updated: 2024/01/13 10:55:54 by chbuerge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

// function when key pressed figure out which tile to check next
// send map and location of tile to check_next_tile
// 1. key handle
/* CURRENTLY NOT IN USE
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
}*/
int	check_for_win(t_map *map)
{
	// if collectable == total of collectable -> win
	printf("col: %d total_col: %d \n", map->collectable, map->collectable_total);
	if (map->collectable == map->collectable_total)
	{
		map->move_counter++;
		printf("YOU WIN with %d moves\n", map->move_counter);

		// seg fault her

		// free all resources etc. like make sure everything is ready to be quit
		// before or after destroying window?

		// whats happening here?
		//ft_destroy_images(map);
		clean_up(map);

		//clean_up(map);
		exit(0);
		//return(0);
	}
	else
	{
		printf("/////////\n");
		printf("not done\n");
		printf("/////////\n");
		return(1);
	}
	// whats supposed to happen? close window?
}


// do i need all ifs?
int	key_hook(int keycode, t_map *map)
{
	if (keycode == LEFT || keycode == A)
	{
		check_next_field(-1, 'x', map);
		//printf("LEFT\n");
	}
	else if(keycode == UP || keycode == W)
	{
		check_next_field(-1, 'y', map);
		//printf("UP\n");
	}
	else if(keycode == RIGHT || keycode == D)
	{
		check_next_field(1, 'x', map);
		//printf("RIGHT\n");
	}
	else if(keycode == DOWN || keycode == S)
	{
		check_next_field(1, 'y', map);
		//printf("DOWN\n");
	}
	else if (keycode == ESC)
	{
		clean_up(map);
		exit(1);
	}
	return (0);
}

int check_next_field(int move, char pos, t_map *map)
{
	int i;
	int j;

	i = map->pos_player_x;
	j = map->pos_player_y;
	if (pos == 'x')
		i = map->pos_player_x + move;
	else if (pos == 'y')
		j = map->pos_player_y + move;
	if((map->map_array[j][i] == '0') ||
		(map->map_array[j][i] == 'C') )
		{
				// if C somehow safe info into my struct /
			if (map->map_array[j][i] == 'C')
				{
					map->collectable++;
					map->map_array[j][i] = '0';
				}
				//put background on the old position
			if (map->space_image != NULL)
				mlx_destroy_image(map->mlx, map->space_image);
			map->space_image = put_img(map, SPACE_XPM, map->pos_player_x, map->pos_player_y);
			if (pos == 'x')
				map->pos_player_x = map->pos_player_x + move;
			else if (pos == 'y')
				map->pos_player_y = map->pos_player_y + move;
				//put img of player
			if (map->player_image != NULL)
				mlx_destroy_image(map->mlx, map->player_image);
			map->player_image = put_img(map, PLAYER_XPM, map->pos_player_x, map->pos_player_y);
			map->move_counter++;
			printf("moves: %d\n", map->move_counter);
				//printf("space or collect\n");
		}
		else if(map->map_array[j][i] == 'E')
		{
			check_for_win(map);
		}
		else if(map->map_array[j][i] == '1')
		{
			printf("alert, wall!\n");
				// what to do if wall?
		}
	return(0);

}


