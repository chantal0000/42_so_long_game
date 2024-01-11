/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_play.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chbuerge <chbuerge@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 14:28:35 by chbuerge          #+#    #+#             */
/*   Updated: 2024/01/11 15:25:05 by chbuerge         ###   ########.fr       */
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
		mlx_destroy_window(map->mlx, map->mlx_win);
		exit(1);
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
		printf("LEFT\n");
	}
	else if(keycode == UP || keycode == W)
	{
		check_next_field(-1, 'y', map);
		printf("UP\n");
	}
	else if(keycode == RIGHT || keycode == D)
	{
		check_next_field(1, 'x', map);
		printf("RIGHT\n");
	}
	else if(keycode == DOWN || keycode == S)
	{
		check_next_field(1, 'y', map);
		printf("DOWN\n");
	}
	return (0);
}

int check_next_field(int move, char key, t_map *map)
{
	int i;
	int j;

	i = map->pos_player_x;
	j = map->pos_player_y;
//if key code UP || DOWN -> y
//if key code LEFT || RIGHT -> x
	if (key == 'x')
		i = map->pos_player_x + move;
	else if (key == 'y')
		j = map->pos_player_y + move;

	//if (key == 'x')
	//{
	printf("pos1: %d\n", map->pos_player_x);
		if((map->map_array[j][i] == '0') ||
			(map->map_array[j][i] == 'C') )//|| (map->map_array[j][i] == 'E'))
			{
				// if C somehow safe info into my struct /
				if (map->map_array[j][i] == 'C')
					map->collectable++;
					/*
				if (map->map_array[j][i] == 'E')
				{
					if(check_for_win(map) == 1)
						put_img(map, EXIT_XPM, map->pos_player_x, map->pos_player_y);
				}*/
				printf("price: %d\n", map->collectable);
				//printf("pos: %d\n", map->pos_player_x);
				//put background on the old position
				put_img(map, SPACE_XPM, map->pos_player_x, map->pos_player_y);
				if (key == 'x')
					map->pos_player_x = map->pos_player_x + move;
				else if (key == 'y')
					map->pos_player_y = map->pos_player_y + move;
				//put img of player
				put_img(map, PLAYER_XPM, map->pos_player_x, map->pos_player_y);
				map->move_counter++;
				printf("moves: %d\n", map->move_counter);
				printf("space or collect\n");
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


