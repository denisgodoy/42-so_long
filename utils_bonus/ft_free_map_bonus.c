/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_map_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: degabrie <degabrie@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/21 18:04:34 by degabrie          #+#    #+#             */
/*   Updated: 2021/10/21 18:04:56 by degabrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"../so_long_bonus.h"

void	ft_free_map(t_game *game)
{
	int	h;

	h = 0;
	while (game->plan.map[h])
	{
		free(game->plan.map[h]);
		h++;
	}
	free(game->plan.map);
}
