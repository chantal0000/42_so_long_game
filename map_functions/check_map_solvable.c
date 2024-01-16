/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_solvable.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chbuerge <chbuerge@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 12:30:45 by chbuerge          #+#    #+#             */
/*   Updated: 2024/01/16 20:39:22 by chbuerge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

// check that you can reach the exit and collectables from the pos of the player
// y and x mixed up??
int	flood_fill(t_map *tmp, int y, int x)
{
	if (tmp->map_array[y][x] == '1')
		return (0);
	if (tmp->map_array[y][x] == 'C')
		tmp->collectable_total--;
	if (tmp->map_array[y][x] == 'E')
	{
		tmp->exit = 1;
		return (0);
	}
	tmp->map_array[y][x] = '1';
	if (flood_fill(tmp, y + 1, x))
		return (1);
	if (flood_fill(tmp, y - 1, x))
		return (1);
	if (flood_fill(tmp, y, x + 1))
		return (1);
	if (flood_fill(tmp, y, x - 1))
		return (1);
	return (0);
}

void	free_tmp_array(char **array, int rows)
{
	int	i;

	i = 0;
	while (i < rows)
	{
		free(array[i]);
		i++;
	}
	free(array);
}

int	check_map_solvable(t_map *map)
{
	t_map	tmp;
	int		i;

	tmp.rows = map->rows;
	tmp.columns = map->columns;
	tmp.collectable_total = map->collectable_total;
	tmp.pos_player_x = map->pos_player_x;
	tmp.pos_player_y = map->pos_player_y;
	tmp.exit = 0;
	i = 0;
	tmp.map_array = (char **)malloc(sizeof(char *) * tmp.rows);
	if (!tmp.map_array)
	{
		ft_printf("Memory not allocated\n");
		exit(0);
	}
	while (i < tmp.rows)
	{
		tmp.map_array[i] = ft_strdup(map->map_array[i]);
		i++;
	}
	flood_fill(&tmp, tmp.pos_player_y, tmp.pos_player_x);
	if (!(tmp.exit == 1 && tmp.collectable_total == 0))
	{
		free_tmp_array(tmp.map_array, tmp.rows);
		return (1);
	}
	free_tmp_array(tmp.map_array, tmp.rows);
	return (0);
}
