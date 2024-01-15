/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chbuerge <chbuerge@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/29 13:41:30 by chbuerge          #+#    #+#             */
/*   Updated: 2024/01/15 14:37:11 by chbuerge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int argc, char **argv)
{
	t_map	*map;

	map = malloc(sizeof(t_map));
	if (!map)
		return (1);
	//HANDLE ERROR ABOVE
	if (argc == 2)
	{
		check_filetype(argv[1]);
		read_map(argv[1], map);
		map_check(map);
		init_game(map);
	}
	else
	// ERROR??
	return (0);
}
