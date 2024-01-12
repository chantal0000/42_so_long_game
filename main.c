/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chbuerge <chbuerge@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/29 13:41:30 by chbuerge          #+#    #+#             */
/*   Updated: 2024/01/12 16:34:45 by chbuerge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

//initialize the struct?

t_map	init_map_struct(t_map *map)
{
    //whats a good place to put this all?
	map->player = malloc(sizeof(t_player));
	map->exit = malloc(sizeof(t_exit));
	map->wall = malloc(sizeof(t_wall));
	map->player->player_exists = false;
	map->player->x = 0;
	map->player->y = 0;
	map->exit->exit_exists = false;
	map->exit->x = 0;
	map->exit->y = 0;
	map->total_number_of_lines = 0;
	map->wall->count_lines = 0;
	map->length_of_lines = 0;
	map->map_array = NULL;
	map->pos_player_x = 0;
	map->pos_player_y = 0;
	map->columns = 0;
	map->rows = 0;
	map->collectable = 0;
	map->collectable_total = 0;
	map->move_counter = 0;
	map->walls_image = NULL;
    map->space_image = NULL;
    map->player_image = NULL;
    map->price_image = NULL;
    map->exit_image = NULL;

	///
	map->mlx = NULL;
	map->mlx_win = NULL;

	//////


	return(*map);
}

t_map	*read_map(char *file_name)
{
	int fd;
	int k = 0;
	int l = 0;

	char *new_line = NULL;
	char *line = NULL;
	t_map *map = malloc(sizeof(t_map));
	if (!map)
		return (NULL);
	init_map_struct(map);
	// open the map to get information and do the input check
	fd = open(file_name, O_RDONLY);
	if (fd == -1)
	{
		printf("fd == -1, problem with input file\n");
		handle_error();
	}
	while ((new_line = get_next_line(fd)) != NULL)
	{
		map->rows++;
		map->columns = (ft_strlen(new_line) - 1);
		free(new_line);
    }
	//free(new_line);
	close(fd);

	// open again to safe/copy the info array into my struct;
	fd = open(file_name, O_RDONLY);
	if (fd == -1)
	{
		printf("fd == -1, problem with input file\n");
		handle_error();
	}
	// allocate memory for the map array
	// + 1?
	map->map_array = malloc(sizeof(char *) * map->rows);
	if (!map->map_array)
		return NULL;
	// allocate memory for the array in the array
/* 	while(k < map->rows)
	{

		map->map_array[k] = malloc(sizeof(char) * (map->columns + 1));
		//map->map_array[k] = malloc(sizeof(char *));
		if (!map->map_array[k])
			return NULL;
		k++;
	} */
	// fill the array
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
		//free(line);
	}		//printf("collactable total %d\n", map->collectable_total);
		// set up the game
		//free(line);
		init_game(map);

	// checking here because in the check for player I always only check one line
    if ((!(map->player->player_exists)) || !(map->exit->exit_exists))
         handle_error();
    printf("\n");
    return (map);
}

int main(int argc, char **argv)
{
    if (argc == 2)
	{
		read_map(argv[1]);
		//init_game();
	}
	return (0);
}
		//your old version
		// while(k < map->columns && new_line[l + 1] != '\0')
		// {
		// 	map->map_array[k][l] = new_line[l];
		// 	if (map->map_array[k][l] == 'P')
		// 	{
		// 		map->pos_player_x = l;
		// 		map->pos_player_y = k;
		// 	}
		// 	if (map->map_array[k][l] == 'C')
		// 		map->collectable_total++;

		// 	//printf("map->map_array[%d][%d]: %c\n", k, l, map->map_array[k][l]);
		// 	l++;
		// }
		//printf("my line[%d]: %s \n", k, map->map_array[k]);
		// if i free here it tells me i am trying to delete memory that is already freed
		//free(line);
