/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: degabrie <degabrie@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/25 22:45:16 by degabrie          #+#    #+#             */
/*   Updated: 2021/09/27 02:53:02 by degabrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"so_long.h"

void	ft_keypress(int key_press)
{
	static int	n;

	n += key_press;
	printf("%d\n", n);
}

int	deal_key(void)
{
	ft_keypress(1);
	return (0);
}

int	main(void)
{
	void	*mlx_ptr;
	void	*win_ptr;
	int		x;
	int		temp_x;
	int		y;
	
	x = 600;
	temp_x = x;
	y = 350;
	mlx_ptr = mlx_init();
	win_ptr = mlx_new_window(mlx_ptr, x, y, "so_long");
	mlx_string_put(mlx_ptr, win_ptr, 300, 190, 0xF3F3F3, "hello 42");
	while (x && y)
	{
		mlx_pixel_put(mlx_ptr, win_ptr, --x, y, 0x25A60);
		if (!x)
		{
			x = temp_x;
			--y;
		}
	}
	mlx_key_hook(win_ptr, deal_key, (void *)0);
	mlx_loop(mlx_ptr);
}
