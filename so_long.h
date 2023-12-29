/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chbuerge <chbuerge@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/29 13:41:57 by chbuerge          #+#    #+#             */
/*   Updated: 2023/12/29 18:43:47 by chbuerge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
// miniLibX - graphical interface library
#include <mlx.h>
// open
#include <fcntl.h>
// printf
#include <stdio.h>
// free
#include <stdlib.h>
// boolean function
# include <stdbool.h>
// write
#include <unistd.h>
# include "./libft/libft.h"
# define SO_LONG_H

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

// CHECK_MAP
void    check_map(char *current_row, t_map *map);
void    check_player(char *current_row, t_map *map);
void    check_exit(char *current_row, t_map *map);
void    check_wall(char *current_row, t_map *map);

// MAIN
int handle_error();

#endif
