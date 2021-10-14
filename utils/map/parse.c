/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: degabrie <degabrie@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/14 00:39:02 by degabrie          #+#    #+#             */
/*   Updated: 2021/10/14 02:41:13 by degabrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"../../so_long.h"

char	**ft_read_map(t_ptr *ptr)
{
	char	*map_read;
	char	*temp_read;
	int		fd;

	temp_read = ft_strdup("");
	fd = open(ptr->map, O_RDONLY);
	while (1)
	{
		map_read = ft_strjoin(temp_read, get_next_line(fd));
		temp_read = map_read;
		if (map_read[ft_strlen(map_read) - 1] != '\n')
			break ;
	}
	close(fd);
	ft_map_char(map_read);
	return (ft_split(map_read, '\n'));
}

void	ft_make_map(t_ptr *ptr)
{
	char	**map;
	int		h;
	int		w;
	int		collects;

	collects = 0;
	h = 0;
	map = ft_read_map(ptr);
	while (map[h])
	{
		w = 0;
		while (map[h][w])
		{
			if (map[h][w] == '1')
				ft_map_walls(ptr, h, w);
			else if (map[h][w] == 'P')
				mlx_put_image_to_window(ptr->mlx, ptr->win, ptr->player.ptr, (40 * w), (40 * h));
			else if (map[h][w] == 'C')
			{
				collects++;
				mlx_put_image_to_window(ptr->mlx, ptr->win, ptr->collect.ptr, (40 * w), (40 * h));
			}
			else if (map[h][w] == 'E')
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
