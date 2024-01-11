/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chbuerge <chbuerge@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/03 08:46:39 by chbuerge          #+#    #+#             */
/*   Updated: 2024/01/11 11:32:11 by chbuerge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}
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
// creates a new sprite img using the data loaded from the XPM file
/*
t_image	ft_create_sprite(void *mlx, char *xpm_path, t_game *game)
{
	t_image	sprite;

	sprite.xpm_ptr = mlx_xmp_file_to_image(mlx, xpm_path, &sprite.x, &sprite.y);
	return (sprite);
}*/

/*
void	init_game()
{
	void	*mlx;
	//t_data	img;
	void *img;
	void	*map->mlx_win;
	char *img_path = "./assets/space.xpm";
	int i_width;
	int i_height;

	mlx = mlx_init();
	if (mlx == NULL)
		handle_error();
	//img = mlx_new_image(mlx, 1920, 1080);
	map->mlx_win = mlx_new_window(mlx, 500, 500, "Hello world!");
	//img.img = mlx_new_image(mlx, 1920, 1080);
	//calculate the memory offset using the line length set by mlx_get_data_addr
	// int offset = (y * line_length + x * (bits_per_pixel / 8));
	//img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length, &img.endian);
	//my_mlx_pixel_put(&img, 15, 15, 0x00FF0000);

	img = mlx_xpm_file_to_image(mlx, img_path, &i_width, &i_height);


	//mlx_put_image_to_window(mlx, map->mlx_win, img.img, 0, 0);
	// to keep window open long
	mlx_loop(mlx);
	//mlx_destroy_display(mlx);
}*/
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
int	mouse_hook(int keycode, t_map *map)
{
	printf("Hello from mouse_hook!\n");
	// seg fault when called fct below
	//mlx_destroy_window(map->mlx, map->mlx_win);

	return (0);
}





void	init_game(t_map *map)
{
	void	*img;

	map->mlx = mlx_init();
	if (!map->mlx)
	{
		handle_error();
		free(map->mlx);
	}
	printf("IMG_HEIGHT %d map->col %d\n", IMG_HEIGHT, map->columns);
	map->mlx_win = mlx_new_window(map->mlx, (IMG_WIDTH * map->columns), (IMG_HEIGHT * map->rows), "so_long");
	// load img
	if (!map->mlx_win)
	{
		handle_error();
		free(map->mlx);
	}
	get_tiles(map);

	//update_pos(map);


	if (img !=NULL)
	{

		// display img on the screen
		mlx_put_image_to_window(map->mlx, map->mlx_win, img, 300, 500);
		//mlx_put_image_to_window(mlx, map->mlx_win, img, 0, 0);
		// free img
		mlx_destroy_image(map->mlx, img);
	}
	//mlx_mouse_hook(map->mlx_win, mouse_hook, &map);
	mlx_key_hook(map->mlx_win, key_hook, map);

	mlx_loop(map->mlx);

}
