/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: degabrie <degabrie@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/25 22:44:47 by degabrie          #+#    #+#             */
/*   Updated: 2021/12/06 21:34:19 by degabrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H
# include "../minilibx-mac/mlx.h"
# include "../42-libft/libft.h"
# include "../42-gnl/get_next_line.h"
# include <stdio.h>
# include <fcntl.h>

# define UP 			119
# define DOWN 			115
# define LEFT 			97
# define RIGHT			100
# define ESC			65307
# define IMG			36
# define SUCCESS		"\033[1;32m"
# define RESET   		"\033[0m"
# define X_DESTROY		17
# define X_EXPOSE		12

enum e_direction
{
	left,
	right,
	up,
	down
};

enum e_leave
{
	quit,
	clean,
	mlx,
	map
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
	t_img	p;
	int		x;
	int		y;
	int		moves;
}	t_player;

typedef struct s_game
{
	void		*mlx;
	void		*win;
	char		*filename;
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
	t_img		key;
}	t_game;

void	ft_check_args(int argc, char **argv, t_game *game);
int		ft_close_window(t_game *game);
void	ft_collect_item(t_game *game);
void	ft_error_handler(t_game *game, char *str, int clear);
void	ft_exit_map(t_game *game);
void	ft_free_game(t_game *game);
void	ft_free_map(t_game *game);
void	ft_img_init(t_game *game);
int		ft_key_input(int key, t_game *game);
void	ft_make_map(t_game *game);
void	ft_map_format(t_game *game);
int		ft_move_player(t_game *game, int move);
int		ft_move_window(t_game *game);
void	ft_put_walls(t_game *game, int h, int w);
char	*ft_read_map(t_game *game);
void	ft_validate_map_str(t_game *game, char *map);
void	ft_valid_map(t_game *game);

#endif
