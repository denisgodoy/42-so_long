/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_max_resolution.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: degabrie <degabrie@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/17 03:46:00 by degabrie          #+#    #+#             */
/*   Updated: 2021/10/21 22:12:38 by degabrie         ###   ########.fr       */
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
	if ((game->plan.height * IMG) > height
		|| (game->plan.width * IMG) > width)
	{
		printf("Max screen resolution: %dx%d\nMap resolution: %dx%d\n",
			width, height,
			game->plan.width * IMG,
			game->plan.height * IMG);
		ft_error_handler(game, "Error\nThe map is too big", map);
	}
}
