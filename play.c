/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   play.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chbuerge <chbuerge@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 14:28:35 by chbuerge          #+#    #+#             */
/*   Updated: 2024/01/10 14:51:42 by chbuerge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

// function when key pressed figure out which tile to check next
// send map and location of tile to check_next_tile
// 1. key handle

void	handle_hook(int key, t_map *map)
{
	if (key == LEFT || key == A)
		printf("LEFT");
	else if(key == UP || W)
		printf("UP");
	else if(key == RIGHT || D)
		printf("RIGHT");
	else if(key == DOWN || S)
		printf("DOWN");
}


// move player
// when key pressed check next tile
	// if != '1'
		// if == '0'
void	check_next_tile(t_map *map, tile pos?)
{
	if
}
