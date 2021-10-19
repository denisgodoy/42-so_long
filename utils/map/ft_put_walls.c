/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_walls.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: degabrie <degabrie@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/14 00:34:10 by degabrie          #+#    #+#             */
/*   Updated: 2021/10/19 16:04:55 by degabrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"../../so_long.h"

static int	ft_check_corners(t_game *game, int h, int w);
static int	ft_check_lines(t_game *game, int h, int w);

void	ft_put_walls(t_game *game, int h, int w)
{
	if (!ft_check_lines(game, h, w) && !ft_check_corners(game, h, w))
		mlx_put_image_to_window(game->mlx, game->win, game->wall_m.ptr,
			(IMG * w), (IMG * h));
}

static int	ft_check_corners(t_game *game, int h, int w)
{
	if (h == 0 && w == 0)
	{
		mlx_put_image_to_window(game->mlx, game->win, game->wall_ur.ptr,
			(IMG * w), (IMG * h));
		return (1);
	}
	else if (h == 0 && w == game->plan.width)
	{
		mlx_put_image_to_window(game->mlx, game->win, game->wall_ul.ptr,
			(IMG * w), (IMG * h));
		return (1);
	}
	else if (h == game->plan.height && w == 0)
	{
		mlx_put_image_to_window(game->mlx, game->win, game->wall_bl.ptr,
			(IMG * w), (IMG * h));
		return (1);
	}
	else if (h == game->plan.height && w == game->plan.width)
	{
		mlx_put_image_to_window(game->mlx, game->win, game->wall_br.ptr,
			(IMG * w), (IMG * h));
		return (1);
	}
	return (0);
}

static int	ft_check_lines(t_game *game, int h, int w)
{
	if (h > 0 && h < game->plan.height && w == 0)
	{
		mlx_put_image_to_window(game->mlx, game->win, game->wall_r.ptr,
			(IMG * w), (IMG * h));
		return (1);
	}
	else if (h > 0 && h < game->plan.height && w == game->plan.width)
	{
		mlx_put_image_to_window(game->mlx, game->win, game->wall_l.ptr,
			(IMG * w), (IMG * h));
		return (1);
	}
	else if (h == 0 && w > 0 && w < game->plan.width)
	{
		mlx_put_image_to_window(game->mlx, game->win, game->wall_u.ptr,
			(IMG * w), (IMG * h));
		return (1);
	}
	else if (h == game->plan.height && w > 0 && w < game->plan.width)
	{
		mlx_put_image_to_window(game->mlx, game->win, game->wall_b.ptr,
			(IMG * w), (IMG * h));
		return (1);
	}
	return (0);
}
