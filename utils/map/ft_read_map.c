/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_read_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: degabrie <degabrie@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/14 00:39:02 by degabrie          #+#    #+#             */
/*   Updated: 2021/10/15 22:35:45 by degabrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"../../so_long.h"

char	*ft_read_map(t_game *game)
{
	char	*temp_map;
	char	*map_str;
	int		fd;

	map_str = ft_strdup("");
	fd = open(game->filename, O_RDONLY);
	if (fd < 0)
	{
		printf("Error\nMap does not exist\n");
		exit(1);
	}
	while (1)
	{
		temp_map = get_next_line(fd);
		if (!temp_map)
			break ;
		map_str = ft_strjoin_free(map_str, temp_map);
		free(temp_map);
	}
	close(fd);
	ft_validate_map_str(map_str);
	return (map_str);
}
