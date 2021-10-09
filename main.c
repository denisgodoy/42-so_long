/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: degabrie <degabrie@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/25 22:45:16 by degabrie          #+#    #+#             */
/*   Updated: 2021/10/08 23:09:04 by degabrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"so_long.h"

int	key_input(int key, t_ptr *ptr)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	if (key == LEFT)
		ptr->character.x -= 2;
	else if (key == RIGHT)
		ptr->character.x += 2;
	else if (key == UP)
		ptr->character.y -= 2;
	else if (key == DOWN)
		ptr->character.y += 2;
	else if (key == ESC)
		exit(1);
	mlx_clear_window(ptr->mlx_ptr, ptr->win_ptr);
	mlx_put_image_to_window(ptr->mlx_ptr, ptr->win_ptr, ptr->character.ptr, ptr->character.x, ptr->character.y);
	return (0);
}

int	main(void)
{
	t_ptr	ptr;
	int		x;
	int		y;

	ptr.character.x = 0;
	ptr.character.y = 0;
	ptr.mlx_ptr = mlx_init();
	ptr.win_ptr = mlx_new_window(ptr.mlx_ptr, 600, 150, "so_long");
	ptr.character.ptr = mlx_xpm_file_to_image(ptr.mlx_ptr, "sprites/r1.xpm", &x, &y);
	mlx_hook(ptr.win_ptr, 2, (1L << 0), key_input, &ptr);
	mlx_loop(ptr.mlx_ptr);
	return (0);
}
