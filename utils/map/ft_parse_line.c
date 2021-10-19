/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: degabrie <degabrie@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/17 01:26:10 by degabrie          #+#    #+#             */
/*   Updated: 2021/10/18 23:59:52 by degabrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"../../so_long.h"

static void	ft_player_position(t_game *game, int h, int w);
static void	ft_count_collects(t_game *game, int h, int w);

void	ft_parse_line(t_game *game, int h, int w)
{
	static int	count;

	if (game->plan.map[h][w] == '1')
		ft_put_walls(game, h, w);
	else if (game->plan.map[h][w] == 'P' && !count)
	{
		ft_player_position(game, h, w);
		count++;
	}
	else if (game->plan.map[h][w] == 'C')
		mlx_put_image_to_window(game->mlx, game->win, game->collect.ptr,
			(IMGDIM * w), (IMGDIM * h));
	else if (game->plan.map[h][w] == 'E')
		ft_count_collects(game, h, w);
	else
		mlx_put_image_to_window(game->mlx, game->win, game->floor.ptr,
			(IMGDIM * w), (IMGDIM * h));
}

static void	ft_player_position(t_game *game, int h, int w)
{
	game->player.x = (w * IMGDIM);
	game->player.y = (h * IMGDIM);
	mlx_put_image_to_window(game->mlx, game->win, game->player.p.ptr,
		(IMGDIM * w), (IMGDIM * h));
}

static void	ft_count_collects(t_game *game, int h, int w)
{
	if (!game->counter.c)
		mlx_put_image_to_window(game->mlx, game->win, game->exit_o.ptr,
			(IMGDIM * w), (IMGDIM * h));
	else
		mlx_put_image_to_window(game->mlx, game->win, game->exit_c.ptr,
			(IMGDIM * w), (IMGDIM * h));
}
