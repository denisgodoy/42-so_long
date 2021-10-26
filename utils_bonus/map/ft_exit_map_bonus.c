/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exit_map_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: degabrie <degabrie@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/19 22:56:06 by degabrie          #+#    #+#             */
/*   Updated: 2021/10/26 18:14:56 by degabrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"../../so_long_bonus.h"

void	ft_exit_map(t_game *game)
{
	if (game->plan.map[(game->player.y / IMG)][(game->player.x / IMG)] == 'E')
	{
		printf(SUCCESS"Congratulations! Level Complete!\n"RESET);
		ft_free_game(game);
		exit(1);
	}
	else if (game->plan.map[(game->player.y / IMG)][(game->player.x / IMG)]
		== 'T')
	{
		printf(ERROR"Game Over! You Died!\n"RESET);
		ft_free_game(game);
		exit(1);
	}
	else if (game->key_press == ESC)
	{
		printf(WARNING"You quit the game...\n"RESET);
		ft_free_game(game);
		exit(1);
	}
}
