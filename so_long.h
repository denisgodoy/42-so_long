/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: degabrie <degabrie@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/25 22:44:47 by degabrie          #+#    #+#             */
/*   Updated: 2021/10/14 21:07:03 by degabrie         ###   ########.fr       */
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

typedef struct s_map
{
	int		height;
	int		width;
	char	**map;
}	t_map;

typedef struct s_ptr
{
	void	*mlx;
	void	*win;
	char	*filename;
	t_map	map_utils;
	t_img	player;
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

int		ft_check_ext(char *file);
void	ft_img_init(t_ptr *ptr);
void	ft_map_img(t_ptr *ptr);
void	ft_player_img(t_ptr *ptr);
int		ft_key_input(int key, t_ptr *ptr);
void	ft_make_map(t_ptr *ptr);
void	ft_map_walls(t_ptr *ptr, int h, int w);
void	ft_check_lines(t_ptr *ptr, int h, int w);
void	ft_check_corners(t_ptr *ptr, int h, int w);
char	**ft_read_map(t_ptr *ptr);
void	ft_map_char(char *map_read);
void	ft_map_format(t_ptr *ptr, char *map);
void	ft_valid_map(t_ptr *ptr, char *map_read);

#endif