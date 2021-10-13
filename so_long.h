/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: degabrie <degabrie@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/25 22:44:47 by degabrie          #+#    #+#             */
/*   Updated: 2021/10/13 17:09:10 by degabrie         ###   ########.fr       */
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
	t_img	wall_up;
	t_img	wall_btm;
	t_img	wall_corner_up_l;
	t_img	wall_corner_up_r;
	t_img	wall_corner_btm_l;
	t_img	wall_corner_btm_r;
	t_img	wall_middle;
	t_img	floor;
	t_img	exit;
	t_img	collect;
}	t_ptr;

#endif