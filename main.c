/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chbuerge <chbuerge@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/29 13:41:30 by chbuerge          #+#    #+#             */
/*   Updated: 2024/01/09 17:18:27 by chbuerge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

//initialize the struct?

t_map	init_map(t_map *map)
{
    // whats a good place to put this all?
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

	///
	map->mlx = NULL;
	map->mlx_win = NULL;
	return(*map);
}

int	read_map(char *file_name)
{
	int fd;
	int k = 0;
	int l = 0;

	char *new_line = NULL;
	t_map *map = malloc(sizeof(t_map));
	if (!map)
		return (NULL);
	init_map(map);
	fd = open(file_name, O_RDONLY);
	printf("test 1\n");
	if (fd == -1)
	{
		printf("fd == -1, problem with input file\n");
		handle_error();
	}
	while ((new_line = get_next_line(fd)) != NULL)
	{
		printf("test 2\n");
        map->wall->count_lines = map->wall->count_lines + 1;
		printf("lines: %d\n", map->wall->count_lines);
		printf("test 3\n");
        check_map(new_line, map);
		map->rows++;
		map->columns = (ft_strlen(new_line) - 1);

		printf("col %d rows %d\n", map->columns, map->rows);
		//j++;
        //free(new_line);
    }
	close(fd);
///

  fd = open(file_name, O_RDONLY);
    if (fd == -1)
    {
        printf("fd == -1, problem with input file\n");
        handle_error();
    }

	map->map_array = malloc(sizeof(char *) * map->rows);
	if (!map->map_array)
		return NULL;
while(k < map->rows)
{
	map->map_array[k] = malloc(sizeof(char) * (map->columns + 1));
	k++;
}
// handle map_array[k] = NULL

k = 0;
while ((new_line = get_next_line(fd)) != NULL && k < map->rows)
{
		map->map_array[k] = new_line;

		l = 0;
		while(k < map->columns && new_line[l + 1] != '\0')
		{
			map->map_array[k][l] = new_line[l];
			printf("map->map_array[%d][%d]: %c\n", k, l, map->map_array[k][l]);
			l++;
		}
		printf("my line[%d]: %s \n", k, map->map_array[k]);
		k++;
}
///
		init_game(map);

	// printf("count_lines lines: %d\n", map->wall->count_lines);
	// checking here because in the check for player I always only check one line
    if ((!(map->player->player_exists)) || !(map->exit->exit_exists))
         handle_error();
    printf("\n");
    return (0);
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
