/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: degabrie <degabrie@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/25 22:44:47 by degabrie          #+#    #+#             */
/*   Updated: 2021/10/13 22:09:17 by degabrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H
# include "minilibx-linux/mlx.h"
# include "42-libft/libft.h"
# include "42-gnl/get_next_line.h"
# include <stdio.h>
# include <fcntl.h>

# define UP 	119
# define DOWN 	115
# define LEFT 	97
# define RIGHT 	100
# define ESC	65307

typedef struct s_img
{
	void	*ptr;
	int		x;
	int		y;
}	t_img;

typedef struct s_ptr
{
	void	*mlx;
	void	*win;
	t_img	player;
	t_img	wall;
	t_img	wall_l;
	t_img	wall_r;
	t_img	wall_u;
	t_img	wall_b;
	t_img	wall_ul;
	t_img	wall_ur;
	t_img	wall_bl;
	t_img	wall_br;
	t_img	wall_m;
	t_img	floor;
	t_img	exit_c;
	t_img	exit_o;
	t_img	collect;
}	t_ptr;

#endif