/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_setup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chbuerge <chbuerge@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/03 08:46:39 by chbuerge          #+#    #+#             */
/*   Updated: 2024/01/11 11:52:26 by chbuerge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
/* AM I USING THIS ANYWEHERE?
void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}*/
// general function to put xpm_images anywhere
void	put_img(t_map *map, char *img_path, int x, int y)
{
	char	*img;
	int		img_width;
	int		img_height;

	img_width = 0;
	img_height = 0;
	img = mlx_xpm_file_to_image(map->mlx, img_path, &img_width, &img_height);
    mlx_put_image_to_window(map->mlx, map->mlx_win, img, x * 64, y * 64);
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
			put_img(map, SPACE_XPM, x, y);
			if(map->map_array[y][x] == '1')
				put_img(map, WALLS_XPM, x, y);
			else if(map->map_array[y][x] == 'C')
				put_img(map, PRICE_XPM, x, y);
			else if(map->map_array[y][x] == 'P')
				put_img(map, PLAYER_XPM, x, y);
			else if(map->map_array[y][x] == 'E')
				put_img(map, EXIT_XPM, x, y);
		x++;
		}
	y++;
	}
}
//
/* CURRENTLY NOT IN USE, MAYBE FOR CLOSING THE WINDOW?

int	mouse_hook(int keycode, t_map *map)
{
	printf("Hello from mouse_hook!\n");
	// seg fault when called fct below
	//mlx_destroy_window(map->mlx, map->mlx_win);

	return (0);
}*/
// function to set up the game, include game loop
// create window
void	init_game(t_map *map)
{
	void	*img;

	map->mlx = mlx_init();
	if (!map->mlx)
	{
		handle_error();
	//	free(map->mlx);
	}
	map->mlx_win = mlx_new_window(map->mlx, (IMG_WIDTH * map->columns), (IMG_HEIGHT * map->rows), "so_long");
	// load img
	if (!map->mlx_win)
	{
		handle_error();
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
	mlx_loop(map->mlx);
}