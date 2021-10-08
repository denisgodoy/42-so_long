/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: degabrie <degabrie@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/25 22:45:16 by degabrie          #+#    #+#             */
/*   Updated: 2021/10/08 17:01:01 by degabrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"so_long.h"

typedef struct s_img
{
	void	*ptr;
	int		x;
	int		y;
} t_img;

typedef struct s_ptr
{
	void 	*mlx_ptr;
	void	*win_ptr;
	t_img	character;
	t_img	floor;
} t_ptr;

int	key_input(int key, t_ptr *ptr)
{
	int x;
	int y;

	x = 0;
	y = 0;
	if (key == 'a')
		ptr->character.x -= 20;
	else if (key == 'd')
		ptr->character.x += 20;
	else if (key == 'w')
		ptr->character.y -= 20;
	else if (key == 's')
		ptr->character.y += 20;
	else if (key == 'p')
		exit(1);
	mlx_clear_window(ptr->mlx_ptr, ptr->win_ptr);
	while (x < 10)
	{
	 	mlx_put_image_to_window(ptr->mlx_ptr, ptr->win_ptr, ptr->floor.ptr, (50 * x), 0);
	 	x++;
	}
	mlx_put_image_to_window(ptr->mlx_ptr, ptr->win_ptr, ptr->character.ptr, ptr->character.x,  ptr->character.y);
}

int	main(void)
{
	t_ptr ptr;
	int x;
	int y;

	ptr.character.x = 0;
	ptr.character.y = 0;

	ptr.mlx_ptr = mlx_init();
	ptr.win_ptr = mlx_new_window(ptr.mlx_ptr, 500, 150, "so_long");
	ptr.character.ptr = mlx_xpm_file_to_image(ptr.mlx_ptr, "sprites/zombie.xpm", &x, &y);
	ptr.floor.ptr = mlx_xpm_file_to_image(ptr.mlx_ptr, "sprites/floor.xpm", &x, &y);
	mlx_key_hook(ptr.win_ptr, key_input, &ptr);
	mlx_loop(ptr.mlx_ptr);
}
