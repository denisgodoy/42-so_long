/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: degabrie <degabrie@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/25 22:45:16 by degabrie          #+#    #+#             */
/*   Updated: 2021/10/14 00:43:48 by degabrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"so_long.h"

int	main(int argc, char **argv)
{
	t_ptr	ptr;
	char	*map;

	if (argc == 2 && !ft_check_ext(argv[1]))
		ptr.map = argv[1];
	else
	{
		if (ft_check_ext(argv[1]))
			printf("Error\nInvalid map extension\n");
		else
			printf("Error\nInvalid number of arguments\n");
		exit(1);
	}
	ptr.mlx = mlx_init();
	ptr.win = mlx_new_window(ptr.mlx, 520, 200, "so_long");
	ft_img_init(&ptr);
	mlx_key_hook(ptr.win, ft_key_input, &ptr);
	ft_make_map(&ptr);
	mlx_loop(ptr.mlx);
	return (0);
}
