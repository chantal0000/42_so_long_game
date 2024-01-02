/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chbuerge <chbuerge@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/29 13:41:30 by chbuerge          #+#    #+#             */
/*   Updated: 2024/01/02 08:33:50 by chbuerge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

//initialize the struct?


int handle_error()
{
	write(1, "Error\n", 6);
	exit (1);
}


int    read_map(char *file_name)
{
   int fd;

    t_map *map = malloc(sizeof(t_map));
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

    map->wall->count = 0;
   char *new_line = NULL;

    fd = open(file_name, O_RDONLY);
    if (fd == -1)
    {
        printf("fd == -1, problem with input file\n");
        handle_error();
    }
   while  ((new_line = get_next_line(fd)) != NULL)
    {
        printf("%s", new_line);
        map->wall->count = map->wall->count + 1;
        check_map(new_line, map);


        //free(new_line);
    }
    printf("count lines: %d\n", map->wall->count);
	// checking here because in the check for player I always only check one line
    if ((!(map->player->player_exists)) || !(map->exit->exit_exists))
         handle_error();
    printf("\n");
    return (0);
}

int main(int argc, char **argv)
{
    if (argc == 2)
        read_map(argv[1]);

    return (0);
}
