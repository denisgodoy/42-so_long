/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: degabrie <degabrie@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/25 22:44:47 by degabrie          #+#    #+#             */
/*   Updated: 2021/10/17 01:27:29 by degabrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H
# include "minilibx-linux/mlx.h"
# include "42-libft/libft.h"
# include "42-gnl/get_next_line.h"
# include <stdio.h>
# include <fcntl.h>

# define UP 		119
# define DOWN 		115
# define LEFT 		97
# define RIGHT 		100
# define ESC		65307
# define IMG_SIZE	40

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

typedef struct s_count
{
	int	p;
	int	c;
	int	e;
}	t_count;

typedef struct s_player
{
	t_img 	p;
	int		x;
	int		y;
}	t_player;

typedef struct s_game
{
	void	*mlx;
	void	*win;
	char	*filename;
	t_count	counter;
	t_map	map_utils;
	t_player	player;
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
}	t_game;

void	ft_check_args(int argc, char **argv, t_game *game);
void	ft_img_init(t_game *game);
int		ft_key_input(int key, t_game *game);
void	ft_map_format(t_game *game);
void	ft_make_map(t_game *game);
void	ft_put_walls(t_game *game, int h, int w);
char	*ft_read_map(t_game *game);
void	ft_valid_map(t_game *game);
void	ft_validate_map_str(char *map);
void	ft_error_handler(char *str);
void	ft_parse_line(t_game *game, int h, int w);

#endif