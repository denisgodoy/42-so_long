/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_walls.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: degabrie <degabrie@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/14 00:34:10 by degabrie          #+#    #+#             */
/*   Updated: 2021/10/19 00:00:07 by degabrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"../../so_long.h"

static void	ft_check_corners(t_game *game, int h, int w);
static void	ft_check_lines(t_game *game, int h, int w);

void	ft_put_walls(t_game *game, int h, int w)
{
	ft_check_lines(game, h, w);
	ft_check_corners(game, h, w);
}

static void	ft_check_corners(t_game *game, int h, int w)
{
	if (h == 0 && w == 0)
		mlx_put_image_to_window(game->mlx, game->win, game->wall_ur.ptr,
			(IMGDIM * w), (IMGDIM * h));
	else if (h == 0 && w == game->plan.width)
		mlx_put_image_to_window(game->mlx, game->win, game->wall_ul.ptr,
			(IMGDIM * w), (IMGDIM * h));
	else if (h == game->plan.height && w == 0)
		mlx_put_image_to_window(game->mlx, game->win, game->wall_bl.ptr,
			(IMGDIM * w), (IMGDIM * h));
	else if (h == game->plan.height && w == game->plan.width)
		mlx_put_image_to_window(game->mlx, game->win, game->wall_br.ptr,
			(IMGDIM * w), (IMGDIM * h));
}

static void	ft_check_lines(t_game *game, int h, int w)
{
	if (h > 0 && h < game->plan.height && w == 0)
		mlx_put_image_to_window(game->mlx, game->win, game->wall_r.ptr,
			(IMGDIM * w), (IMGDIM * h));
	else if (h > 0 && h < game->plan.height && w == game->plan.width)
		mlx_put_image_to_window(game->mlx, game->win, game->wall_l.ptr,
			(IMGDIM * w), (IMGDIM * h));
	else if (h == 0 && w > 0 && w < game->plan.width)
		mlx_put_image_to_window(game->mlx, game->win, game->wall_u.ptr,
			(IMGDIM * w), (IMGDIM * h));
	else if (h == game->plan.height && w > 0 && w < game->plan.width)
		mlx_put_image_to_window(game->mlx, game->win, game->wall_b.ptr,
			(IMGDIM * w), (IMGDIM * h));
	else
		mlx_put_image_to_window(game->mlx, game->win, game->wall_m.ptr,
			(IMGDIM * w), (IMGDIM * h));
}
