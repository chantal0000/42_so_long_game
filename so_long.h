/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chbuerge <chbuerge@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/29 13:41:57 by chbuerge          #+#    #+#             */
/*   Updated: 2024/01/03 13:59:01 by chbuerge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

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

# define IMG_HEIGHT	320
# define IMG_WIDTH	320
# define WALL		'1'
# define SPACE		'0'
# define PLAYER		'P'
# define MAP_EXIT	'E'
# define COLLECTABLE 'C'

# define SPACE_XPM "assets/space.xpm"

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
    int count_lines;
	int	data;
} t_wall;

typedef struct s_map
{
    int fd;
	int	total_number_of_lines;
	int length_of_lines;
    t_wall *wall;
    t_player *player;
    t_exit *exit;
    int collectable;
    //struct s_map *next;
}	t_map;

typedef struct s_image
{
	void	*xpm_ptr;
	int			x;
	int			y;
}	t_image;

//
typedef struct	s_data {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_data;

// CHECK_MAP
void    check_map(char *current_row, t_map *map);
void    check_player(char *current_row, t_map *map);
void    check_exit(char *current_row, t_map *map);
void    check_walls_and_shape(char *current_row, t_map *map);

// MAIN

// SO_LONG_UTILS
void handle_error(void);

void	count_lines(t_map *map);

// GAME
void	init_game();


#endif
