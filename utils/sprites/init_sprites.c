/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_sprites.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: degabrie <degabrie@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/14 00:41:33 by degabrie          #+#    #+#             */
/*   Updated: 2021/10/14 00:41:59 by degabrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"../../so_long.h"

void	ft_player_img(t_ptr *ptr)
{
	int		y;
	int		x;

	ptr->player.x = 0;
	ptr->player.y = 0;
	ptr->player.ptr = mlx_xpm_file_to_image(ptr->mlx, "img/right1.xpm", &x, &y);
}

void	ft_map_img(t_ptr *ptr)
{
	int		y;
	int		x;

	ptr->wall_l.ptr = mlx_xpm_file_to_image(ptr->mlx, "img/wl.xpm", &x, &y);
	ptr->wall_r.ptr = mlx_xpm_file_to_image(ptr->mlx, "img/wr.xpm", &x, &y);
	ptr->wall_bl.ptr = mlx_xpm_file_to_image(ptr->mlx, "img/wbl.xpm", &x, &y);
	ptr->wall_ul.ptr = mlx_xpm_file_to_image(ptr->mlx, "img/wtl.xpm", &x, &y);
	ptr->wall_br.ptr = mlx_xpm_file_to_image(ptr->mlx, "img/wbr.xpm", &x, &y);
	ptr->wall_ur.ptr = mlx_xpm_file_to_image(ptr->mlx, "img/wtr.xpm", &x, &y);
	ptr->wall_u.ptr = mlx_xpm_file_to_image(ptr->mlx, "img/wb.xpm", &x, &y);
	ptr->wall_b.ptr = mlx_xpm_file_to_image(ptr->mlx, "img/wu.xpm", &x, &y);
	ptr->wall_m.ptr = mlx_xpm_file_to_image(ptr->mlx, "img/wm.xpm", &x, &y);
	ptr->floor.ptr = mlx_xpm_file_to_image(ptr->mlx, "img/water.xpm", &x, &y);
	ptr->exit_c.ptr = mlx_xpm_file_to_image(ptr->mlx, "img/exit1.xpm", &x, &y);
	ptr->exit_o.ptr = mlx_xpm_file_to_image(ptr->mlx, "img/exit2.xpm", &x, &y);
	ptr->collect.ptr = mlx_xpm_file_to_image(ptr->mlx, "img/key.xpm", &x, &y);
}

void	ft_img_init(t_ptr *ptr)
{
	ft_player_img(ptr);
	ft_map_img(ptr);
}
