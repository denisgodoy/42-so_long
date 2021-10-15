/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: degabrie <degabrie@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/25 22:45:16 by degabrie          #+#    #+#             */
/*   Updated: 2021/10/14 20:33:14 by degabrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"so_long.h"

int	main(int argc, char **argv)
{
	t_ptr	ptr;

	if (argc == 2 && !ft_check_ext(argv[1]))
		ptr.filename = argv[1];
	else if (argc < 2)
	{
	 	printf("Error\nPlease provide a map\n");
	 	exit(1);
	}
	else
	{
		if (ft_check_ext(argv[1]))
			printf("Error\nInvalid map extension\n");
		else
			printf("Error\nInvalid number of arguments\n");
		exit(1);
	}
	ptr.mlx = mlx_init();
	ptr.map_utils.map = ft_read_map(&ptr);
	ptr.win = mlx_new_window(ptr.mlx, ((ptr.map_utils.width + 1) * 40), ((ptr.map_utils.height + 1) * 40), "so_long");
	ft_img_init(&ptr);
	ft_make_map(&ptr);
	mlx_key_hook(ptr.win, ft_key_input, &ptr);
	mlx_loop(ptr.mlx);
	return (0);
}
