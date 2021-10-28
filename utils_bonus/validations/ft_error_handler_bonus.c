/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error_handler_bonus.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: coder <coder@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/16 03:18:49 by degabrie          #+#    #+#             */
/*   Updated: 2021/10/28 19:18:23 by coder            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"../../so_long_bonus.h"

void	ft_error_handler(t_game *game, char *str, int clear)
{
	if (clear == clean)
	{
		printf("Error\n%s\n", str);
		ft_free_game(game);
		exit(EXIT_FAILURE);
	}
	else if (clear == mlx)
	{
		printf("Error\n%s\n", str);
		mlx_destroy_display(game->mlx);
		free(game->mlx);
		exit(EXIT_FAILURE);
	}
	else if (clear == map)
	{
		printf("Error\n%s\n", str);
		ft_free_map(game);
		mlx_destroy_display(game->mlx);
		free(game->mlx);
		exit(EXIT_FAILURE);
	}
	printf("Error\n%s\n", str);
	exit(EXIT_FAILURE);
}
