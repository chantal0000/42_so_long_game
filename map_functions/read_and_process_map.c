/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_and_process_map.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chbuerge <chbuerge@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 14:36:49 by chbuerge          #+#    #+#             */
/*   Updated: 2024/01/17 11:31:15 by chbuerge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

/*
** Reads the map file specified by file_name and initializes the t_map structure
** map with information such as the number of rows, columns, and the map array.
** calls the init_map_struct to init struct
** Calls the create_map_array function to create the map array.
*/
int	read_map(char *file_name, t_map *map)
{
	int		fd;
	char	*new_line;

	new_line = NULL;
	fd = open(file_name, O_RDONLY);
	if (fd == -1)
		ft_error("Error\nFailed to open file");
	init_map_struct(map);
	new_line = get_next_line(fd);
	while (new_line != NULL)
	{
		map->rows++;
		map->columns = (ft_strlen(new_line) - 1);
		free(new_line);
		new_line = get_next_line(fd);
	}
	close(fd);
	create_map_array (file_name, map, fd);
	return (0);
}

/*
** Creates the map array for the t_map structure map based on the file
** specified by file_name.
** Allocates memory for the map array, reads each line from the file,
** and processes it through the array_loop function.
*/
int	create_map_array(char *file_name, t_map *map, int fd)
{
	char	*new_line;

	new_line = NULL;
	fd = open(file_name, O_RDONLY);
	if (fd == -1)
		ft_error("Error\nFailed to open file");
	map->map_array = malloc(sizeof(char *) * map->rows);
	if (!map->map_array)
	{
		ft_printf("Memory not allocated\n");
		exit(0);
	}
	new_line = get_next_line(fd);
	array_loop(new_line, fd, map);
	close(fd);
	return (0);
}

/*
** helper function to process each line of the map array
*/
void	array_loop(char *new_line, int fd, t_map *map)
{
	int	k;
	int	l;

	k = 0;
	while (new_line != NULL && k < map->rows)
	{
		map->map_array[k] = ft_strdup(new_line);
		free(new_line);
		l = 0;
		while (map->map_array[k][l + 1] != '\0')
		{
			if (map->map_array[k][l] == 'P')
			{
				map->pos_player_x = l;
				map->pos_player_y = k;
			}
			if (map->map_array[k][l] == 'C')
				map->collectable_total++;
			l++;
		}
		k++;
		new_line = get_next_line(fd);
	}
}
