/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_key_input_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: degabrie <degabrie@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/14 00:44:47 by degabrie          #+#    #+#             */
/*   Updated: 2021/12/06 21:40:40 by degabrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"so_long_bonus.h"

static void	ft_put_image_to_window(t_game *game, int key);

int	ft_key_input(int key, t_game *game)
{
	if (key == LEFT)
		game->player.moves = ft_move_player(game, left);
	else if (key == RIGHT)
		game->player.moves = ft_move_player(game, right);
	else if (key == UP)
		game->player.moves = ft_move_player(game, up);
	else if (key == DOWN)
		game->player.moves = ft_move_player(game, down);
	else if (key == ESC)
	{
		game->key_press = key;
		ft_exit_map(game);
	}
	ft_collect_item(game);
	ft_exit_map(game);
	mlx_clear_window(game->mlx, game->win);
	ft_make_map(game);
	ft_put_image_to_window(game, key);
	return (0);
}

static void	ft_put_image_to_window(t_game *game, int key)
{
	if (key == LEFT)
	{
		mlx_put_image_to_window(game->mlx, game->win, game->player.p5.ptr,
			game->player.x, game->player.y);
		game->key_press = key;
	}
	else if (key == UP)
	{
		mlx_put_image_to_window(game->mlx, game->win, game->player.p8.ptr,
			game->player.x, game->player.y);
		game->key_press = key;
	}
	else if (key == DOWN)
	{
		mlx_put_image_to_window(game->mlx, game->win, game->player.pb.ptr,
			game->player.x, game->player.y);
		game->key_press = key;
	}
	else if (key == RIGHT)
	{
		mlx_put_image_to_window(game->mlx, game->win, game->player.p2.ptr,
			game->player.x, game->player.y);
		game->key_press = key;
	}
}
