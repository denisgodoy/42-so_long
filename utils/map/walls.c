/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   walls.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: degabrie <degabrie@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/14 00:34:10 by degabrie          #+#    #+#             */
/*   Updated: 2021/10/14 17:33:42 by degabrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"../../so_long.h"

void	ft_check_corners(t_ptr *ptr, int h, int w)
{
	if (h == 0 && w == 0)
		mlx_put_image_to_window(ptr->mlx, ptr->win, ptr->wall_ur.ptr,
			(40 * w), (40 * h));
	else if (h == 0 && w == ptr->map_utils.width)
		mlx_put_image_to_window(ptr->mlx, ptr->win, ptr->wall_ul.ptr,
			(40 * w), (40 * h));
	else if (h == ptr->map_utils.height && w == 0)
		mlx_put_image_to_window(ptr->mlx, ptr->win, ptr->wall_bl.ptr,
			(40 * w), (40 * h));
	else if (h == ptr->map_utils.height && w == ptr->map_utils.width)
		mlx_put_image_to_window(ptr->mlx, ptr->win, ptr->wall_br.ptr,
			(40 * w), (40 * h));
}

void	ft_check_lines(t_ptr *ptr, int h, int w)
{
	if (h > 0 && h < ptr->map_utils.height && w == 0)
		mlx_put_image_to_window(ptr->mlx, ptr->win, ptr->wall_r.ptr,
			(40 * w), (40 * h));
	else if (h > 0 && h < ptr->map_utils.height && w == ptr->map_utils.width)
		mlx_put_image_to_window(ptr->mlx, ptr->win, ptr->wall_l.ptr,
			(40 * w), (40 * h));
	else if (h == 0 && w > 0 && w < ptr->map_utils.width)
		mlx_put_image_to_window(ptr->mlx, ptr->win, ptr->wall_u.ptr,
			(40 * w), (40 * h));
	else if (h == ptr->map_utils.height && w > 0 && w < ptr->map_utils.width)
		mlx_put_image_to_window(ptr->mlx, ptr->win, ptr->wall_b.ptr,
			(40 * w), (40 * h));
	else
		mlx_put_image_to_window(ptr->mlx, ptr->win, ptr->wall_m.ptr,
			(40 * w), (40 * h));
}

void	ft_map_walls(t_ptr *ptr, int h, int w)
{
	ft_check_lines(ptr, h, w);
	ft_check_corners(ptr, h, w);
}
