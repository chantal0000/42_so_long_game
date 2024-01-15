/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_play.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chbuerge <chbuerge@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 14:28:35 by chbuerge          #+#    #+#             */
/*   Updated: 2024/01/15 16:18:14 by chbuerge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

// function to check for win and close game, add one final move to counter
int	check_for_win(t_map *map)
{
	if (map->collectable == map->collectable_total)
	{
		map->move_counter++;
		ft_printf("YOU WIN with %d moves\n", map->move_counter);
		clean_up(map);
		exit(0);
	}
	return (0);
}

// helper function for check_next_field
void	checking(t_map *map, int move, char pos)
{
	if (map->space_image != NULL)
		mlx_destroy_image(map->mlx, map->space_image);
	map->space_image
		= put_img(map, SPACE_XPM, map->pos_player_x, map->pos_player_y);
	if (pos == 'x')
		map->pos_player_x = map->pos_player_x + move;
	else if (pos == 'y')
		map->pos_player_y = map->pos_player_y + move;
	if (map->player_image != NULL)
		mlx_destroy_image(map->mlx, map->player_image);
	map->player_image
		= put_img(map, PLAYER_XPM, map->pos_player_x, map->pos_player_y);
	map->move_counter++;
	ft_printf("moves: %d\n", map->move_counter);
}

int	check_next_field(int move, char pos, t_map *map)
{
	int	i;
	int	j;

	i = map->pos_player_x;
	j = map->pos_player_y;
	if (pos == 'x')
		i = map->pos_player_x + move;
	else if (pos == 'y')
		j = map->pos_player_y + move;
	if ((map->map_array[j][i] == '0') ||
		(map->map_array[j][i] == 'C') || (map->map_array[j][i] == 'P'))
	{
		if (map->map_array[j][i] == 'C')
		{
			map->collectable++;
			map->map_array[j][i] = '0';
		}
		checking(map, move, pos);
	}
	else if (map->map_array[j][i] == 'E')
		check_for_win(map);
	return (0);
}
