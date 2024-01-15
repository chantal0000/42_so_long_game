/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chbuerge <chbuerge@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/29 13:41:30 by chbuerge          #+#    #+#             */
/*   Updated: 2024/01/15 10:17:50 by chbuerge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

// function to read the map and gather information
// calls the create map array function
t_map	*read_map(char *file_name)
{
	int fd;
	char *new_line;
	t_map *map;

	fd = 0;
	new_line = NULL;
	// check file_name here
	fd = open(file_name, O_RDONLY);
	if (fd == -1)
	{
		write(1, "Error\n", 6);
		exit(1);
	}
	map = malloc(sizeof(t_map));
	if (!map)
		return (NULL);
		// handle error
	init_map_struct(map);
	while ((new_line = get_next_line(fd)) != NULL)
	{
		// if (check_map(new_line, map) == 1)
		// 	ft_error(new_line, map, fd);
		// printf("rows: %d\n", map->rows);
		map->rows++;
		map->columns = (ft_strlen(new_line) - 1);
		free(new_line);
	}
	// here checken ob player, exit und walls exists?
	close(fd);
	create_map_array(file_name, map, fd);
	return(map);
}

int create_map_array(char *file_name, t_map *map, int fd)
{
	int k = 0;
	int l = 0;

	char *line = NULL;
	// open again to safe/copy the info array into my struct;
	fd = open(file_name, O_RDONLY);
	if (fd == -1)
	{
		printf("fd == -1, problem with input file\n");
		handle_error(map);
	}
	// allocate memory for the map array
	// + 1?
	map->map_array = malloc(sizeof(char *) * map->rows);
	if (!map->map_array)
		return (0);
	// handle error above
	k = 0;

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
	// I think it makes sense to check my map here?!
	map_check(map);
	//map->collectable = 0;
	init_game(map);

	return (0);
}
//function to check that the input is a .ber filetype
void	check_filetype(char *filename)
{
	int	len;

	len = ft_strlen(filename);
	if(len < 4 || ft_strcmp(filename + len - 4, ".ber") != 0)
	{
		printf("Error\n");
		exit (1);
	}
}


int main(int argc, char **argv)
{
    if (argc == 2)
	{
		check_filetype(argv[1]);
		read_map(argv[1]);
		//init_game();
	}
	return (0);
}

