/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chbuerge <chbuerge@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/29 18:34:45 by chbuerge          #+#    #+#             */
/*   Updated: 2023/12/29 18:35:12 by chbuerge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"


void    check_map(char *current_row, t_map *map)
{
    // check_walls(current_row, map);
    check_player(current_row, map);
    check_exit(current_row, map);
    // check_collect(current_row);
}
// multiple players checker works
// no player checker works
void    check_player(char *current_row, t_map *map)
{
        while (*current_row)
        {
            if ((*current_row == 'P' && !(map->player->player_exists)))
            {
                map->player->player_exists = true;
                printf("Player found\n");
            }
            else if ((*current_row == 'P' && (map->player->player_exists)))
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
