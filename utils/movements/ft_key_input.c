/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_key_input.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: degabrie <degabrie@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/14 00:44:47 by degabrie          #+#    #+#             */
/*   Updated: 2021/10/16 23:06:18 by degabrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"../../so_long.h"

int	ft_key_input(int key, t_game *game)
{
	int	x;
	int	y;

	x = game->player.x;
	y = game->player.y;
	if (key == LEFT)
		game->player.x -= IMG_SIZE;
	else if (key == RIGHT)
		game->player.x += IMG_SIZE;
	else if (key == UP)
		game->player.y -= IMG_SIZE;
	else if (key == DOWN)
		game->player.y += IMG_SIZE;
	else if (key == ESC)
		exit(1);
	mlx_clear_window(game->mlx, game->win);
	ft_make_map(game);
	mlx_put_image_to_window(game->mlx, game->win, game->player.p.ptr,
		game->player.x, game->player.y);
	return (0);
}
