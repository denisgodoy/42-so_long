/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   walls.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: degabrie <degabrie@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/14 00:34:10 by degabrie          #+#    #+#             */
/*   Updated: 2021/10/15 11:27:18 by degabrie         ###   ########.fr       */
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
			(IMG_SIZE * w), (IMG_SIZE * h));
	else if (h == 0 && w == game->map_utils.width)
		mlx_put_image_to_window(game->mlx, game->win, game->wall_ul.ptr,
			(IMG_SIZE * w), (IMG_SIZE * h));
	else if (h == game->map_utils.height && w == 0)
		mlx_put_image_to_window(game->mlx, game->win, game->wall_bl.ptr,
			(IMG_SIZE * w), (IMG_SIZE * h));
	else if (h == game->map_utils.height && w == game->map_utils.width)
		mlx_put_image_to_window(game->mlx, game->win, game->wall_br.ptr,
			(IMG_SIZE * w), (IMG_SIZE * h));
}

static void	ft_check_lines(t_game *game, int h, int w)
{
	if (h > 0 && h < game->map_utils.height && w == 0)
		mlx_put_image_to_window(game->mlx, game->win, game->wall_r.ptr,
			(IMG_SIZE * w), (IMG_SIZE * h));
	else if (h > 0 && h < game->map_utils.height && w == game->map_utils.width)
		mlx_put_image_to_window(game->mlx, game->win, game->wall_l.ptr,
			(IMG_SIZE * w), (IMG_SIZE * h));
	else if (h == 0 && w > 0 && w < game->map_utils.width)
		mlx_put_image_to_window(game->mlx, game->win, game->wall_u.ptr,
			(IMG_SIZE * w), (IMG_SIZE * h));
	else if (h == game->map_utils.height && w > 0 && w < game->map_utils.width)
		mlx_put_image_to_window(game->mlx, game->win, game->wall_b.ptr,
			(IMG_SIZE * w), (IMG_SIZE * h));
	else
		mlx_put_image_to_window(game->mlx, game->win, game->wall_m.ptr,
			(IMG_SIZE * w), (IMG_SIZE * h));
}
