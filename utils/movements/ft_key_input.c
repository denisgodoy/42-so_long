/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_key_input.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: degabrie <degabrie@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/14 00:44:47 by degabrie          #+#    #+#             */
/*   Updated: 2021/10/18 23:29:00 by degabrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"../../so_long.h"

int	ft_key_input(int key, t_game *game)
{
	if (key == LEFT)
		ft_move_player(game, left);
	else if (key == RIGHT)
		ft_move_player(game, right);
	else if (key == UP)
		ft_move_player(game, up);
	else if (key == DOWN)
		ft_move_player(game, down);
	else if (key == ESC)
		exit(1);
	mlx_clear_window(game->mlx, game->win);
	ft_make_map(game);
	mlx_put_image_to_window(game->mlx, game->win, game->player.p.ptr,
		game->player.x, game->player.y);
	return (0);
}
