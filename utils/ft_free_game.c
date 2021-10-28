/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_game.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: coder <coder@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/21 15:55:04 by degabrie          #+#    #+#             */
/*   Updated: 2021/10/28 19:34:17 by coder            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

static void	ft_free_map_utils_img(t_game *game);

void	ft_free_game(t_game *game)
{
	mlx_destroy_image(game->mlx, game->player.p.ptr);
	ft_free_map_utils_img(game);
	ft_free_map(game);
	mlx_destroy_window(game->mlx, game->win);
	mlx_destroy_display(game->mlx);
	free(game->mlx);
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
