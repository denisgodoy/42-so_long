/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_max_resolution.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: degabrie <degabrie@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/17 03:46:00 by degabrie          #+#    #+#             */
/*   Updated: 2021/10/17 03:46:18 by degabrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"../../so_long.h"

void	ft_max_resolution(t_game *game)
{
	int	sizey;
	int	sizex;

	sizey = 0;
	sizex = 0;
	mlx_get_screen_size(game->mlx, &sizex, &sizey);
	if ((game->map_utils.height * IMG_SIZE) > (sizey / 1.1)
			|| (game->map_utils.width * IMG_SIZE) > (sizex / 1.05))
		ft_error_handler("Map is bigger than screen resolution");
}
