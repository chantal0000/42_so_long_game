/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chbuerge <chbuerge@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/10 13:00:45 by chbuerge          #+#    #+#             */
/*   Updated: 2023/08/02 17:56:24 by chbuerge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H
/*write*/
# include <unistd.h>
/* malloc */
# include <stdlib.h>
/* variadic functions */
# include <stdarg.h>
/* include libft */
# include "./libft/libft.h"

#include <stdio.h>

#include <stdbool.h>

#include "../MLX42/include/MLX42/MLX42.h"

#define WIDTH 512
#define HEIGHT 512

typedef struct s_mlx
{
	void	*mlx;
	void	*window;
}				t_mlx;

int main();

#endif
