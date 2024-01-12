/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chbuerge <chbuerge@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 16:17:58 by chbuerge          #+#    #+#             */
/*   Updated: 2024/01/12 16:22:04 by chbuerge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"


// destroy display
// free mlx pointer
// destroy img?

// free array[i]
// free array
// free map

// ??
// free player, exit, wall

void	clean_up(t_map *map)
{
	int i;

	i = 0;
	while(i < map->rows)
	{
		free(map->map_array[i]);
		i++;
	}
	free(map->map_array);
	// what to put instead of WALLS_XPM
	mlx_destroy_image(map->mlx, map->walls_image);
	mlx_destroy_image(map->mlx, map->space_image);
	mlx_destroy_image(map->mlx, map->player_image);
	mlx_destroy_image(map->mlx, map->price_image);
	mlx_destroy_image(map->mlx, map->exit_image);

//	mlx_destroy_image(map->mlx, map->test1);
//	mlx_destroy_image(map->mlx, map->test2);

	mlx_destroy_window(map->mlx, map->mlx_win);
	mlx_destroy_display(map->mlx);
	//free(map->mlx);
	//free(map->mlx_win);
	free(map->player);
	free(map->exit);
	free(map->wall);
	free(map);
	//printf("all free lol %d \n", map->rows);
}

/////////////////////////////////////////
/*
void	ft_destroy_images(t_map *map)
{
	//mlx_destroy_image(map->mlx, map->img);
}

void	free_array(t_map *map)
{
	int i;

	i = 0;
	while(i < map->rows)
	{
		free(map->map_array[i]);
		i++;
	}
	free(map->map_array);
}




void	ft_free(t_map *map)
{
	free(map->player);
	free(map->exit);
	free(map->wall);
	free(map->player);
}*/
