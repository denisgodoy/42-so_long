/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_animate_enemy_bonus.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: degabrie <degabrie@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/21 00:27:15 by degabrie          #+#    #+#             */
/*   Updated: 2021/10/28 17:07:23 by degabrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"so_long_bonus.h"

static int	ft_enemy_line(t_game *game);
static int	ft_enemy_column(t_game *game);
static int	ft_slow_down(t_game *game);

int	ft_animate_enemy(t_game *game)
{
	static int	i;
	int			speed;

	i++;
	speed = ft_slow_down(game);
	if (i == 1 * speed)
		mlx_put_image_to_window(game->mlx, game->win, game->enemy.p1.ptr,
			(ft_enemy_column(game) * IMG), (ft_enemy_line(game) * IMG));
	else if (i == 2 * speed)
		mlx_put_image_to_window(game->mlx, game->win, game->enemy.p2.ptr,
			(ft_enemy_column(game) * IMG), (ft_enemy_line(game) * IMG));
	else if (i == 3 * speed)
		mlx_put_image_to_window(game->mlx, game->win, game->enemy.p3.ptr,
			(ft_enemy_column(game) * IMG), (ft_enemy_line(game) * IMG));
	else if (i == 4 * speed)
		mlx_put_image_to_window(game->mlx, game->win, game->enemy.p4.ptr,
			(ft_enemy_column(game) * IMG), (ft_enemy_line(game) * IMG));
	else if (i == 5 * speed)
	{
		if (!((game->plan.t + 1) % 5 == 0))
			mlx_put_image_to_window(game->mlx, game->win, game->enemy.p5.ptr,
				(ft_enemy_column(game) * IMG), (ft_enemy_line(game) * IMG));
		i = 0;
	}
	return (0);
}

static int	ft_enemy_line(t_game *game)
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
				w++;
				return (h);
			}
			w++;
		}
		h++;
	}
	return (-1);
}

static int	ft_enemy_column(t_game *game)
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
				w++;
				return (w - 1);
			}
			w++;
		}
		h++;
	}
	return (-1);
}

static int	ft_slow_down(t_game *game)
{
	int	speed;

	speed = 1;
	if (game->plan.t == 1)
		speed = 4;
	else if (game->plan.t == 2)
		speed = 3;
	return (speed);
}
