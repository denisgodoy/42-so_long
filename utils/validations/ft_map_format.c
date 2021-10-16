/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_format.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: degabrie <degabrie@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/15 17:52:14 by degabrie          #+#    #+#             */
/*   Updated: 2021/10/15 20:03:29 by degabrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"../../so_long.h"

static void	ft_horizontal(t_game *game);
static void	ft_vertical(t_game *game);

void	ft_map_format(t_game *game)
{
	if (game->map_utils.height == game->map_utils.width)
	{
		printf("Error\nMap is not rectangular\n");
		exit(1);
	}
	ft_horizontal(game);
	ft_vertical(game);
}

static void	ft_horizontal(t_game *game)
{
	int	h;
	int	w;

	w = 0;
	h = game->map_utils.height;
	while (game->map_utils.map[0][w])
	{
		if (game->map_utils.map[0][w] != '1')
		{
			printf("Error\nMap misconfiguration\n");
			exit(1);
		}
		w++;
	}
	w = 0;
	while (game->map_utils.map[h][w])
	{
		if (game->map_utils.map[h][w] != '1')
		{
			printf("Error\nMap misconfiguration\n");
			exit(1);
		}
		w++;
	}
}

static void	ft_vertical(t_game *game)
{
	int	h;
	int	w;

	h = 0;
	w = game->map_utils.width;
	while (game->map_utils.map[h])
	{
		if (game->map_utils.map[h][0] != '1')
		{
			printf("Error\nMap misconfiguration");
			exit(1);
		}
		h++;
	}
	h = 0;
	while (game->map_utils.map[h])
	{
		if (game->map_utils.map[h][w] != '1')
		{
			printf("Error\nMap misconfiguration");
			exit(1);
		}
		h++;
	}
}
