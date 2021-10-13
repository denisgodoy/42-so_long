/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: degabrie <degabrie@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/25 22:45:16 by degabrie          #+#    #+#             */
/*   Updated: 2021/10/13 17:19:44 by degabrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"so_long.h"

char	*ft_read_map(void)
{
	char	*map_read;
	char	*temp_read;
	int		fd;

	temp_read = ft_strdup("");
	fd = open("./maps/map2.ber", O_RDONLY);
	//fd = open("./maps/map.ber", O_RDONLY);
	while(1)
	{
		map_read = ft_strjoin(temp_read, get_next_line(fd));
		temp_read = map_read;
		if (map_read[ft_strlen(map_read) - 1] != '\n')
			break ;
	}
	close(fd);
	return (map_read);
}

void ft_check_walls(t_ptr *ptr, int h, int w)
{
	if (h == 0 && w == 0)
		mlx_put_image_to_window(ptr->mlx, ptr->win, ptr->wall_corner_up_r.ptr, (40 * w), (40 * h));
	else if (h == 4 && w == 0)
		mlx_put_image_to_window(ptr->mlx, ptr->win, ptr->wall_corner_btm_l.ptr, (40 * w), (40 * h));				
	else if (h == 0 && w == 12)
		mlx_put_image_to_window(ptr->mlx, ptr->win, ptr->wall_corner_up_l.ptr, (40 * w), (40 * h));
	else if (h == 4 && w == 12)
		mlx_put_image_to_window(ptr->mlx, ptr->win, ptr->wall_corner_btm_r.ptr, (40 * w), (40 * h));
	else if (h == 0 && w > 0 && w < 12)
		mlx_put_image_to_window(ptr->mlx, ptr->win, ptr->wall_up.ptr, (40 * w), (40 * h));
	else if (h > 0 && h < 4 && w == 0)
		mlx_put_image_to_window(ptr->mlx, ptr->win, ptr->wall_r.ptr, (40 * w), (40 * h));
	else if (h > 0 && h < 4 && w == 12)
		mlx_put_image_to_window(ptr->mlx, ptr->win, ptr->wall_l.ptr, (40 * w), (40 * h));
	else if (h == 4 && w > 0 && w < 12)
		mlx_put_image_to_window(ptr->mlx, ptr->win, ptr->wall_btm.ptr, (40 * w), (40 * h));
	else
		mlx_put_image_to_window(ptr->mlx, ptr->win, ptr->wall_middle.ptr, (40 * w), (40 * h));
}

void	ft_make_map(t_ptr *ptr)
{
	char	**map;
	int		h;
	int		w;

	h = 0;
	map = ft_split(ft_read_map(), '\n');
	while (map[h])
	{
		w = 0;
		while(map[h][w])
		{
			if (map[h][w] == '1')
				ft_check_walls(ptr, h, w);
	 		else if (map[h][w] == 'P')
				mlx_put_image_to_window(ptr->mlx, ptr->win, ptr->player.ptr, (40 * w), (40 * h));
			else if (map[h][w] == 'C')
	 			mlx_put_image_to_window(ptr->mlx, ptr->win, ptr->collect.ptr, (40 * w), (40 * h));
			else if (map[h][w] == 'E')
	 			mlx_put_image_to_window(ptr->mlx, ptr->win, ptr->exit.ptr, (40 * w), (40 * h));
			else
				mlx_put_image_to_window(ptr->mlx, ptr->win, ptr->floor.ptr, (40 * w), (40 * h));
			w++;
		}
	 	h++;
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
		ptr->player.x -= 40;
	else if (key == RIGHT)
		ptr->player.x += 40;
	else if (key == UP)
		ptr->player.y -= 40;
	else if (key == DOWN)
		ptr->player.y += 40;
	else if (key == ESC)
		exit(1);
	mlx_clear_window(ptr->mlx, ptr->win);
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
	ptr.mlx = mlx_init();
	ptr.win = mlx_new_window(ptr.mlx, 520, 200, "so_long");
	//ptr.win = mlx_new_window(ptr.mlx, 400, 280, "so_long");
	ptr.player.ptr = mlx_xpm_file_to_image(ptr.mlx, "sprites/right1.xpm", &x, &y);
	ptr.wall_l.ptr = mlx_xpm_file_to_image(ptr.mlx, "sprites/wall_left.xpm", &x, &y);
	ptr.wall_r.ptr = mlx_xpm_file_to_image(ptr.mlx, "sprites/wall_right.xpm", &x, &y);
	ptr.wall_corner_btm_l.ptr = mlx_xpm_file_to_image(ptr.mlx, "sprites/wall_bottom_left.xpm", &x, &y);
	ptr.wall_corner_up_l.ptr = mlx_xpm_file_to_image(ptr.mlx, "sprites/wall_top_left.xpm", &x, &y);
	ptr.wall_corner_btm_r.ptr = mlx_xpm_file_to_image(ptr.mlx, "sprites/wbr.xpm", &x, &y);
	ptr.wall_corner_up_r.ptr = mlx_xpm_file_to_image(ptr.mlx, "sprites/wall_top_right.xpm", &x, &y);
	ptr.wall_up.ptr = mlx_xpm_file_to_image(ptr.mlx, "sprites/wall_down.xpm", &x, &y);
	ptr.wall_btm.ptr = mlx_xpm_file_to_image(ptr.mlx, "sprites/wall_up.xpm", &x, &y);
	ptr.wall_middle.ptr = mlx_xpm_file_to_image(ptr.mlx, "sprites/wall_middle.xpm", &x, &y);
	ptr.floor.ptr = mlx_xpm_file_to_image(ptr.mlx, "sprites/water.xpm", &x, &y);
	ptr.exit.ptr = mlx_xpm_file_to_image(ptr.mlx, "sprites/exit1.xpm", &x, &y);
	ptr.collect.ptr = mlx_xpm_file_to_image(ptr.mlx, "sprites/key.xpm", &x, &y);
	mlx_key_hook(ptr.win, ft_key_input, &ptr);
	//mlx_hook(ptr.win, 2, (1L << 0), ft_key_input, &ptr);
	ft_make_map(&ptr);
	mlx_loop(ptr.mlx);
	return (0);
}
