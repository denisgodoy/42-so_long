/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_animations_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: degabrie <degabrie@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/21 00:31:12 by degabrie          #+#    #+#             */
/*   Updated: 2021/10/28 17:07:30 by degabrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"so_long_bonus.h"

int	ft_animations(t_game *game)
{
	if (game->plan.t)
	{
		ft_animate_enemy(game);
		ft_move_enemy(game);
	}
	ft_animate_player(game);
	return (0);
}
