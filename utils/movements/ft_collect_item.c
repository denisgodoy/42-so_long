/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_collect_item.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: degabrie <degabrie@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/19 16:36:29 by degabrie          #+#    #+#             */
/*   Updated: 2021/10/19 20:44:52 by degabrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"../../so_long.h"

void	ft_collect_item(t_game *game)
{
	if (game->plan.map[(game->player.y / IMG)][(game->player.x / IMG)] != 'C')
		return ;
	game->plan.map[(game->player.y / IMG)][(game->player.x / IMG)] = '0';
	game->plan.c--;
}
