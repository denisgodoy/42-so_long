/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exit_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: degabrie <degabrie@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/19 22:56:06 by degabrie          #+#    #+#             */
/*   Updated: 2021/10/21 18:37:23 by degabrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"../../so_long.h"

void	ft_exit_map(t_game *game)
{
	if (game->plan.map[(game->player.y / IMG)][(game->player.x / IMG)] == 'E')
	{
		printf("\033[1;32m\nCongratulations! Level Complete!\n\033[0m");
		ft_free_game(game);
		exit(1);
	}
}
