/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chbuerge <chbuerge@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/02 10:14:34 by chbuerge          #+#    #+#             */
/*   Updated: 2024/01/11 11:45:14 by chbuerge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void handle_error(void)
{
	write(1, "Error\n", 6);
	// free all things here
	exit (1);
}
/* NOT IN USE?
void	count_lines(t_map *map)
{
		map->total_number_of_lines++;
}*/
