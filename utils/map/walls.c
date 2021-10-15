/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   walls.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: degabrie <degabrie@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/14 00:34:10 by degabrie          #+#    #+#             */
/*   Updated: 2021/10/14 23:15:27 by degabrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"../../so_long.h"

static void	ft_check_corners(t_game *game, int h, int w);
static void	ft_check_lines(t_game *game, int h, int w);

void	ft_map_walls(t_game *game, int h, int w)
{
	ft_check_lines(game, h, w);
	ft_check_corners(game, h, w);
}

static void	ft_check_corners(t_game *game, int h, int w)
{
	if (h == 0 && w == 0)
		mlx_put_image_to_window(game->mlx, game->win, game->wall_ur.ptr,
			(40 * w), (40 * h));
	else if (h == 0 && w == game->map_utils.width)
		mlx_put_image_to_window(game->mlx, game->win, game->wall_ul.ptr,
			(40 * w), (40 * h));
	else if (h == game->map_utils.height && w == 0)
		mlx_put_image_to_window(game->mlx, game->win, game->wall_bl.ptr,
			(40 * w), (40 * h));
	else if (h == game->map_utils.height && w == game->map_utils.width)
		mlx_put_image_to_window(game->mlx, game->win, game->wall_br.ptr,
			(40 * w), (40 * h));
}

static void	ft_check_lines(t_game *game, int h, int w)
{
	if (h > 0 && h < game->map_utils.height && w == 0)
		mlx_put_image_to_window(game->mlx, game->win, game->wall_r.ptr,
			(40 * w), (40 * h));
	else if (h > 0 && h < game->map_utils.height && w == game->map_utils.width)
		mlx_put_image_to_window(game->mlx, game->win, game->wall_l.ptr,
			(40 * w), (40 * h));
	else if (h == 0 && w > 0 && w < game->map_utils.width)
		mlx_put_image_to_window(game->mlx, game->win, game->wall_u.ptr,
			(40 * w), (40 * h));
	else if (h == game->map_utils.height && w > 0 && w < game->map_utils.width)
		mlx_put_image_to_window(game->mlx, game->win, game->wall_b.ptr,
			(40 * w), (40 * h));
	else
		mlx_put_image_to_window(game->mlx, game->win, game->wall_m.ptr,
			(40 * w), (40 * h));
}
