/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_move_player.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: degabrie <degabrie@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/18 23:12:15 by degabrie          #+#    #+#             */
/*   Updated: 2021/10/19 00:02:02 by degabrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"../../so_long.h"

void	ft_move_player(t_game *game, int m)
{
	static int	movement;

	if (m == left && !(game->player.x <= IMGDIM))
	{
		game->player.x -= IMGDIM;
		movement++;
	}
	if (m == right && !(game->player.x >= (game->plan.width * IMGDIM) - IMGDIM))
	{
		game->player.x += IMGDIM;
		movement++;
	}
	if (m == up && !(game->player.y <= IMGDIM))
	{
		game->player.y -= IMGDIM;
		movement++;
	}
	if (m == down && !(game->player.y >= (game->plan.height * IMGDIM) - IMGDIM))
	{
		game->player.y += IMGDIM;
		movement++;
	}
	game->player.moves = movement;
}
