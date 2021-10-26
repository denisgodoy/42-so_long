/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: degabrie <degabrie@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/25 22:45:16 by degabrie          #+#    #+#             */
/*   Updated: 2021/10/26 18:11:01 by degabrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"so_long_bonus.h"

int	main(int argc, char **argv)
{
	char	*map_read;
	t_game	game;

	game.player.moves = 0;
	game.key_press = 0;
	ft_check_args(argc, argv, &game);
	game.mlx = mlx_init();
	map_read = ft_read_map(&game);
	game.plan.map = ft_split(map_read, '\n');
	free(map_read);
	ft_valid_map(&game);
	game.win = mlx_new_window(game.mlx, ((game.plan.width + 1) * IMG),
			((game.plan.height + 1) * IMG), "./so_long");
	mlx_set_font(game.mlx, game.win,
		"-misc-fixed-bold-r-normal--14-*-*-*-c-90-iso8859-1");
	ft_img_init(&game);
	ft_make_map(&game);
	mlx_key_hook(game.win, &ft_key_input, &game);
	mlx_hook(game.win, X_DESTROY, (0L), &ft_close_window, &game);
	mlx_hook(game.win, X_EXPOSE, (1L << 15), &ft_move_window, &game);
	mlx_loop_hook(game.mlx, &ft_animations, &game);
	mlx_loop(game.mlx);
	return (0);
}
