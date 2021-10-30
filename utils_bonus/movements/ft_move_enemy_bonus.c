/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_move_enemy_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: degabrie <degabrie@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/23 13:02:22 by degabrie          #+#    #+#             */
/*   Updated: 2021/10/29 23:43:17 by degabrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"so_long_bonus.h"

static void	ft_check_position(t_game *game);
static void	ft_move_left_right(t_game *game, int h, int w);

int	ft_move_enemy(t_game *game)
{
	static int	i;

	i++;
	if (i == 30)
	{
		ft_check_position(game);
		i = 0;
	}
	return (0);
}

static void	ft_check_position(t_game *game)
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
			if (game->plan.map[h][w] == 'T' || game->plan.map[h][w] == 't')
			{
				ft_move_left_right(game, h, w);
				w++;
			}
			w++;
		}
		h++;
	}
	return ;
}

static void	ft_move_left_right(t_game *game, int h, int w)
{
	if (game->plan.map[h][w] == 't' && game->plan.map[h][w - 1] == '0')
	{
		mlx_put_image_to_window(game->mlx, game->win, game->floor.ptr,
			(IMG * w), (IMG * h));
		game->plan.map[h][w] = '0';
		game->plan.map[h][w - 1] = 't';
		ft_exit_map(game);
	}
	else if (game->plan.map[h][w] == 't' && game->plan.map[h][w - 1] != '0')
		game->plan.map[h][w] = 'T';
	else if (game->plan.map[h][w] == 'T' && game->plan.map[h][w + 1] == '0')
	{
		mlx_put_image_to_window(game->mlx, game->win, game->floor.ptr,
			(IMG * w), (IMG * h));
		game->plan.map[h][w] = '0';
		game->plan.map[h][w + 1] = 'T';
		ft_exit_map(game);
	}
	else if (game->plan.map[h][w] == 'T' && game->plan.map[h][w + 1] != '0')
		game->plan.map[h][w] = 't';
	return ;
}
