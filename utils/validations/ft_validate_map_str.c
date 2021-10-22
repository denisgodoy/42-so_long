/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_validate_map_str.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: degabrie <degabrie@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/15 22:04:07 by degabrie          #+#    #+#             */
/*   Updated: 2021/10/21 22:13:03 by degabrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"../../so_long.h"

void	ft_validate_map_str(t_game *game, char *map)
{
	int	i;

	i = 0;
	if (map[i] == '\0')
	{
		free(map);
		ft_error_handler(game, "Error\nInvalid map", mlx);
	}
	while (map[i])
	{
		if (map[i] == '\n' && map[i + 1] != '1')
		{
			free(map);
			ft_error_handler(game, "Error\nInvalid map", mlx);
		}
		i++;
	}
}
