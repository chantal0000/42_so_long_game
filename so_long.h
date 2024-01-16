/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chbuerge <chbuerge@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/29 13:41:57 by chbuerge          #+#    #+#             */
/*   Updated: 2024/01/16 20:38:49 by chbuerge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

// miniLibX - graphical interface library
# include <mlx.h>
// OPEN
# include <fcntl.h>
// PRINTF
# include <stdio.h>
// FREE
# include <stdlib.h>
// WRITE
# include <unistd.h>
// NULL
# include <stddef.h>
// LIBFT
# include "./libft/libft.h"

# define IMG_HEIGHT	32
# define IMG_WIDTH	32

// IMAGE PATHS
# define SPACE_XPM "assets/background.xpm"
# define WALLS_XPM "assets/walls.xpm"
# define PRICE_XPM "assets/collectable.xpm"
# define EXIT_XPM "assets/exit.xpm"
# define PLAYER_XPM "assets/player.xpm"

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
	void	*mlx;
	void	*mlx_win;
	int		wall;
	int		player;
	int		exit;
	int		collectable_total;
	int		collectable;
	int		columns;
	int		rows;
	char	**map_array;
	int		pos_player_x;
	int		pos_player_y;
	int		move_counter;
	void	*walls_image;
	void	*space_image;
	void	*player_image;
	void	*price_image;
	void	*exit_image;
}	t_map;

// MAP_FUNCTIONS/READ_AND_PROCESS_MAP
int		read_map(char *file_name, t_map *map);
int		create_map_array(char *file_name, t_map *map, int fd);
void	array_loop(char *new_line, int fd, t_map *map);

// MAP_FUNCTIONS/MAP_CHECK.C
void	map_check(t_map *map);
int		first_last(t_map *map, int y, int x);
int		check_player_exit(t_map *map, int y, int x);
int		check_square(t_map *map, int y);
int		check_chars(t_map *map, int y, int x);

// MAP_FUNCTIONS/MAP_INIT.c
void	init_map_struct(t_map *map);
void	init_map_struct_2(t_map *map);

// MAP_FUNCTIONS/CHECK_MAP_SOLVABLE.C
int		check_map_solvable(t_map *map);

// SO_LONG_UTILS
void	ft_error(char *str);
void	clean_up_1(t_map *map);
void	handle_error(t_map *map);
int		close_on_x(t_map *map);
void	check_filetype(char *filename);

// GAME_SETUP
void	*put_img(t_map *map, char *img_path, int x, int y);
void	get_tiles(t_map *map);
void	init_game(t_map *map);
void	update_img(t_map *map, int x, int y);

// GAME_PLAY
int		check_for_win(t_map *map);
int		key_hook(int keycode, t_map *map);
int		check_next_field(int move, char key, t_map *map);
void	checking(t_map *map, int move, char pos);

// FREE
void	clean_up(t_map *map);
void	free_array(t_map *map);
void	check_filetype(char *file_name);
#endif
