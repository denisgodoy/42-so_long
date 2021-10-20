/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exit_map_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: degabrie <degabrie@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/19 22:56:06 by degabrie          #+#    #+#             */
/*   Updated: 2021/10/20 16:13:32 by degabrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"../../so_long_bonus.h"

void	ft_exit_map(t_game *game)
{
	if (game->plan.map[(game->player.y / IMG)][(game->player.x / IMG)] == 'E')
	{
		printf("\033[1;32m\nCongratulations! Level Complete!\n\033[1m");
		exit(1);
	}
	else if (game->plan.map[(game->player.y / IMG)][(game->player.x / IMG)] == 'T')
	{
		printf("\033[1;31m\nGame Over! You Died!\n\033[1m");
		exit(1);
	}
/* 	else if (game->player.y == game->enemy.y && game->player.x == game->enemy.x)
	{
		printf("\033[1;31m\nGame Over! You Died!\n\033[1m");
		exit(1);
	} */
}
