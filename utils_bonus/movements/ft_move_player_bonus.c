/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_move_player_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: degabrie <degabrie@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/18 23:12:15 by degabrie          #+#    #+#             */
/*   Updated: 2021/10/20 15:58:54 by degabrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"../../so_long_bonus.h"

static int	ft_mid_walls(t_game *game, int move);
static int	ft_check_exit(t_game *game, int move);

int	ft_move_player(t_game *game, int move)
{
	static int	movement;

	if (move == left && !ft_mid_walls(game, left) && !(game->player.x <= IMG))
	{
		game->player.x -= IMG;
		return (++movement);
	}
	else if (move == right && !ft_mid_walls(game, right)
		&& !(game->player.x >= (game->plan.width * IMG) - IMG))
	{
		game->player.x += IMG;
		return (++movement);
	}
	else if (move == up && !ft_mid_walls(game, up) && !(game->player.y <= IMG))
	{
		game->player.y -= IMG;
		return (++movement);
	}
	else if (move == down && !ft_mid_walls(game, down)
		&& !(game->player.y >= (game->plan.height * IMG) - IMG))
	{
		game->player.y += IMG;
		return (++movement);
	}
	return (0);
}

static int	ft_mid_walls(t_game *game, int move)
{
	if (move == left
		&& (game->plan.map[(game->player.y / IMG)][((game->player.x / IMG) - 1)]
		== '1' || ft_check_exit(game, left)))
		return (1);
	else if (move == right
		&& (game->plan.map[(game->player.y / IMG)][((game->player.x / IMG) + 1)]
		== '1' || ft_check_exit(game, right)))
		return (1);
	else if (move == up
		&& (game->plan.map[((game->player.y / IMG) - 1)][(game->player.x / IMG)]
		== '1' || ft_check_exit(game, up)))
		return (1);
	else if (move == down
		&& (game->plan.map[((game->player.y / IMG) + 1)][(game->player.x / IMG)]
		== '1' || ft_check_exit(game, down)))
		return (1);
	return (0);
}

static int	ft_check_exit(t_game *game, int move)
{
	if (move == left
		&& game->plan.map[(game->player.y / IMG)][((game->player.x / IMG) - 1)]
		== 'E' && game->plan.c > 0)
		return (1);
	else if (move == right
		&& game->plan.map[(game->player.y / IMG)][((game->player.x / IMG) + 1)]
		== 'E' && game->plan.c > 0)
		return (1);
	else if (move == up
		&& game->plan.map[((game->player.y / IMG) - 1)][(game->player.x / IMG)]
		== 'E' && game->plan.c > 0)
		return (1);
	else if (move == down
		&& game->plan.map[((game->player.y / IMG) + 1)][(game->player.x / IMG)]
		== 'E' && game->plan.c > 0)
		return (1);
	return (0);
}
