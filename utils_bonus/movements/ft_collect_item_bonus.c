/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_collect_item_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: degabrie <degabrie@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/19 16:36:29 by degabrie          #+#    #+#             */
/*   Updated: 2021/10/20 15:59:04 by degabrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"../../so_long_bonus.h"

void	ft_collect_item(t_game *game)
{
	if (game->plan.map[(game->player.y / IMG)][(game->player.x / IMG)] != 'C')
		return ;
	game->plan.map[(game->player.y / IMG)][(game->player.x / IMG)] = '0';
	game->plan.c--;
}
