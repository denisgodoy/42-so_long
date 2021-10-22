/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_animate_enemy_bonus.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: degabrie <degabrie@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/21 00:27:15 by degabrie          #+#    #+#             */
/*   Updated: 2021/10/21 19:59:24 by degabrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"../../so_long_bonus.h"

int	ft_animate_enemy(t_game *game)
{
	static int	i;

	if (i == 3)
		mlx_put_image_to_window(game->mlx, game->win, game->enemy.p1.ptr,
			40, 40);
	else if (i == 6)
		mlx_put_image_to_window(game->mlx, game->win, game->enemy.p2.ptr,
			40, 40);
	else if (i == 9)
		mlx_put_image_to_window(game->mlx, game->win, game->enemy.p3.ptr,
			40, 40);
	else if (i == 12)
		mlx_put_image_to_window(game->mlx, game->win, game->enemy.p4.ptr,
			40, 40);
	else if (i == 15)
	{
		mlx_put_image_to_window(game->mlx, game->win, game->enemy.p5.ptr,
			40, 40);
		i = 0;
	}
	ft_delay(30);
	i++;
	return (0);
}
