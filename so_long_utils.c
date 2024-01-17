/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chbuerge <chbuerge@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/02 10:14:34 by chbuerge          #+#    #+#             */
/*   Updated: 2024/01/17 12:15:09 by chbuerge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/*
** error handling, write msg, exit
*/
void	ft_error(char *str, t_map *map)
{
	ft_printf("%s", str);
	free(map);
	map = NULL;
	exit(1);
}

/*
** free function in case there is a map/input error
*/
void	clean_up_map(char *str, t_map *map)
{
	ft_printf("%s", str);
	if (map->map_array)
		free_array(map);
	if (map->mlx_win)
		mlx_destroy_window(map->mlx, map->mlx_win);
	if (map->mlx)
		mlx_destroy_display(map->mlx);
	if (map->mlx)
		free(map->mlx);
	if (map)
		free(map);
	exit(1);
}

/*
** error handling, freeing map, exits
*/
void	handle_error(t_map *map)
{
	write(1, "Error\n", 6);
	clean_up(map);
	exit (1);
}
/*
** closing the game
*/

int	close_on_x(t_map *map)
{
	clean_up(map);
	exit(0);
	return (0);
}

/*
** checking the filetype for .ber
*/
int	check_filetype(char *file_name)
{
	int	len;

	len = ft_strlen(file_name);
	if (len < 4 || ft_strcmp(file_name + len - 4, ".ber") != 0)
	{
		ft_printf("Error\nEncountered a mistake in the file: %s\n", file_name);
		return (1);
	}
	return (0);
}
