/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   play.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chbuerge <chbuerge@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 14:28:35 by chbuerge          #+#    #+#             */
/*   Updated: 2024/01/11 10:49:23 by chbuerge         ###   ########.fr       */
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
	char *img;
	int img_width;
	int img_height;
//if key code UP || DOWN -> y
//if key code LEFT || RIGHT -> x
	if (key == 'x')
	{
		printf("pos1: %d\n", map->pos_player_x);
		if((map->map_array[map->pos_player_y][map->pos_player_x + move] == '0') ||
			(map->map_array[map->pos_player_y][map->pos_player_x + move] == 'C'))
			{
				printf("pos: %d\n", map->pos_player_x);
				map->pos_player_x = map->pos_player_x + move;
				//put img of player
				//put background on the old position
				img = mlx_xpm_file_to_image(map->mlx, PLAYER_XPM, &img_width, &img_height);
				mlx_put_image_to_window(map->mlx, map->mlx_win, img, map->pos_player_x * 64, map->pos_player_y * 64);
				// safe info about collectable
				printf("space or collect\n");
			}
			else if(map->map_array[map->pos_player_y][map->pos_player_x + move] == '1')
			{
				printf("alert, wall!\n");
				// what to do if wall?
			}
	}
	else if (key == 'y')
	{
		if((map->map_array[map->pos_player_y + move][map->pos_player_x] == '0') ||
		(map->map_array[map->pos_player_y + move][map->pos_player_x] == 'C'))
		{
			printf("pos y: %d\n", map->pos_player_y);
				map->pos_player_y = map->pos_player_y + move;
				//put img of player
				//put background on the old position
				img = mlx_xpm_file_to_image(map->mlx, PLAYER_XPM, &img_width, &img_height);
				mlx_put_image_to_window(map->mlx, map->mlx_win, img, map->pos_player_x * 64, map->pos_player_y * 64);
				// safe info about collectable
				printf("space or collect\n");
		}
		else if(map->map_array[map->pos_player_y][map->pos_player_x + move] == '1')
			{
				printf("alert, wall!\n");
				// what to do if wall?
			}
	}


	//if (((map->pos_player_x + move)) == '0' || ((map->pos_player_x + move) == 'C'))

	//map->pos_player_x = map->pos_player_x + move;
	//if (map->map_array[map->pos_player_y][map->pos_player_x] == '0')
	//	printf("hell yea, its floor\n");

	//else if(map->map_array[map->pos_player_y][map->pos_player_x] == 'C')
	//	printf("collectable\n");
	return(0);

}


// move player
// when key pressed check next tile
	// if != '1'
		// if == '0


