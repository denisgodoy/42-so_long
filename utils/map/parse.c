/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: degabrie <degabrie@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/14 00:39:02 by degabrie          #+#    #+#             */
/*   Updated: 2021/10/14 19:50:51 by degabrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"../../so_long.h"

char	**ft_read_map(t_ptr *ptr)
{
	char	*map_read;
	int		fd;

	map_read = ft_strdup("");
	fd = open(ptr->filename, O_RDONLY);
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
	ft_valid_map(ptr, map_read);
	return (ft_split(map_read, '\n'));
}

void	ft_make_map(t_ptr *ptr)
{
	int		h;
	int		w;
	int		collects;

	collects = 0;
	h = 0;
	while (ptr->map_utils.map[h])
	{
		w = 0;
		while ((ptr->map_utils.map)[h][w])
		{
			if (ptr->map_utils.map[h][w] == '1')
				ft_map_walls(ptr, h, w);
			else if (ptr->map_utils.map[h][w] == 'P')
				mlx_put_image_to_window(ptr->mlx, ptr->win, ptr->player.ptr, (40 * w), (40 * h));
			else if (ptr->map_utils.map[h][w] == 'C')
			{
				collects++;
				mlx_put_image_to_window(ptr->mlx, ptr->win, ptr->collect.ptr, (40 * w), (40 * h));
			}
			else if (ptr->map_utils.map[h][w] == 'E')
			{
				if (!collects)
					mlx_put_image_to_window(ptr->mlx, ptr->win, ptr->exit_o.ptr, (40 * w), (40 * h));
				else
					mlx_put_image_to_window(ptr->mlx, ptr->win, ptr->exit_c.ptr, (40 * w), (40 * h));
			}
			else
				mlx_put_image_to_window(ptr->mlx, ptr->win, ptr->floor.ptr, (40 * w), (40 * h));
			w++;
		}
		h++;
	}
}
