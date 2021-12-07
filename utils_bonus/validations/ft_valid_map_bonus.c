/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_valid_map_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: degabrie <degabrie@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/14 15:43:39 by degabrie          #+#    #+#             */
/*   Updated: 2021/12/06 21:15:24 by degabrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"so_long_bonus.h"

static void	ft_map_char(t_game *game);
static void	ft_map_size(t_game *game);
static void	ft_check_chars(t_game *game, int h, int w);

void	ft_valid_map(t_game *game)
{
	ft_map_size(game);
	ft_map_char(game);
	ft_map_format(game);
	return ;
}

static void	ft_map_char(t_game *game)
{
	int	h;
	int	w;

	h = 0;
	game->plan.c = 0;
	game->plan.p = 0;
	game->plan.e = 0;
	game->plan.s = 0;
	game->plan.t = 0;
	while (game->plan.map[h])
	{
		w = 0;
		while (game->plan.map[h][w])
		{
			ft_check_chars(game, h, w);
			w++;
		}
		h++;
	}
	if (!(game->plan.c > 0 && game->plan.p == 1 && game->plan.e == 1
			&& game->plan.s > 0))
		ft_error_handler(game, "Invalid map", map);
	return ;
}

static void	ft_map_size(t_game *game)
{
	int	h;
	int	w;
	int	line_len;

	h = 0;
	line_len = (int)ft_strlen(game->plan.map[h]);
	while (game->plan.map[h])
	{
		w = 0;
		while (game->plan.map[h][w])
			w++;
		if (w != line_len)
			ft_error_handler(game, "Map misconfiguration", map);
		h++;
	}
	game->plan.width = line_len - 1;
	game->plan.height = h - 1;
	return ;
}

static void	ft_check_chars(t_game *game, int h, int w)
{
	if (game->plan.map[h][w] == 'C')
		game->plan.c++;
	else if (game->plan.map[h][w] == 'P')
		game->plan.p++;
	else if (game->plan.map[h][w] == 'E')
		game->plan.e++;
	else if (game->plan.map[h][w] == '0')
		game->plan.s++;
	else if (game->plan.map[h][w] == 'T' || game->plan.map[h][w] == 't')
		game->plan.t++;
	else if (!(game->plan.map[h][w] == '1'))
		ft_error_handler(game, "Map misconfiguration", map);
	return ;
}
