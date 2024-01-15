/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chbuerge <chbuerge@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/29 13:41:30 by chbuerge          #+#    #+#             */
/*   Updated: 2024/01/15 11:54:57 by chbuerge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

// function to read the map and gather information
// calls the create map array function
t_map	*read_map(char *file_name)
{
	int		fd;
	char	*new_line;
	t_map	*map;

	fd = 0;
	new_line = NULL;
	fd = open(file_name, O_RDONLY);
	if (fd == -1)
	{
		write(1, "Error\n", 6);
		exit(1);
	}
	map = malloc(sizeof(t_map));
	if (!map)
		return (NULL);
	init_map_struct(map);
	while ((new_line = get_next_line(fd)) != NULL)
	{
		map->rows++;
		map->columns = (ft_strlen(new_line) - 1);
		free(new_line);
	}
	close(fd);
	create_map_array (file_name, map, fd);
	return (map);
}

int	create_map_array(char *file_name, t_map *map, int fd)
{
	int k = 0;
	int l = 0;

	char *line = NULL;
	fd = open(file_name, O_RDONLY);
	if (fd == -1)
	{
		printf("fd == -1, problem with input file\n");
		handle_error(map);
	}
	map->map_array = malloc(sizeof(char *) * map->rows);
	if (!map->map_array)
		return (0);
	while ((line = get_next_line(fd)) != NULL && k < map->rows)
	{
		map->map_array[k] = ft_strdup(line);
		free(line);
		l = 0;
		while(map->map_array[k][l + 1] != '\0') {
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
	}
	map_check(map);
	init_game(map);
	return (0);
}

int	main(int argc, char **argv)
{
	if (argc == 2)
	{
		check_filetype(argv[1]);
		read_map(argv[1]);
	}
	return (0);
}
