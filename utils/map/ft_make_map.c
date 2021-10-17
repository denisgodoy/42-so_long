/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_make_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: degabrie <degabrie@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/15 22:35:56 by degabrie          #+#    #+#             */
/*   Updated: 2021/10/16 22:28:15 by degabrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"../../so_long.h"

void	ft_make_map(t_game *game)
{
	int			h;
	int			w;
	static int	count;

	h = 0;
	while (game->map_utils.map[h])
	{
		w = 0;
		while (game->map_utils.map[h][w])
		{
			if (game->map_utils.map[h][w] == '1')
				ft_put_walls(game, h, w);
			else if (game->map_utils.map[h][w] == 'P' && !count)
			{
				game->player.x = (w * IMG_SIZE);
				game->player.y = (h * IMG_SIZE);
				mlx_put_image_to_window(game->mlx, game->win, game->player.p.ptr, (IMG_SIZE * w), (IMG_SIZE * h));
				count++;
			}
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
