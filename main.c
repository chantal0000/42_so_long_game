/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chbuerge <chbuerge@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/29 13:41:30 by chbuerge          #+#    #+#             */
/*   Updated: 2023/12/29 13:41:33 by chbuerge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "so_long.h"

typedef struct s_player
{
    bool player_exists;
    int x;
    int y;
}   t_player;

typedef struct s_exit
{
    bool exit_exists;
    int x;
    int y;
}   t_exit;

typedef struct s_wall
{
    int count;
} t_wall;

typedef struct s_map
{
    int fd;
    t_wall *wall;
    t_player *player;
    t_exit *exit;
    int collectable;
    //struct s_map *next;
}   t_map;


//initialize the struct?
char	*get_next_line(int fd);
void    check_player(char *current_row, t_map *map);
void    check_exit(char *current_row, t_map *map);

int handle_error()
{
    write(1, "Error\n", 6);
    exit (1);
}

void    check_map(char *current_row, t_map *map)
{
    // check_walls(current_row, map);
    check_player(current_row, map);
    check_exit(current_row, map);
    // check_collect(current_row);
}

void    check_player(char *current_row, t_map *map)
{
        while (*current_row)
        {
            if ((*current_row == 'P' && !(map->player->player_exists)))
            {
                map->player->player_exists = true;
                printf("Player found\n");
            }
            else if ((*current_row == 'P' && !(map->player->player_exists)))
            {
                printf("player already exists\n");
                handle_error();
            }
            current_row++;
        }
}

void    check_exit(char *current_row, t_map *map)
{
        while (*current_row)
        {
            if (*current_row == 'E' && !(map->exit->exit_exists))
            {
                map->exit->exit_exists = true;
                printf("Exit found\n");
            }
            else if (*current_row == 'E' && map->exit->exit_exists)
            {
                printf("exit already exists\n");
                handle_error();
            }
            current_row++;
        }
}

void    check_wall(char *current_row, t_map *map)
{
    while (*current_row)
    {
        // 1 or last
        if (*current_row && map->wall->count == 1)
        {
            if (*current_row != 1)
                handle_error();
            current_row++;
        }
        current_row++;
    }
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
        printf("check 01E, fd == -1\n");
        return (1);
        // error handle
    }
   while  ((new_line = get_next_line(fd)) != NULL)
    {
        printf("%s", new_line);
        map->wall->count = map->wall->count + 1;
        check_map(new_line, map);


        //free(new_line);
    }
    printf("count lines: %d\n", map->wall->count);
    if (!(map->player->player_exists))
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
