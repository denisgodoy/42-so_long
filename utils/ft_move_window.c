/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_move_window.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: degabrie <degabrie@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/22 09:47:55 by degabrie          #+#    #+#             */
/*   Updated: 2021/10/22 12:22:27 by degabrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	ft_move_window(t_game *game)
{
	ft_make_map(game);
	mlx_put_image_to_window(game->mlx, game->win, game->player.p.ptr,
		game->player.x, game->player.y);
	return (0);
}
