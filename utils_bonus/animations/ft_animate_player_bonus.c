/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_animate_player_bonus.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: degabrie <degabrie@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/20 18:41:01 by degabrie          #+#    #+#             */
/*   Updated: 2021/12/06 21:39:45 by degabrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"so_long_bonus.h"

static int	ft_animate_player_left(t_game *game);
static int	ft_animate_player_right(t_game *game);
static int	ft_animate_player_up(t_game *game);
static int	ft_animate_player_down(t_game *game);

int	ft_animate_player(t_game *game)
{
	static int	key;

	key = game->key_press;
	if (key == LEFT)
		ft_animate_player_left(game);
	else if (key == UP)
		ft_animate_player_up(game);
	else if (key == DOWN)
		ft_animate_player_down(game);
	else
		ft_animate_player_right(game);
	return (0);
}

static int	ft_animate_player_left(t_game *game)
{
	static int	i;

	if (i == 3)
		mlx_put_image_to_window(game->mlx, game->win, game->player.p4.ptr,
			game->player.x, game->player.y);
	else if (i == 6)
		mlx_put_image_to_window(game->mlx, game->win, game->player.p5.ptr,
			game->player.x, game->player.y);
	else if (i == 9)
		mlx_put_image_to_window(game->mlx, game->win, game->player.p6.ptr,
			game->player.x, game->player.y);
	else if (i == 12)
	{
		mlx_put_image_to_window(game->mlx, game->win, game->player.p5.ptr,
			game->player.x, game->player.y);
		i = 0;
	}
	ft_delay(40);
	i++;
	return (0);
}

static int	ft_animate_player_right(t_game *game)
{
	static int	i;

	if (i == 3)
		mlx_put_image_to_window(game->mlx, game->win, game->player.p1.ptr,
			game->player.x, game->player.y);
	else if (i == 6)
		mlx_put_image_to_window(game->mlx, game->win, game->player.p2.ptr,
			game->player.x, game->player.y);
	else if (i == 9)
		mlx_put_image_to_window(game->mlx, game->win, game->player.p3.ptr,
			game->player.x, game->player.y);
	else if (i == 12)
	{
		mlx_put_image_to_window(game->mlx, game->win, game->player.p2.ptr,
			game->player.x, game->player.y);
		i = 0;
	}
	ft_delay(40);
	i++;
	return (0);
}

static int	ft_animate_player_up(t_game *game)
{
	static int	i;

	if (i == 3)
		mlx_put_image_to_window(game->mlx, game->win, game->player.p7.ptr,
			game->player.x, game->player.y);
	else if (i == 6)
		mlx_put_image_to_window(game->mlx, game->win, game->player.p8.ptr,
			game->player.x, game->player.y);
	else if (i == 9)
		mlx_put_image_to_window(game->mlx, game->win, game->player.p9.ptr,
			game->player.x, game->player.y);
	else if (i == 12)
	{
		mlx_put_image_to_window(game->mlx, game->win, game->player.p8.ptr,
			game->player.x, game->player.y);
		i = 0;
	}
	ft_delay(40);
	i++;
	return (0);
}

static int	ft_animate_player_down(t_game *game)
{
	static int	i;

	if (i == 3)
		mlx_put_image_to_window(game->mlx, game->win, game->player.pa.ptr,
			game->player.x, game->player.y);
	else if (i == 6)
		mlx_put_image_to_window(game->mlx, game->win, game->player.pb.ptr,
			game->player.x, game->player.y);
	else if (i == 9)
		mlx_put_image_to_window(game->mlx, game->win, game->player.pc.ptr,
			game->player.x, game->player.y);
	else if (i == 12)
	{
		mlx_put_image_to_window(game->mlx, game->win, game->player.pb.ptr,
			game->player.x, game->player.y);
		i = 0;
	}
	ft_delay(40);
	i++;
	return (0);
}
