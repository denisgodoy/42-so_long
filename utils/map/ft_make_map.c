/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: degabrie <degabrie@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/15 22:35:56 by degabrie          #+#    #+#             */
/*   Updated: 2021/10/15 22:36:06 by degabrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"../../so_long.h"

void	ft_make_map(t_game *game)
{
	int	h;
	int	w;

	h = 0;
	while (game->map_utils.map[h])
	{
		w = 0;
		while (game->map_utils.map[h][w])
		{
			if (game->map_utils.map[h][w] == '1')
				ft_put_walls(game, h, w);
			else if (game->map_utils.map[h][w] == 'P')
				mlx_put_image_to_window(game->mlx, game->win, game->player.ptr, (IMG_SIZE * w), (IMG_SIZE * h));
			else if (game->map_utils.map[h][w] == 'C')
				mlx_put_image_to_window(game->mlx, game->win, game->collect.ptr, (IMG_SIZE * w), (IMG_SIZE * h));
			else if (game->map_utils.map[h][w] == 'E')
			{
				if (!game->counter.c)
					mlx_put_image_to_window(game->mlx, game->win, game->exit_o.ptr, (IMG_SIZE * w), (IMG_SIZE * h));
				else
					mlx_put_image_to_window(game->mlx, game->win, game->exit_c.ptr, (IMG_SIZE * w), (IMG_SIZE * h));
			}
			else
				mlx_put_image_to_window(game->mlx, game->win, game->floor.ptr, (IMG_SIZE * w), (IMG_SIZE * h));
			w++;
		}
		h++;
	}
}
