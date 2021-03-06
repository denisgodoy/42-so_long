/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map_format_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: degabrie <degabrie@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/15 17:52:14 by degabrie          #+#    #+#             */
/*   Updated: 2021/10/28 17:10:30 by degabrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"so_long_bonus.h"

static void	ft_horizontal(t_game *game);
static void	ft_vertical(t_game *game);

void	ft_map_format(t_game *game)
{
	if (game->plan.height == game->plan.width)
		ft_error_handler(game, "Map is not rectangular", map);
	ft_horizontal(game);
	ft_vertical(game);
	return ;
}

static void	ft_horizontal(t_game *game)
{
	int	h;
	int	w;

	w = 0;
	h = game->plan.height;
	while (game->plan.map[0][w])
	{
		if (game->plan.map[0][w] != '1')
			ft_error_handler(game, "Map misconfiguration", map);
		w++;
	}
	w = 0;
	while (game->plan.map[h][w])
	{
		if (game->plan.map[h][w] != '1')
			ft_error_handler(game, "Map misconfiguration", map);
		w++;
	}
	return ;
}

static void	ft_vertical(t_game *game)
{
	int	h;
	int	w;

	h = 0;
	w = game->plan.width;
	while (game->plan.map[h])
	{
		if (game->plan.map[h][0] != '1')
			ft_error_handler(game, "Map misconfiguration", map);
		h++;
	}
	h = 0;
	while (game->plan.map[h])
	{
		if (game->plan.map[h][w] != '1')
			ft_error_handler(game, "Map misconfiguration", map);
		h++;
	}
	return ;
}
