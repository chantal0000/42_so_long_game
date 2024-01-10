/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chbuerge <chbuerge@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/29 13:41:57 by chbuerge          #+#    #+#             */
/*   Updated: 2024/01/10 18:56:31 by chbuerge         ###   ########.fr       */
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

# define IMG_HEIGHT	64
# define IMG_WIDTH	64
# define WALL		'1'
# define SPACE		'0'
# define PLAYER		'P'
# define MAP_EXIT	'E'
# define COLLECTABLE 'C'

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
//

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

typedef struct s_collectable
{
    bool collectable_exists;
    int x;
    int y;
}   t_collectable;

typedef struct s_wall
{
    int count_lines;
	int	data;
} t_wall;

typedef struct s_map
{
    int fd;
	void *mlx;
	void *mlx_win;
	int	total_number_of_lines;
	int length_of_lines;
    t_wall *wall;
    t_player *player;
    t_exit *exit;
    int collectable;
	int	columns;
	int	rows;
	char **map_array;
	int pos_player_x;
	int pos_player_y;
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
t_map	init_map_struct(t_map *map);


// SO_LONG_UTILS
void handle_error(void);

void	count_lines(t_map *map);

// GAME
void	init_game(t_map *map);

//PLAY

int	key_hook(int keycode, t_map *map);
//void	check_next_field(int keycode, t_map *map);
void	my_test_function();

#endif
