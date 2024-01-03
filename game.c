/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chbuerge <chbuerge@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/03 08:46:39 by chbuerge          #+#    #+#             */
/*   Updated: 2024/01/03 14:51:04 by chbuerge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
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
	void	*mlx_win;
	char *img_path = "./assets/space.xpm";
	int i_width;
	int i_height;

	mlx = mlx_init();
	if (mlx == NULL)
		handle_error();
	//img = mlx_new_image(mlx, 1920, 1080);
	mlx_win = mlx_new_window(mlx, 500, 500, "Hello world!");
	//img.img = mlx_new_image(mlx, 1920, 1080);
	//calculate the memory offset using the line length set by mlx_get_data_addr
	// int offset = (y * line_length + x * (bits_per_pixel / 8));
	//img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length, &img.endian);
	//my_mlx_pixel_put(&img, 15, 15, 0x00FF0000);

	img = mlx_xpm_file_to_image(mlx, img_path, &i_width, &i_height);


	//mlx_put_image_to_window(mlx, mlx_win, img.img, 0, 0);
	// to keep window open long
	mlx_loop(mlx);
	//mlx_destroy_display(mlx);
}*/

void	init_game(void)
{
	void	*mlx;
	void	*img;
	//char	*relative_path = "assets/space.xpm";
	int		img_width;
	int		img_height;
	void	*mlx_win;


	mlx = mlx_init();
	if (!mlx)
	{
		handle_error();
		free(mlx);
	}
	mlx_win = mlx_new_window(mlx, 1920, 1080, "so_long");
	// load img
	if (!mlx_win)
	{
		handle_error();
		free(mlx);
	}
	img = mlx_xpm_file_to_image(mlx, SPACE_XPM, &img_width, &img_height);
	img = mlx_xpm_file_to_image(mlx, SPACE_XPM, &img_width, &img_height);

	if (img !=NULL)
	{

		// display img on the screen
		mlx_put_image_to_window(mlx, mlx_win, img, 300, 500);
		mlx_put_image_to_window(mlx, mlx_win, img, 0, 0);
		// free img
		mlx_destroy_image(mlx, img);
	}
	mlx_loop(mlx);
}
