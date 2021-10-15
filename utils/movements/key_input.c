/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_input.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: degabrie <degabrie@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/14 00:44:47 by degabrie          #+#    #+#             */
/*   Updated: 2021/10/14 19:48:28 by degabrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"../../so_long.h"

int	ft_key_input(int key, t_ptr *ptr)
{
	if (key == LEFT)
		ptr->player.x -= 40;
	else if (key == RIGHT)
		ptr->player.x += 40;
	else if (key == UP)
		ptr->player.y -= 40;
	else if (key == DOWN)
		ptr->player.y += 40;
	else if (key == ESC)
		exit(1);
	mlx_clear_window(ptr->mlx, ptr->win);
	ft_make_map(ptr);
	mlx_put_image_to_window(ptr->mlx, ptr->win, ptr->player.ptr,
		ptr->player.x, ptr->player.y);
	return (0);
}
