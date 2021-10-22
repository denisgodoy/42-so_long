/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exit_map_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: degabrie <degabrie@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/19 22:56:06 by degabrie          #+#    #+#             */
/*   Updated: 2021/10/21 22:02:56 by degabrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"../../so_long_bonus.h"

void	ft_exit_map(t_game *game)
{
	if (game->plan.map[(game->player.y / IMG)][(game->player.x / IMG)] == 'E')
	{
		printf(SUCCESS"\nCongratulations! Level Complete!\n"RESET);
		ft_free_game(game);
		exit(1);
	}
	else if (game->plan.map[(game->player.y / IMG)][(game->player.x / IMG)]
		== 'T')
	{
		printf(ERROR"\nGame Over! You Died!\n"RESET);
		ft_free_game(game);
		exit(1);
	}
	else if (game->key_press == ESC)
	{
		printf(WARNING"\nYou quit the game...\n"RESET);
		ft_free_game(game);
		exit(1);
	}
}
