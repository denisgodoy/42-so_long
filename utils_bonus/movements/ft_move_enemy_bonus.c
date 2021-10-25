/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_move_enemy_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: degabrie <degabrie@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/23 13:02:22 by degabrie          #+#    #+#             */
/*   Updated: 2021/10/25 16:55:46 by degabrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long_bonus.h"

static void	ft_move_up(t_game *game);
static void	ft_move_down(t_game *game);
static void	ft_move_left(t_game *game);
static void	ft_move_right(t_game *game);

int ft_move_enemy(t_game *game)
{
	static int	i;

	i++;
	if (i == 10)
	{
		ft_move_up(game);
		ft_move_down(game);
	}
	else if (i == 20)
	{
		ft_move_left(game);
		ft_move_right(game);
		i = 0;
	}
	return (0);
}

static void	ft_move_up(t_game *game)
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
			if (game->plan.map[h][w] == 'T' && !(ft_strchr("1TC", game->plan.map[h - 1][w])))
			{
				mlx_put_image_to_window(game->mlx, game->win, game->floor.ptr,
					(IMG * w), (IMG * h));
				game->plan.map[h][w] = '0';

				game->plan.map[h - 1][w] = 'T';
				w++;
				return ;
			}
			w++;
		}
		h++;
	}
	return ;
}


static void	ft_move_down(t_game *game)
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
			if (game->plan.map[h][w] == 'T' && !(ft_strchr("1TC", game->plan.map[h + 1][w])))
			{
				mlx_put_image_to_window(game->mlx, game->win, game->floor.ptr,
					(IMG * w), (IMG * h));
				game->plan.map[h][w] = '0';

				game->plan.map[h + 1][w] = 'T';
				w++;
				return ;
			}
			w++;
		}
		h++;
	}
	return ;
}


static void	ft_move_left(t_game *game)
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
			if (game->plan.map[h][w] == 'T' && !(ft_strchr("1TC", game->plan.map[h][w - 1])))
			{
				mlx_put_image_to_window(game->mlx, game->win, game->floor.ptr,
					(IMG * w), (IMG * h));
				game->plan.map[h][w] = '0';
				game->plan.map[h][w - 1] = 'T';
				w++;
				return ;
			}
			w++;
		}
		h++;
	}
	return ;
}


static void	ft_move_right(t_game *game)
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
			if (game->plan.map[h][w] == 'T' && !(ft_strchr("1TC", game->plan.map[h][w + 1])))
			{
				mlx_put_image_to_window(game->mlx, game->win, game->floor.ptr,
					(IMG * w), (IMG * h));
				game->plan.map[h][w] = '0';
				game->plan.map[h][w + 1] = 'T';
				w++;
				return ;
			}
			w++;
		}
		h++;
	}
	return ;
}
