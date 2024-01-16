/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_setup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chbuerge <chbuerge@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/03 08:46:39 by chbuerge          #+#    #+#             */
/*   Updated: 2024/01/16 14:06:31 by chbuerge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

// function recoginzing the keys and sending info to check next or closing
// the game
int	key_hook(int keycode, t_map *map)
{
	if (keycode == LEFT || keycode == A)
		check_next_field(-1, 'x', map);
	else if (keycode == UP || keycode == W)
		check_next_field(-1, 'y', map);
	else if (keycode == RIGHT || keycode == D)
		check_next_field(1, 'x', map);
	else if (keycode == DOWN || keycode == S)
		check_next_field(1, 'y', map);
	else if (keycode == ESC)
	{
		clean_up(map);
		exit(0);
	}
	return (0);
}
int	close_on_x(t_map *map)
{
	clean_up(map);
	exit(0);
	return (0);
}

void	*put_img(t_map *map, char *img_path, int x, int y)
{
	void	*img;
	int		img_width;
	int		img_height;

	img = NULL;
	img_width = 0;
	img_height = 0;
	img = mlx_xpm_file_to_image(map->mlx, img_path, &img_width, &img_height);
	mlx_put_image_to_window(map->mlx, map->mlx_win, img, x * 32, y * 32);
	return (img);
}

void	update_img(t_map *map, int x, int y)
{
	if (map->space_image != NULL)
		mlx_destroy_image(map->mlx, map->space_image);
	map->space_image = put_img(map, SPACE_XPM, x, y);
	if (map->map_array[y][x] == '1')
	{
		if (map->walls_image != NULL)
			mlx_destroy_image(map->mlx, map->walls_image);
		map->walls_image = put_img(map, WALLS_XPM, x, y);
	}
	else if (map->map_array[y][x] == 'C')
	{
		if (map->price_image != NULL)
			mlx_destroy_image(map->mlx, map->price_image);
		map->price_image = put_img(map, PRICE_XPM, x, y);
	}
	else if (map->map_array[y][x] == 'P')
		map->player_image = put_img(map, PLAYER_XPM, x, y);
	else if (map->map_array[y][x] == 'E')
		map->exit_image = put_img(map, EXIT_XPM, x, y);
}

void	get_tiles(t_map *map)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	while (y < map->rows)
	{
		x = 0;
		while (x < map->columns)
		{
			update_img(map, x, y);
			x++;
		}
		y++;
	}
}

void	init_game(t_map *map)
{
	void	*img;

	img = NULL;
	map->mlx = mlx_init();
	if (!map->mlx)
		handle_error(map);
	map->mlx_win = mlx_new_window(map->mlx, (IMG_WIDTH * map->columns),
			(IMG_HEIGHT * map->rows), "so_long");
	if (!map->mlx_win)
		handle_error(map);
	if (img != NULL)
	{
		mlx_put_image_to_window(map->mlx, map->mlx_win, img, 300, 500);
		mlx_destroy_image(map->mlx, img);
	}
	get_tiles(map);
	mlx_key_hook(map->mlx_win, key_hook, map);
	mlx_hook(map->mlx_win, 17, (1L << 2), close_on_x, map);
	mlx_loop(map->mlx);
}
