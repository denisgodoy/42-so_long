/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_move_enemy_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: degabrie <degabrie@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/23 13:02:22 by degabrie          #+#    #+#             */
/*   Updated: 2021/10/28 17:07:58 by degabrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"so_long_bonus.h"

static void	ft_move_direction(t_game *game, int direction);
static void	ft_move_up_down(t_game *game, int move, int h, int w);
static void	ft_move_left_right(t_game *game, int move, int h, int w);

int	ft_move_enemy(t_game *game)
{
	static int	i;

	i++;
	if (i == 3)
		ft_move_direction(game, up);
	else if (i == 6)
		ft_move_direction(game, down);
	else if (i == 9)
		ft_move_direction(game, left);
	else if (i == 12)
	{
		ft_move_direction(game, right);
		i = 0;
	}
	return (0);
}

static void	ft_move_direction(t_game *game, int direction)
{
	static int	h;
	static int	w;

	if (h > game->plan.height)
		h = 0;
	while (game->plan.map[h])
	{
		if (w > game->plan.width)
			w = 0;
		while (game->plan.map[h][w])
		{
			if (game->plan.map[h][w] == 'T')
			{
				ft_move_up_down(game, direction, h, w);
				ft_move_left_right(game, direction, h, w);
				w++;
				return ;
			}
			w++;
		}
		h++;
	}
	return ;
}

static void	ft_move_up_down(t_game *game, int move, int h, int w)
{
	if (move == up && !(ft_strchr("1TC", game->plan.map[h - 1][w])))
	{
		mlx_put_image_to_window(game->mlx, game->win, game->floor.ptr,
			(IMG * w), (IMG * h));
		game->plan.map[h][w] = '0';
		game->plan.map[h - 1][w] = 'T';
	}
	else if (move == down && !(ft_strchr("1TC", game->plan.map[h + 1][w])))
	{
		mlx_put_image_to_window(game->mlx, game->win, game->floor.ptr,
			(IMG * w), (IMG * h));
		game->plan.map[h][w] = '0';
		game->plan.map[h + 1][w] = 'T';
	}
	ft_exit_map(game);
	return ;
}

static void	ft_move_left_right(t_game *game, int move, int h, int w)
{
	if (move == left && !(ft_strchr("1TC", game->plan.map[h][w - 1])))
	{
		mlx_put_image_to_window(game->mlx, game->win, game->floor.ptr,
			(IMG * w), (IMG * h));
		game->plan.map[h][w] = '0';
		game->plan.map[h][w - 1] = 'T';
	}
	else if (move == right && !(ft_strchr("1TC", game->plan.map[h][w + 1])))
	{
		mlx_put_image_to_window(game->mlx, game->win, game->floor.ptr,
			(IMG * w), (IMG * h));
		game->plan.map[h][w] = '0';
		game->plan.map[h][w + 1] = 'T';
	}
	ft_exit_map(game);
	return ;
}
