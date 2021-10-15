/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: degabrie <degabrie@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/14 00:39:02 by degabrie          #+#    #+#             */
/*   Updated: 2021/10/14 23:59:34 by degabrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"../../so_long.h"

char	**ft_read_map(t_game *game)
{
	char	*map_read;
	int		fd;

	map_read = ft_strdup("");
	fd = open(game->filename, O_RDONLY);
	if (fd < 0)
	{
		printf("Error\nMap does not exist\n");
		close(fd);
		exit(1);
	}
	while (1)
	{
		map_read = ft_strjoin_free(map_read, get_next_line(fd));
		if (map_read[ft_strlen(map_read) - 1] != '\n')
			break ;
	}
	close(fd);
	ft_valid_map(game, map_read);
	return (ft_split(map_read, '\n'));
}

void	ft_make_map(t_game *game)
{
	int	h;
	int	w;

	h = 0;
	while (game->map_utils.map[h])
	{
		w = 0;
		while ((game->map_utils.map)[h][w])
		{
			if (game->map_utils.map[h][w] == '1')
				ft_map_walls(game, h, w);
			else if (game->map_utils.map[h][w] == 'P')
				mlx_put_image_to_window(game->mlx, game->win, game->player.ptr, (IMG_SIZE * w), (IMG_SIZE * h));
			else if (game->map_utils.map[h][w] == 'C')
				mlx_put_image_to_window(game->mlx, game->win, game->collect.ptr, (IMG_SIZE * w), (IMG_SIZE * h));
			else if (game->map_utils.map[h][w] == 'E')
			{
				if (!game->counter.c)
					mlx_put_image_to_window(game->mlx, game->win, game->exit_o.ptr, (IMG_SIZE * w), (IMG_SIZE * h));
				else
					mlx_put_image_to_window(game->mlx, game->win, game->exit_c.ptr, (IMG_SIZE * w), (IMG_SIZE * h));
			}
			else
				mlx_put_image_to_window(game->mlx, game->win, game->floor.ptr, (IMG_SIZE * w), (IMG_SIZE * h));
			w++;
		}
		h++;
	}
}
