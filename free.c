/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chbuerge <chbuerge@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 16:17:58 by chbuerge          #+#    #+#             */
/*   Updated: 2024/01/15 15:56:53 by chbuerge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	clean_up(t_map *map)
{
	if (map->map_array)
		free_array(map);
	if (map->walls_image)
		mlx_destroy_image(map->mlx, map->walls_image);
	if (map->space_image)
		mlx_destroy_image(map->mlx, map->space_image);
	if (map->player_image)
		mlx_destroy_image(map->mlx, map->player_image);
	if (map->price_image)
		mlx_destroy_image(map->mlx, map->price_image);
	if (map->exit)
		mlx_destroy_image(map->mlx, map->exit_image);
	if (map->mlx_win)
		mlx_destroy_window(map->mlx, map->mlx_win);
	if (map->mlx)
		mlx_destroy_display(map->mlx);
	if (map->mlx)
		free(map->mlx);
	if (map)
		free(map);
}

void	free_array(t_map *map)
{
	int	i;

	i = 0;
	while (i < map->rows)
	{
		free (map->map_array[i]);
		i++;
	}
	free (map->map_array);
}
