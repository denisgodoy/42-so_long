/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: degabrie <degabrie@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/25 22:44:47 by degabrie          #+#    #+#             */
/*   Updated: 2021/10/21 10:49:03 by degabrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_BONUS_H
# define SO_LONG_BONUS_H
# include "minilibx-linux/mlx.h"
# include "42-libft/libft.h"
# include "42-gnl/get_next_line.h"
# include <stdio.h>
# include <fcntl.h>
# include <time.h>

# define UP 	119
# define DOWN 	115
# define LEFT 	97
# define RIGHT	100
# define ESC	65307
# define IMG	40

enum e_direction
{
	left,
	right,
	up,
	down
};

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
	int		c;
	int		p;
	int		s;
	int		e;
}	t_map;

typedef struct s_player
{
	t_img	p1;
	t_img	p2;
	t_img	p3;
	t_img	p4;
	t_img	p5;
	t_img	p6;
	t_img	p7;
	t_img	p8;
	t_img	p9;
	t_img	pa;
	t_img	pb;
	t_img	pc;
	int		x;
	int		y;
	int		moves;
}	t_player;

typedef struct s_enemy
{
	t_img	p1;
	t_img	p2;
	t_img	p3;
	t_img	p4;
	t_img	p5;
	int		x;
	int		y;
}	t_enemy;

typedef struct s_game
{
	void		*mlx;
	void		*win;
	char		*filename;
	int			key_press;
	t_map		plan;
	t_player	player;
	t_img		wall_l;
	t_img		wall_r;
	t_img		wall_u;
	t_img		wall_b;
	t_img		wall_ul;
	t_img		wall_ur;
	t_img		wall_bl;
	t_img		wall_br;
	t_img		wall_m;
	t_img		floor;
	t_img		exit_c;
	t_img		exit_o;
	t_img		collect;
	t_enemy		enemy;
}	t_game;

int		ft_animate_player(t_game *game);
int		ft_animate_enemy(t_game *game);
int		ft_animations(t_game *game);
void	ft_check_args(int argc, char **argv, t_game *game);
void	ft_collect_item(t_game *game);
void	ft_delay(int ms);
void	ft_error_handler(char *str);
void	ft_img_init(t_game *game);
int		ft_key_input(int key, t_game *game);
void	ft_make_map(t_game *game);
void	ft_map_format(t_game *game);
void	ft_max_resolution(t_game *game);
int		ft_move_player(t_game *game, int move);
void	ft_put_walls(t_game *game, int h, int w);
char	*ft_read_map(t_game *game);
void	ft_validate_map_str(char *map);
void	ft_valid_map(t_game *game);
void	ft_exit_map(t_game *game);

#endif