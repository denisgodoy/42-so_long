/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_valid_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: degabrie <degabrie@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/14 15:43:39 by degabrie          #+#    #+#             */
/*   Updated: 2021/10/16 03:35:39 by degabrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"../../so_long.h"

static void	ft_map_char(t_game *game);
static void	ft_map_size(t_game *game);

void	ft_valid_map(t_game *game)
{
	ft_map_size(game);
	ft_map_char(game);
	ft_map_format(game);
}

static void	ft_map_char(t_game *game)
{
	int	h;
	int	w;

	h = 0;
	game->counter.c = 0;
	game->counter.e = 0;
	game->counter.p = 0;
	while (game->map_utils.map[h])
	{
		w = 0;
		while (game->map_utils.map[h][w++])
		{
			if (game->map_utils.map[h][w] == 'C')
				game->counter.c++;
			else if (game->map_utils.map[h][w] == 'P')
				game->counter.p++;
			else if (game->map_utils.map[h][w] == 'E')
				game->counter.e++;
			else if (!ft_strchr("10CPE\n", game->map_utils.map[h][w]))
				ft_error_handler("Invalid map");
		}
		h++;
	}
	if (!(game->counter.c > 0 && game->counter.p == 1 && game->counter.e == 1))
		ft_error_handler("Invalid map");
}

static void	ft_map_size(t_game *game)
{
	int	h;
	int	w;
	int	w_len;

	h = 0;
	w_len = 0;
	while (game->map_utils.map[h])
	{
		w = 0;
		while (game->map_utils.map[h][w++])
			w_len++;
		h++;
	}
	game->map_utils.width = (w_len / h) - 1;
	game->map_utils.height = h - 1;
}
