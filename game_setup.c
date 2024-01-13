/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_setup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chbuerge <chbuerge@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/03 08:46:39 by chbuerge          #+#    #+#             */
/*   Updated: 2024/01/13 11:00:46 by chbuerge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

// general function to put xpm_images anywhere
/*
void	put_img(t_map *map, char *img_path, int x, int y)
{
	char	*img;
	int		img_width;
	int		img_height;

	img_width = 0;
	img_height = 0;
	img = mlx_xpm_file_to_image(map->mlx, img_path, &img_width, &img_height);
    mlx_put_image_to_window(map->mlx, map->mlx_win, img, x * 64, y * 64);
}*/


// function recoginzing the keys and sending info to check next or closing
// the game
int	key_hook(int keycode, t_map *map)
{
	if (keycode == LEFT || keycode == A)
		check_next_field(-1, 'x', map);
	else if(keycode == UP || keycode == W)
		check_next_field(-1, 'y', map);
	else if(keycode == RIGHT || keycode == D)
		check_next_field(1, 'x', map);
	else if(keycode == DOWN || keycode == S)
		check_next_field(1, 'y', map);
	else if (keycode == ESC)
	{
		clean_up(map);
		exit(0);
	}
	return (0);
}

void	*put_img(t_map *map, char *img_path, int x, int y)
{
	void	*img = NULL;
	int		img_width;
	int		img_height;

	img_width = 0;
	img_height = 0;
	img = mlx_xpm_file_to_image(map->mlx, img_path, &img_width, &img_height);
	//free(img);
    mlx_put_image_to_window(map->mlx, map->mlx_win, img, x * 64, y * 64);
	return (img);
}



void	get_tiles(t_map *map)
{
	int x;
	int y;

	x = 0;
	y = 0;
	while(y < map->rows)
	{
		x = 0;
		while(x < map->columns)
		{
			if (map->space_image != NULL)
				mlx_destroy_image(map->mlx, map->space_image);
			map->space_image = put_img(map, SPACE_XPM, x, y);
			if(map->map_array[y][x] == '1')
			{
				if (map->walls_image != NULL)
					mlx_destroy_image(map->mlx, map->walls_image);
				map->walls_image = put_img(map, WALLS_XPM, x, y);
			}
			else if(map->map_array[y][x] == 'C')
			{
				if (map->price_image != NULL)
					mlx_destroy_image(map->mlx, map->price_image);
				map->price_image = put_img(map, PRICE_XPM, x, y);
			}
			else if(map->map_array[y][x] == 'P')
				map->player_image = put_img(map, PLAYER_XPM, x, y);
			else if(map->map_array[y][x] == 'E')
				map->exit_image = put_img(map, EXIT_XPM, x, y);
		x++;
		}
	y++;
	}
}
//
/* CURRENTLY NOT IN USE, MAYBE FOR CLOSING THE WINDOW?*/

// int	mouse_hook(int keycode, t_map *map)
// {
// 	keycode = 1;
// 	printf("Hello from mouse_hook!\n");
// 	// seg fault when called fct below
// 	//mlx_destroy_window(map->mlx, map->mlx_win);
// 	clean_up(map);
// 	exit(1);
// 	return (0);
// }

// int	close_window_on_x(int event, t_map *map)
// {
// 	if (event == 17)
// 	{
// 		clean_up(map);
// 		exit(0);
// 	}
// 	return (0);
// }
// function to set up the game, include game loop
// create window
void	init_game(t_map *map)
{
	void	*img;

	img = NULL;
	map->mlx = mlx_init();
	if (!map->mlx)
	{
		handle_error(map);
	//	free(map->mlx);
	}
	map->mlx_win = mlx_new_window(map->mlx, (IMG_WIDTH * map->columns), (IMG_HEIGHT * map->rows), "so_long");
	// load img
	if (!map->mlx_win)
	{
		handle_error(map);
	//	free(map->mlx);
	}
	if (img != NULL)
	{
		// display img on the screen
		mlx_put_image_to_window(map->mlx, map->mlx_win, img, 300, 500);
		mlx_destroy_image(map->mlx, img);
	}
	get_tiles(map);
	mlx_key_hook(map->mlx_win, key_hook, map);
	//mlx_mouse_hook(map->mlx_win, mouse_hook, map);
	mlx_loop(map->mlx);
}
