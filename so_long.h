/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chbuerge <chbuerge@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/29 13:41:57 by chbuerge          #+#    #+#             */
/*   Updated: 2024/01/15 12:24:58 by chbuerge         ###   ########.fr       */
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
#include <stdbool.h>
// write
#include <unistd.h>
// NULL
#include <stddef.h>


# include "./libft/libft.h"

# define IMG_HEIGHT	64
# define IMG_WIDTH	64
/*
# define WALL		'1'
# define SPACE		'0'
# define PLAYER		'P'
# define MAP_EXIT	'E'
# define COLLECTABLE 'C'*/

# define SPACE_XPM "assets/space1.xpm"
# define WALLS_XPM "assets/walls.xpm"
# define PRICE_XPM "assets/collectable.xpm"
# define EXIT_XPM "assets/exit.xpm"
# define PLAYER_XPM "assets/smile.xpm"

// KEYS
# define W 119
# define A 97
# define S 115
# define D 100

# define UP 65362
# define LEFT 65361
# define DOWN 65364
# define RIGHT 65363

# define ESC 65307


typedef struct s_player
{
    bool player_exists;
}   t_player;

typedef struct s_exit
{
    bool exit_exists;
}   t_exit;

typedef struct s_collectable
{
    bool collectable_exists;
}   t_collectable;

typedef struct s_wall
{
    int count_lines;
	//??
	int	data;
} t_wall;

typedef struct s_map
{
    int fd;
	void *mlx;
	void *mlx_win;
    int wall;
    int player;
    int exit;
	int	collectable_total;
    int	collectable;
	int	columns;
	int	rows;
	char **map_array;
	int pos_player_x;
	int pos_player_y;
	int move_counter;
// not used yet:
	void *walls_image;
    void *space_image;
    void *player_image;
    void *price_image;
    void *exit_image;
    //struct s_map *next;
}	t_map;

// typedef struct s_image
// {
// 	void	*xpm_ptr;
// 	int			x;
// 	int			y;
// }	t_image;

// CHECK_MAP
int    check_map(char *current_row, t_map *map);
int    check_player(char *current_row, t_map *map);
void    check_exit(char *current_row, t_map *map);
void    check_walls_and_shape(char *current_row, t_map *map);

// MAIN
t_map		*read_map(char *file_name);
int		create_map_array(char *file_name, t_map *map, int fd);
void	init_map_struct(t_map *map);
void	init_map_struct_2(t_map *map);
void	check_filetype(char *filename);


// SO_LONG_UTILS
void handle_error(t_map *map);
void	ft_error(char *current_line, t_map *map, int fd);


//void	count_lines(t_map *map);

// GAME_SETUP
void	*put_img(t_map *map, char *img_path, int x, int y);
void	get_tiles(t_map *map);
void	init_game(t_map *map);

int	close_window_on_x(int event, t_map *map);


int check_next_field(int move, char key, t_map *map);
// GAME_PLAY
int		check_for_win(t_map *map);
int		key_hook(int keycode, t_map *map);
//void	check_next_field(int keycode, t_map *map);
int		check_next_field(int move, char key, t_map *map);


// FREE
void	clean_up(t_map *map);
void	free_array(t_map *map);


void	map_check(t_map *map);
int	check_square(t_map *map, int y);
int	check_walls(t_map *map, int y, int x);
int	check_chars(t_map *map, int y, int x);
void	clean_up_1(t_map *map);
int	check_player_exit_collect(t_map *map, int y, int x);
int	first_last(t_map *map, int y, int x);
int	first_last_col(t_map *map, int y);
void	check_filetype(char *file_name);
#endif
