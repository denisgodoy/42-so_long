/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: degabrie <degabrie@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/25 22:45:16 by degabrie          #+#    #+#             */
/*   Updated: 2021/10/11 19:08:37 by degabrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"so_long.h"

char	*ft_read_map(void)
{
	char	*map_read;
	char	*temp_read;
	int		fd;
	int 	i;

	temp_read =  ft_strdup("");
	i = 0;
	fd = open("./maps/map.ber", O_RDONLY);
	while(i < 4)
	{
		map_read = ft_strjoin(temp_read, get_next_line(fd));
		temp_read = map_read;
		i++;
	}
	close(fd);
	return (map_read);
}

void	ft_make_map(t_ptr *ptr)
{
	char	**map;
	int		i;
	int		j;

	i = 0;
	map = ft_split(ft_read_map(), '\n');
	while (map[i])
	{
		j = 0;
		while(map[i][j])
		{
			if (map[i][j] == '1')
	 			mlx_put_image_to_window(ptr->mlx, ptr->win, ptr->wall.ptr, (40 * j), (40 * i));
	 		else
	 			mlx_put_image_to_window(ptr->mlx, ptr->win, ptr->floor.ptr, (40 * j), (40 * i));
			j++;
		}
	 	i++;
	}
}

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
	ft_make_map(ptr);
	mlx_put_image_to_window(ptr->mlx, ptr->win, ptr->player.ptr,
		ptr->player.x, ptr->player.y);
	return (0);
}

int	main(void)
{
	t_ptr	ptr;
	int		y;
	int		x;

	ptr.player.x = 0;
	ptr.player.y = 0;
	ptr.floor.x = 0;
	ptr.floor.y = 0;
	ptr.wall.x = 0;
	ptr.wall.y = 0;
	ptr.mlx = mlx_init();
	ptr.win = mlx_new_window(ptr.mlx, 400, 160, "so_long");
	ptr.player.ptr = mlx_xpm_file_to_image(ptr.mlx, "sprites/right1.xpm", &x, &y);
	ptr.wall.ptr = mlx_xpm_file_to_image(ptr.mlx, "sprites/crate.xpm", &x, &y);
	ptr.floor.ptr = mlx_xpm_file_to_image(ptr.mlx, "sprites/water.xpm", &x, &y);
	mlx_hook(ptr.win, 2, (1L << 0), ft_key_input, &ptr);
	ft_make_map(&ptr);
	mlx_loop(ptr.mlx);
	return (0);
}
