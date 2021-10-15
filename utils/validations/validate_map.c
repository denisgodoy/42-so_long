/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: degabrie <degabrie@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/14 15:43:39 by degabrie          #+#    #+#             */
/*   Updated: 2021/10/15 11:26:29 by degabrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"../../so_long.h"

static void	ft_map_char(t_game *game, char *map_read);
static void	ft_char_count(t_game *game);
static void	ft_map_size(t_game *game, char *map);

void	ft_valid_map(t_game *game, char *map_read)
{
	ft_map_char(game, map_read);
	ft_map_size(game, map_read);
	if (game->map_utils.height == game->map_utils.width)
	{
		printf("Error\nMap is not rectangular\n");
		exit(1);
	}
}

static void	ft_map_char(t_game *game, char *map_read)
{
	int	i;

	i = 0;
	game->counter.c = 0;
	game->counter.e = 0;
	game->counter.p = 0;
	while (map_read[i])
	{
		if (map_read[i] == 'C')
			game->counter.c++;
		else if (map_read[i] == 'P')
			game->counter.p++;
		else if (map_read[i] == 'E')
			game->counter.e++;
		else if (!ft_strchr("10CPE\n", map_read[i]))
		{
			printf("Error\nInvalid map\n");
			exit(1);
		}
		i++;
	}
	ft_char_count(game);
}

static void	ft_char_count(t_game *game)
{
	if (!(game->counter.c > 0 && game->counter.p == 1 && game->counter.e == 1))
	{
		printf("Error\nInvalid map\n");
		exit(1);
	}
}

static void	ft_map_size(t_game *game, char *map)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (map[i])
	{
		if (map[i] == '\n')
			j++;
		i++;
	}
	game->map_utils.width = ((i / (j + 1)) - 1);
	game->map_utils.height = j;
}
