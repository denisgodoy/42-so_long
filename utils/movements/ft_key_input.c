/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_key_input.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: degabrie <degabrie@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/14 00:44:47 by degabrie          #+#    #+#             */
/*   Updated: 2021/10/19 00:21:42 by degabrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"../../so_long.h"

int	ft_key_input(int key, t_game *game)
{
	game->player.moves = 0;
	if (key == LEFT)
		game->player.moves = ft_move_player(game, left);
	else if (key == RIGHT)
		game->player.moves = ft_move_player(game, right);
	else if (key == UP)
		game->player.moves = ft_move_player(game, up);
	else if (key == DOWN)
		game->player.moves = ft_move_player(game, down);
	else if (key == ESC)
		exit(1);
	mlx_clear_window(game->mlx, game->win);
	ft_make_map(game);
	mlx_put_image_to_window(game->mlx, game->win, game->player.p.ptr,
		game->player.x, game->player.y);
	return (0);
}
