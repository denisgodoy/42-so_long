/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exit_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: degabrie <degabrie@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/19 22:56:06 by degabrie          #+#    #+#             */
/*   Updated: 2021/10/28 17:11:03 by degabrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"so_long.h"

void	ft_exit_map(t_game *game)
{
	if (game->plan.map[(game->player.y / IMG)][(game->player.x / IMG)] == 'E')
	{
		printf(SUCCESS"\nCongratulations! Level Complete!\n"RESET);
		ft_free_game(game);
		exit(EXIT_SUCCESS);
	}
	return ;
}
