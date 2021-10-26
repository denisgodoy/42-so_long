/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_make_map_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: degabrie <degabrie@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/15 22:35:56 by degabrie          #+#    #+#             */
/*   Updated: 2021/10/26 17:42:42 by degabrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"../../so_long_bonus.h"

static void	ft_parse_line(t_game *game, int h, int w);
static void	ft_player_position(t_game *game, int h, int w);
static void	ft_check_collects(t_game *game, int h, int w);
static void	ft_print_moves(t_game *game);

void	ft_make_map(t_game *game)
{
	int	h;
	int	w;

	h = 0;
	while (game->plan.map[h])
	{
		w = 0;
		while (game->plan.map[h][w])
		{
			ft_parse_line(game, h, w);
			w++;
		}
		h++;
	}
	ft_print_moves(game);
}

static void	ft_parse_line(t_game *game, int h, int w)
{
	static int	count;

	if (game->plan.map[h][w] == '1')
		ft_put_walls(game, h, w);
	else if (game->plan.map[h][w] == 'P' && !count)
	{
		ft_player_position(game, h, w);
		count++;
	}
	else if (game->plan.map[h][w] == 'C')
		mlx_put_image_to_window(game->mlx, game->win, game->key.ptr,
			(IMG * w), (IMG * h));
	else if (game->plan.map[h][w] == 'E')
		ft_check_collects(game, h, w);
	else if (game->plan.map[h][w] == 'T')
		mlx_put_image_to_window(game->mlx, game->win, game->enemy.p1.ptr,
			(IMG * w), (IMG * h));
	else
		mlx_put_image_to_window(game->mlx, game->win, game->floor.ptr,
			(IMG * w), (IMG * h));
}

static void	ft_player_position(t_game *game, int h, int w)
{
	game->player.x = (w * IMG);
	game->player.y = (h * IMG);
	mlx_put_image_to_window(game->mlx, game->win, game->player.p2.ptr,
		(IMG * w), (IMG * h));
}

static void	ft_check_collects(t_game *game, int h, int w)
{
	if (!game->plan.c)
		mlx_put_image_to_window(game->mlx, game->win, game->exit_o.ptr,
			(IMG * w), (IMG * h));
	else
		mlx_put_image_to_window(game->mlx, game->win, game->exit_c.ptr,
			(IMG * w), (IMG * h));
}

static void	ft_print_moves(t_game *game)
{
	char		*move;
	static int	temp_move;
	char		*last_move;

	move = ft_itoa(game->player.moves);
	if (move[0] == '0')
		free(move);
	mlx_string_put(game->mlx, game->win, 28, 22, 0x3f2905, "Moves: ");
	if (game->player.moves > 0)
	{
		temp_move = game->player.moves;
		mlx_string_put(game->mlx, game->win, 88, 22, 0x3f2905, move);
		free(move);
		return ;
	}
	last_move = ft_itoa(temp_move);
	mlx_string_put(game->mlx, game->win, 88, 22, 0x3f2905, last_move);
	free(last_move);
	return ;
}
