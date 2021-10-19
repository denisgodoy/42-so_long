/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_max_resolution.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: degabrie <degabrie@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/17 03:46:00 by degabrie          #+#    #+#             */
/*   Updated: 2021/10/19 00:00:23 by degabrie         ###   ########.fr       */
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
	if ((game->plan.height * IMGDIM) > height
		|| (game->plan.width * IMGDIM) > width)
	{
		printf("Max screen resolution: %dx%d\nMap resolution: %dx%d\n",
			width, height,
			game->plan.width * IMGDIM,
			game->plan.height * IMGDIM);
		ft_error_handler("Map is way too big");
	}
}
