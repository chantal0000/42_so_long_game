/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chbuerge <chbuerge@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/29 18:34:45 by chbuerge          #+#    #+#             */
/*   Updated: 2024/01/13 12:43:31 by chbuerge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

// check exactly one player
int    check_map(char *current_row, t_map *map)
{
	//check_walls_and_shape(current_row, map);
   printf("%d\n", map->player->player_exists);
	if (check_player(current_row, map) == 1 )//|| !(map->player->player_exists))
		return (1);
   // check_exit(current_row, map);
    // check_collect(current_row);
	return (0);
}


void	check_walls_and_shape(char *current_row, t_map *map)
{
	while(*current_row)
	{
		if (map->rows == '0') // or last one
		{
			//printf("total number of lines %d\n", map->total_number_of_lines);
			if (*current_row != '1')
			{
				printf("Invalid character detected: %c\n", *current_row);
				handle_error(map);
			}
		}
		current_row++;
	}
}
// multiple players checker works
int	check_player(char *current_row, t_map *map)
{
	while (*current_row)
	{
		if ((*current_row == 'P' && !(map->player->player_exists)))
			map->player->player_exists = true;
		else if ((*current_row == 'P' && (map->player->player_exists)))
			return (1);
		current_row++;
	}
	return(0);
}

/*
void	allowed_chars(char *current_row)
{
	if (*current_row != 'E' || *current_row != '0' || *current_row != '1' || *current_row != 'P' || *current_row != 'C' || *current_row != '\n')
		handle_error(map);
}*/
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
                handle_error(map);
            }
            current_row++;
        }
}



// if line == 0 or last one? than str[i] muss 1 sein sonst error
// wenn line != pos 0 or last dann muss pos 0 == 1 sein und die ltzte position

