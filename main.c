/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: degabrie <degabrie@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/25 22:45:16 by degabrie          #+#    #+#             */
/*   Updated: 2021/10/22 10:10:38 by degabrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"so_long.h"

int	main(int argc, char **argv)
{
	char	*map_read;
	t_game	game;

	ft_check_args(argc, argv, &game);
	game.mlx = mlx_init();
	map_read = ft_read_map(&game);
	game.plan.map = ft_split(map_read, '\n');
	free(map_read);
	ft_valid_map(&game);
	game.win = mlx_new_window(game.mlx, ((game.plan.width + 1) * IMG),
			((game.plan.height + 1) * IMG), "./so_long");
	ft_img_init(&game);
	ft_make_map(&game);
	mlx_key_hook(game.win, &ft_key_input, &game);
	mlx_hook(game.win, X_DESTROY, (0L), &ft_close_window, &game);
	mlx_hook(game.win, X_EXPOSE, (1L << 15), &ft_move_window, &game);
	mlx_loop(game.mlx);
	return (0);
}
