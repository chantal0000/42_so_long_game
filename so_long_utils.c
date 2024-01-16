/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chbuerge <chbuerge@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/02 10:14:34 by chbuerge          #+#    #+#             */
/*   Updated: 2024/01/16 20:38:04 by chbuerge         ###   ########.fr       */
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
	ft_printf("Error\nInvalid configuration detected in the map\n");
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

void	handle_error(t_map *map)
{
	write(1, "Error\n", 6);
	clean_up(map);
	// free all things here
	exit (1);
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


int	close_on_x(t_map *map)
{
	clean_up(map);
	exit(0);
	return (0);
}
