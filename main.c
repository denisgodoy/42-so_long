/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: degabrie <degabrie@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/25 22:45:16 by degabrie          #+#    #+#             */
/*   Updated: 2021/10/09 01:03:37 by degabrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"so_long.h"

int	ft_key_input(int key, t_ptr *ptr)
{
	int			x;
	int			y;
	static int	movement;

	x = 0;
	y = 0;
	if (key == LEFT)
		ptr->player.x -= 5;
	else if (key == RIGHT)
		ptr->player.x += 5;
	else if (key == UP)
		ptr->player.y -= 5;
	else if (key == DOWN)
		ptr->player.y += 5;
	else if (key == ESC)
		exit(1);
	mlx_clear_window(ptr->mlx, ptr->win);
	printf("%d\n", ++movement);
	mlx_put_image_to_window(ptr->mlx, ptr->win, ptr->player.ptr,
		ptr->player.x, ptr->player.y);
	return (0);
}

int	main(void)
{
	t_ptr	ptr;
	int		x;
	int		y;

	ptr.player.x = 0;
	ptr.player.y = 0;
	ptr.mlx = mlx_init();
	ptr.win = mlx_new_window(ptr.mlx, 600, 150, "so_long");
	ptr.player.ptr = mlx_xpm_file_to_image(ptr.mlx, "sprites/r1.xpm", &x, &y);
	mlx_hook(ptr.win, 2, (1L << 0), ft_key_input, &ptr);
	mlx_loop(ptr.mlx);
	return (0);
}
