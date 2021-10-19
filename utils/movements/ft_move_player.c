/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_move_player.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: degabrie <degabrie@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/18 23:12:15 by degabrie          #+#    #+#             */
/*   Updated: 2021/10/19 00:23:10 by degabrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"../../so_long.h"

int	ft_move_player(t_game *game, int move)
{
	static int	movement;

	if (move == left && !(game->player.x <= IMG_SIZE))
	{
		game->player.x -= IMG_SIZE;
		return (movement++);
	}
	else if (move == right
		&& !(game->player.x >= (game->plan.width * IMG_SIZE) - IMG_SIZE))
	{
		game->player.x += IMG_SIZE;
		return (movement++);
	}
	else if (move == up && !(game->player.y <= IMG_SIZE))
	{
		game->player.y -= IMG_SIZE;
		return (movement++);
	}
	else if (move == down
		&& !(game->player.y >= (game->plan.height * IMG_SIZE) - IMG_SIZE))
	{
		game->player.y += IMG_SIZE;
		return (movement++);
	}
	return (0);
}
