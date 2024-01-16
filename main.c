/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chbuerge <chbuerge@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/29 13:41:30 by chbuerge          #+#    #+#             */
/*   Updated: 2024/01/16 14:08:54 by chbuerge         ###   ########.fr       */
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
	{
		free(map);
		ft_error("Error\nPlease add the Program 'so_long' and a valid Map\n");
	}
	return (0);
}
