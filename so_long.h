/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chbuerge <chbuerge@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/29 13:41:57 by chbuerge          #+#    #+#             */
/*   Updated: 2024/01/15 12:36:41 by chbuerge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

// miniLibX - graphical interface library
#include <mlx.h>
// OPEN
#include <fcntl.h>
// PRINTF
#include <stdio.h>
// FREE
#include <stdlib.h>
// WRITE
#include <unistd.h>
// NULL
#include <stddef.h>
// LIBFT
# include "./libft/libft.h"

# define IMG_HEIGHT	64
# define IMG_WIDTH	64

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
	void *walls_image;
	void *space_image;
	void *player_image;
	void *price_image;
	void *exit_image;
}	t_map;


// MAIN.C
t_map		*read_map(char *file_name);
int		create_map_array(char *file_name, t_map *map, int fd);
void	init_map_struct(t_map *map);
void	init_map_struct_2(t_map *map);
void	check_filetype(char *filename);

// MAP_CHECK/MAP_CHECK.C
void	map_check(t_map *map);
int		first_last(t_map *map, int y, int x);
int		check_player_exit(t_map *map, int y, int x);
int		check_square(t_map *map, int y);
int		check_chars(t_map *map, int y, int x);

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






void	clean_up_1(t_map *map);



void	check_filetype(char *file_name);
#endif
