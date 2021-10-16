/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_sprites.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: degabrie <degabrie@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/14 00:41:33 by degabrie          #+#    #+#             */
/*   Updated: 2021/10/14 23:56:21 by degabrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"../../so_long.h"

static void	ft_player_img(t_game *game);
static void	ft_map_img(t_game *game);

void	ft_img_init(t_game *game)
{
	ft_player_img(game);
	ft_map_img(game);
}

static void	ft_player_img(t_game *game)
{
	int	y;
	int	x;

	game->player.x = 0;
	game->player.y = 0;
	game->player.ptr = mlx_xpm_file_to_image(game->mlx, "img/right1.xpm", &x, &y);
}

static void	ft_map_img(t_game *game)
{
	int	y;
	int	x;

	game->wall_l.ptr = mlx_xpm_file_to_image(game->mlx, "img/wl.xpm", &x, &y);
	game->wall_r.ptr = mlx_xpm_file_to_image(game->mlx, "img/wr.xpm", &x, &y);
	game->wall_bl.ptr = mlx_xpm_file_to_image(game->mlx, "img/wbl.xpm", &x, &y);
	game->wall_ul.ptr = mlx_xpm_file_to_image(game->mlx, "img/wtl.xpm", &x, &y);
	game->wall_br.ptr = mlx_xpm_file_to_image(game->mlx, "img/wbr.xpm", &x, &y);
	game->wall_ur.ptr = mlx_xpm_file_to_image(game->mlx, "img/wtr.xpm", &x, &y);
	game->wall_u.ptr = mlx_xpm_file_to_image(game->mlx, "img/wb.xpm", &x, &y);
	game->wall_b.ptr = mlx_xpm_file_to_image(game->mlx, "img/wu.xpm", &x, &y);
	game->wall_m.ptr = mlx_xpm_file_to_image(game->mlx, "img/wm.xpm", &x, &y);
	game->floor.ptr = mlx_xpm_file_to_image(game->mlx, "img/water.xpm", &x, &y);
	game->exit_c.ptr = mlx_xpm_file_to_image(game->mlx, "img/exit1.xpm", &x, &y);
	game->exit_o.ptr = mlx_xpm_file_to_image(game->mlx, "img/exit2.xpm", &x, &y);
	game->collect.ptr = mlx_xpm_file_to_image(game->mlx, "img/key.xpm", &x, &y);
}
