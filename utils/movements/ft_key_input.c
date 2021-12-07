/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_key_input.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: degabrie <degabrie@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/14 00:44:47 by degabrie          #+#    #+#             */
/*   Updated: 2021/12/06 21:11:50 by degabrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"so_long.h"

static void	ft_print_moves(t_game *game);

int	ft_key_input(int key, t_game *game)
{
	game->player.moves = 0;
	if (key == LEFT || key == 0)
		game->player.moves = ft_move_player(game, left);
	else if (key == RIGHT || key == 2)
		game->player.moves = ft_move_player(game, right);
	else if (key == UP || key == 13)
		game->player.moves = ft_move_player(game, up);
	else if (key == DOWN || key == 1)
		game->player.moves = ft_move_player(game, down);
	else if (key == ESC || key == 53)
		ft_error_handler(game, "\nYou quit the game", clean);
	ft_print_moves(game);
	ft_collect_item(game);
	ft_exit_map(game);
	mlx_clear_window(game->mlx, game->win);
	ft_make_map(game);
	mlx_put_image_to_window(game->mlx, game->win, game->player.p.ptr,
		game->player.x, game->player.y);
	return (0);
}

static void	ft_print_moves(t_game *game)
{
	if (game->player.moves > 0)
	{
		ft_putstr_fd("\rMovements: ", 1);
		ft_putnbr_fd(game->player.moves, 1);
	}
}
