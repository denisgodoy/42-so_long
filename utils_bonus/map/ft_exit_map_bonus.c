/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exit_map_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: coder <coder@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/19 22:56:06 by degabrie          #+#    #+#             */
/*   Updated: 2021/10/28 19:23:22 by coder            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"../../so_long_bonus.h"

void	ft_exit_map(t_game *game)
{
	if (game->plan.map[(game->player.y / IMG)][(game->player.x / IMG)] == 'E')
	{
		printf(SUCCESS"Congratulations! Level Complete!\n"RESET);
		ft_free_game(game);
		exit(EXIT_SUCCESS);
	}
	else if (game->plan.map[(game->player.y / IMG)][(game->player.x / IMG)]
		== 'T')
	{
		printf(ERROR"Game Over! You Died!\n"RESET);
		ft_free_game(game);
		exit(EXIT_SUCCESS);
	}
	else if (game->key_press == ESC)
	{
		printf(WARNING"You quit the game...\n"RESET);
		ft_free_game(game);
		exit(EXIT_SUCCESS);
	}
	return ;
}
