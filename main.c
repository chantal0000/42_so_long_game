/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chbuerge <chbuerge@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/29 13:41:30 by chbuerge          #+#    #+#             */
/*   Updated: 2024/01/17 10:58:38 by chbuerge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/*
** Beginning of the program
** checking that it is a .ber file,
** reading the map to get data
** checking and initalizing the map
** setting up and running the game
*/

int	main(int argc, char **argv)
{
	t_map	*map;

	map = malloc(sizeof(t_map));
	if (!map)
		ft_error("Error\nMemory allocation failed\n");
	if (argc == 2)
	{
		if (check_filetype(argv[1]) == 1)
		{
			free(map);
			exit (1);
		}
		read_map(argv[1], map);
		map_check(map);
		init_game(map);
	}
	else
	{
		free(map);
		ft_error("Error\nPlease run the Program with one '.ber' file\n");
	}
	return (0);
}
