/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chbuerge <chbuerge@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/02 13:05:44 by chbuerge          #+#    #+#             */
/*   Updated: 2023/09/13 16:57:42 by chbuerge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int main()
{
	mlx_t	*mlx;
	mlx = mlx_init(WIDTH, HEIGHT, "hello world", false);
	if (!mlx)
		return (1);
	mlx_loop(mlx);
	mlx_terminate(mlx);
	return (0);
}
/*
int32_t main(void)
{
	mlx_t *mlx;
	mlx = mlx_init(WIDTH, HEIGHT, "42BALLS", true);
	return (0);
}*/


