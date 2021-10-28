/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: coder <coder@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/21 18:04:34 by degabrie          #+#    #+#             */
/*   Updated: 2021/10/28 19:34:26 by coder            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"../so_long.h"

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
	return ;
}
