/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chbuerge <chbuerge@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/02 10:14:34 by chbuerge          #+#    #+#             */
/*   Updated: 2024/01/13 15:15:19 by chbuerge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_error(char *current_line, t_map *map, int fd)
{
	write(1, "Error\n", 6);
	free(current_line);
	close(fd);
	free(map);

	//current_line = 0;
	//clean_up(map);
	exit(1);
}



void	clean_up_1(t_map *map)
{
	printf("Error\n");
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
	map->fd = 0;
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

