/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: degabrie <degabrie@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/25 22:45:16 by degabrie          #+#    #+#             */
/*   Updated: 2021/10/14 23:11:00 by degabrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"so_long.h"

int	main(int argc, char **argv)
{
	t_game	game;

	ft_check_args(argc, argv, &game);
	game.mlx = mlx_init();
	game.map_utils.map = ft_read_map(&game);
	game.win = mlx_new_window(game.mlx, ((game.map_utils.width + 1) * 40), ((game.map_utils.height + 1) * 40), "so_long");
	ft_img_init(&game);
	ft_make_map(&game);
	mlx_key_hook(game.win, ft_key_input, &game);
	mlx_loop(game.mlx);
	return (0);
}
