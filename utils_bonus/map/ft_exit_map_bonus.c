/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exit_map_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: degabrie <degabrie@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/19 22:56:06 by degabrie          #+#    #+#             */
/*   Updated: 2021/12/06 21:41:10 by degabrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"so_long_bonus.h"

void	ft_exit_map(t_game *game)
{
	if (game->plan.map[(game->player.y / IMG)][(game->player.x / IMG)] == 'E')
	{
		printf(SUCCESS"Congratulations! Level Complete!\n"RESET);
		ft_free_game(game);
		exit(EXIT_SUCCESS);
	}
	else if (game->plan.map[(game->player.y / IMG)][(game->player.x / IMG)]
		== 'T' || game->plan.map[(game->player.y / IMG)][(game->player.x / IMG)]
		== 't')
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
