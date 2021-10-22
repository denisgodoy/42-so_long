/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error_handler_bonus.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: degabrie <degabrie@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/16 03:18:49 by degabrie          #+#    #+#             */
/*   Updated: 2021/10/21 22:18:17 by degabrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"../../so_long_bonus.h"

void	ft_error_handler(t_game *game, char *str, int clear)
{
	if (clear == clean)
	{
		printf("Error\n%s\n", str);
		ft_free_game(game);
		exit(1);
	}
	else if (clear == mlx)
	{
		printf("Error\n%s\n", str);
		mlx_destroy_display(game->mlx);
		free(game->mlx);
		exit(1);
	}
	else if (clear == map)
	{
		printf("Error\n%s\n", str);
		ft_free_map(game);
		mlx_destroy_display(game->mlx);
		free(game->mlx);
		exit(1);
	}
	printf("Error\n%s\n", str);
	exit(1);
}
