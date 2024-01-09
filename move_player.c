/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chbuerge <chbuerge@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 09:10:19 by chbuerge          #+#    #+#             */
/*   Updated: 2024/01/05 09:35:12 by chbuerge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

// update the position of the player based on the key movements

// 1111111111111
// 10010000000C1
// 1000011111001
// 1P0011E0C0001
// 1111111111111

// current coordinates (x, y) -> (1, 3)
// if we press right key      -> (2, 3)

// if key == key_arrow_right
	// player x = x + 1
// else if key == key_arrow_left
	// player x = x - 1
// else if key == key_arrow_up
	// player y = y - 1
// else if key == key_arrow_down
	// player y = y + 1




int	key_hook(int keycode, t_vars *vars)
{
	printf("hello world\n");
	return (0);
}

