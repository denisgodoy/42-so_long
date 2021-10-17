/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_max_resolution.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: degabrie <degabrie@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/17 03:46:00 by degabrie          #+#    #+#             */
/*   Updated: 2021/10/17 16:11:38 by degabrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"../../so_long.h"

void	ft_max_resolution(t_game *game)
{
	int	height;
	int	width;

	height = 0;
	width = 0;
	mlx_get_screen_size(game->mlx, &width, &height);
	width = (width * 90) / 100;
	height = (height * 80) / 100;
	if ((game->map_utils.height * IMG_SIZE) > height
		|| (game->map_utils.width * IMG_SIZE) > width)
	{
		printf("Max screen resolution: %dx%d\n", width, height);
		printf("Map resolution: %dx%d\n", game->map_utils.width * IMG_SIZE,
			game->map_utils.height * IMG_SIZE);
		ft_error_handler("Map is way too big");
	}
}
