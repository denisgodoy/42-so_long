/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_game_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: degabrie <degabrie@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/21 15:55:04 by degabrie          #+#    #+#             */
/*   Updated: 2021/10/28 17:08:30 by degabrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"so_long_bonus.h"

static void	ft_free_player_img(t_game *game);
static void	ft_free_map_utils_img(t_game *game);
static void	ft_free_enemy_img(t_game *game);

void	ft_free_game(t_game *game)
{
	ft_free_player_img(game);
	ft_free_map_utils_img(game);
	ft_free_enemy_img(game);
	ft_free_map(game);
	mlx_destroy_window(game->mlx, game->win);
	mlx_destroy_display(game->mlx);
	free(game->mlx);
	return ;
}

static void	ft_free_player_img(t_game *game)
{
	mlx_destroy_image(game->mlx, game->player.p1.ptr);
	mlx_destroy_image(game->mlx, game->player.p2.ptr);
	mlx_destroy_image(game->mlx, game->player.p3.ptr);
	mlx_destroy_image(game->mlx, game->player.p4.ptr);
	mlx_destroy_image(game->mlx, game->player.p5.ptr);
	mlx_destroy_image(game->mlx, game->player.p6.ptr);
	mlx_destroy_image(game->mlx, game->player.p7.ptr);
	mlx_destroy_image(game->mlx, game->player.p8.ptr);
	mlx_destroy_image(game->mlx, game->player.p9.ptr);
	mlx_destroy_image(game->mlx, game->player.pa.ptr);
	mlx_destroy_image(game->mlx, game->player.pb.ptr);
	mlx_destroy_image(game->mlx, game->player.pc.ptr);
	return ;
}

static void	ft_free_map_utils_img(t_game *game)
{
	mlx_destroy_image(game->mlx, game->wall_b.ptr);
	mlx_destroy_image(game->mlx, game->wall_bl.ptr);
	mlx_destroy_image(game->mlx, game->wall_br.ptr);
	mlx_destroy_image(game->mlx, game->wall_l.ptr);
	mlx_destroy_image(game->mlx, game->wall_m.ptr);
	mlx_destroy_image(game->mlx, game->wall_r.ptr);
	mlx_destroy_image(game->mlx, game->wall_u.ptr);
	mlx_destroy_image(game->mlx, game->wall_ul.ptr);
	mlx_destroy_image(game->mlx, game->wall_ur.ptr);
	mlx_destroy_image(game->mlx, game->exit_c.ptr);
	mlx_destroy_image(game->mlx, game->exit_o.ptr);
	mlx_destroy_image(game->mlx, game->key.ptr);
	mlx_destroy_image(game->mlx, game->floor.ptr);
	return ;
}

static void	ft_free_enemy_img(t_game *game)
{
	mlx_destroy_image(game->mlx, game->enemy.p1.ptr);
	mlx_destroy_image(game->mlx, game->enemy.p2.ptr);
	mlx_destroy_image(game->mlx, game->enemy.p3.ptr);
	mlx_destroy_image(game->mlx, game->enemy.p4.ptr);
	mlx_destroy_image(game->mlx, game->enemy.p5.ptr);
	return ;
}
