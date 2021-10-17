/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_make_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: degabrie <degabrie@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/15 22:35:56 by degabrie          #+#    #+#             */
/*   Updated: 2021/10/17 01:28:36 by degabrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"../../so_long.h"

void	ft_make_map(t_game *game)
{
	int	h;
	int	w;

	h = 0;
	while (game->map_utils.map[h])
	{
		w = 0;
		while (game->map_utils.map[h][w])
		{
			ft_parse_line(game, h, w);
			w++;
		}
		h++;
	}
}
