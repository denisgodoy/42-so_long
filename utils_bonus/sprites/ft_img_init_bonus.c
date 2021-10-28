/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_img_init_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: degabrie <degabrie@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/14 00:41:33 by degabrie          #+#    #+#             */
/*   Updated: 2021/10/28 17:08:13 by degabrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"so_long_bonus.h"

static void	ft_player_img(t_game *game);
static void	ft_enemy_img(t_game *game);
static void	ft_map_img(t_game *game);

void	ft_img_init(t_game *game)
{
	ft_player_img(game);
	ft_enemy_img(game);
	ft_map_img(game);
}

static void	ft_player_img(t_game *game)
{
	int	y;
	int	x;

	game->player.p1.ptr = mlx_xpm_file_to_image(game->mlx, "img/7.xpm", &x, &y);
	game->player.p2.ptr = mlx_xpm_file_to_image(game->mlx, "img/8.xpm", &x, &y);
	game->player.p3.ptr = mlx_xpm_file_to_image(game->mlx, "img/9.xpm", &x, &y);
	game->player.p4.ptr = mlx_xpm_file_to_image(game->mlx, "img/4.xpm", &x, &y);
	game->player.p5.ptr = mlx_xpm_file_to_image(game->mlx, "img/5.xpm", &x, &y);
	game->player.p6.ptr = mlx_xpm_file_to_image(game->mlx, "img/6.xpm", &x, &y);
	game->player.p7.ptr = mlx_xpm_file_to_image(game->mlx, "img/a.xpm", &x, &y);
	game->player.p8.ptr = mlx_xpm_file_to_image(game->mlx, "img/b.xpm", &x, &y);
	game->player.p9.ptr = mlx_xpm_file_to_image(game->mlx, "img/c.xpm", &x, &y);
	game->player.pa.ptr = mlx_xpm_file_to_image(game->mlx, "img/1.xpm", &x, &y);
	game->player.pb.ptr = mlx_xpm_file_to_image(game->mlx, "img/2.xpm", &x, &y);
	game->player.pc.ptr = mlx_xpm_file_to_image(game->mlx, "img/3.xpm", &x, &y);
}

static void	ft_enemy_img(t_game *game)
{
	int	y;
	int	x;

	game->enemy.p1.ptr = mlx_xpm_file_to_image(game->mlx, "img/t1.xpm", &x, &y);
	game->enemy.p2.ptr = mlx_xpm_file_to_image(game->mlx, "img/t2.xpm", &x, &y);
	game->enemy.p3.ptr = mlx_xpm_file_to_image(game->mlx, "img/t3.xpm", &x, &y);
	game->enemy.p4.ptr = mlx_xpm_file_to_image(game->mlx, "img/t4.xpm", &x, &y);
	game->enemy.p5.ptr = mlx_xpm_file_to_image(game->mlx, "img/t5.xpm", &x, &y);
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
	game->exit_c.ptr = mlx_xpm_file_to_image(game->mlx, "img/e1.xpm", &x, &y);
	game->exit_o.ptr = mlx_xpm_file_to_image(game->mlx, "img/e2.xpm", &x, &y);
	game->key.ptr = mlx_xpm_file_to_image(game->mlx, "img/key.xpm", &x, &y);
}
