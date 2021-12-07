/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error_handler_bonus.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: degabrie <degabrie@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/16 03:18:49 by degabrie          #+#    #+#             */
/*   Updated: 2021/12/06 21:14:34 by degabrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"so_long_bonus.h"

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
		free(game->mlx);
		exit(EXIT_FAILURE);
	}
	else if (clear == map)
	{
		printf("Error\n%s\n", str);
		ft_free_map(game);
		free(game->mlx);
		exit(EXIT_FAILURE);
	}
	printf("Error\n%s\n", str);
	exit(EXIT_FAILURE);
}
