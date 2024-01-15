/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chbuerge <chbuerge@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/02 10:14:34 by chbuerge          #+#    #+#             */
/*   Updated: 2024/01/15 12:58:17 by chbuerge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_error(char *str)
{
	ft_printf("%s", str);
	exit(1);
}

void	clean_up_1(t_map *map)
{
	//printf("Error\n");
	ft_printf("Error\nInvalid configuration detected in the map\n");
	if (map->map_array)
		free_array(map);
	if(map->mlx_win)
		mlx_destroy_window(map->mlx, map->mlx_win);
	if(map->mlx)
		mlx_destroy_display(map->mlx);
	if(map->mlx)
		free(map->mlx);
	if(map)
		free(map);
	exit(1);
}

void handle_error(t_map *map)
{
	write(1, "Error\n", 6);
	clean_up(map);
	// free all things here
	exit (1);
}

//function to initialize the map structure I/II
void	init_map_struct(t_map *map)
{
	//map->fd = 0;
	map->mlx = NULL;
	map->mlx_win = NULL;
	map->wall = 0;
	map->player = 0;
	map->exit = 0;
	map->collectable_total = 0;
	map->collectable = 0;
	map->columns = 0;
	map->rows = 0;
	init_map_struct_2(map);
}

//function to initialize the map structure II/II
void	init_map_struct_2(t_map *map)
{
	map->map_array = NULL;
	map->pos_player_x = 0;
	map->pos_player_y = 0;
	map->move_counter = 0;
	map->walls_image = NULL;
	map->space_image = NULL;
	map->player_image = NULL;
	map->price_image = NULL;
	map->exit_image = NULL;
}

/*
** Function to check if the given filename has a .ber extension.
** It compares the last four characters of the filename with ".ber"
** and exits with an error message if the condition is not met.
**
** Parameters:
**   - filename: The name of the file to be checked.
*/
void	check_filetype(char *file_name)
{
	int	len;

	len = ft_strlen(file_name);
	if (len < 4 || ft_strcmp(file_name + len - 4, ".ber") != 0)
	{
		ft_printf("Error\nEncountered a mistake in the file: %s\n", file_name);
		exit (1);
	}
}
