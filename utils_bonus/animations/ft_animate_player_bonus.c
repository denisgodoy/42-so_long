/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_animate_player_bonus.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: degabrie <degabrie@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/20 18:41:01 by degabrie          #+#    #+#             */
/*   Updated: 2021/10/21 00:31:49 by degabrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"../../so_long_bonus.h"

int	ft_animate_player(t_game *game)
{
	static int	i;

	if (i == 3)
		mlx_put_image_to_window(game->mlx, game->win, game->player.p1.ptr,
			game->player.x, game->player.y);
	else if (i == 6)
		mlx_put_image_to_window(game->mlx, game->win, game->player.p2.ptr,
			game->player.x, game->player.y);
	else if (i == 9)
		mlx_put_image_to_window(game->mlx, game->win, game->player.p3.ptr,
			game->player.x, game->player.y);
	else if (i == 12)
	{
		mlx_put_image_to_window(game->mlx, game->win, game->player.p2.ptr,
			game->player.x, game->player.y);
		i = 0;
	}
	ft_delay(50);
	i++;
	return (0);
}
