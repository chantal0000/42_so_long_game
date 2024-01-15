/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chbuerge <chbuerge@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 14:47:49 by chbuerge          #+#    #+#             */
/*   Updated: 2024/01/15 14:48:11 by chbuerge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

//function to initialize the map structure I/II
void	init_map_struct(t_map *map)
{
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
