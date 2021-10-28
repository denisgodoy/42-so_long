/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_validate_map_str.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: coder <coder@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/15 22:04:07 by degabrie          #+#    #+#             */
/*   Updated: 2021/10/28 19:33:03 by coder            ###   ########.fr       */
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
	return ;
}
