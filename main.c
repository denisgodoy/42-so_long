/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: degabrie <degabrie@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/25 22:45:16 by degabrie          #+#    #+#             */
/*   Updated: 2021/10/13 23:56:49 by degabrie         ###   ########.fr       */
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

char	**ft_read_map(t_ptr *ptr)
{
	char	*map_read;
	char	*temp_read;
	int		fd;

	temp_read = ft_strdup("");
	fd = open(ptr->map, O_RDONLY);
	while(1)
	{
		map_read = ft_strjoin(temp_read, get_next_line(fd));
		temp_read = map_read;
		if (map_read[ft_strlen(map_read) - 1] != '\n')
			break ;
	}
	close(fd);
	return (ft_split(map_read, '\n'));
}

void	ft_check_walls(t_ptr *ptr, int h, int w)
{
	if (h == 0 && w == 0)
		mlx_put_image_to_window(ptr->mlx, ptr->win, ptr->wall_ur.ptr, (40 * w), (40 * h));
	else if (h == 4 && w == 0)
		mlx_put_image_to_window(ptr->mlx, ptr->win, ptr->wall_bl.ptr, (40 * w), (40 * h));				
	else if (h == 0 && w == 12)
		mlx_put_image_to_window(ptr->mlx, ptr->win, ptr->wall_ul.ptr, (40 * w), (40 * h));
	else if (h == 4 && w == 12)
		mlx_put_image_to_window(ptr->mlx, ptr->win, ptr->wall_br.ptr, (40 * w), (40 * h));
	else if (h == 0 && w > 0 && w < 12)
		mlx_put_image_to_window(ptr->mlx, ptr->win, ptr->wall_u.ptr, (40 * w), (40 * h));
	else if (h > 0 && h < 4 && w == 0)
		mlx_put_image_to_window(ptr->mlx, ptr->win, ptr->wall_r.ptr, (40 * w), (40 * h));
	else if (h > 0 && h < 4 && w == 12)
		mlx_put_image_to_window(ptr->mlx, ptr->win, ptr->wall_l.ptr, (40 * w), (40 * h));
	else if (h == 4 && w > 0 && w < 12)
		mlx_put_image_to_window(ptr->mlx, ptr->win, ptr->wall_b.ptr, (40 * w), (40 * h));
	else
		mlx_put_image_to_window(ptr->mlx, ptr->win, ptr->wall_m.ptr, (40 * w), (40 * h));
}

void	ft_make_map(t_ptr *ptr)
{
	char	**map;
	int		h;
	int		w;
	int		collects;

	collects = 0;
	h = 0;
	map = ft_read_map(ptr);
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
			{
				collects++;
				mlx_put_image_to_window(ptr->mlx, ptr->win, ptr->collect.ptr, (40 * w), (40 * h));
			}
			else if (map[h][w] == 'E')
			{
				if (!collects)
	 				mlx_put_image_to_window(ptr->mlx, ptr->win, ptr->exit_o.ptr, (40 * w), (40 * h));
				else
					mlx_put_image_to_window(ptr->mlx, ptr->win, ptr->exit_c.ptr, (40 * w), (40 * h));
			}
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

void	ft_player_img(t_ptr *ptr)
{
	int		y;
	int		x;

	ptr->player.x = 0;
	ptr->player.y = 0;
	ptr->player.ptr = mlx_xpm_file_to_image(ptr->mlx, "img/right1.xpm", &x, &y);
}

void	ft_map_img(t_ptr *ptr)
{
	int		y;
	int		x;

	ptr->wall_l.ptr = mlx_xpm_file_to_image(ptr->mlx, "img/wl.xpm", &x, &y);
	ptr->wall_r.ptr = mlx_xpm_file_to_image(ptr->mlx, "img/wr.xpm", &x, &y);
	ptr->wall_bl.ptr = mlx_xpm_file_to_image(ptr->mlx, "img/wbl.xpm", &x, &y);
	ptr->wall_ul.ptr = mlx_xpm_file_to_image(ptr->mlx, "img/wtl.xpm", &x, &y);
	ptr->wall_br.ptr = mlx_xpm_file_to_image(ptr->mlx, "img/wbr.xpm", &x, &y);
	ptr->wall_ur.ptr = mlx_xpm_file_to_image(ptr->mlx, "img/wtr.xpm", &x, &y);
	ptr->wall_u.ptr = mlx_xpm_file_to_image(ptr->mlx, "img/wb.xpm", &x, &y);
	ptr->wall_b.ptr = mlx_xpm_file_to_image(ptr->mlx, "img/wu.xpm", &x, &y);
	ptr->wall_m.ptr = mlx_xpm_file_to_image(ptr->mlx, "img/wm.xpm", &x, &y);
	ptr->floor.ptr = mlx_xpm_file_to_image(ptr->mlx, "img/water.xpm", &x, &y);
	ptr->exit_c.ptr = mlx_xpm_file_to_image(ptr->mlx, "img/exit1.xpm", &x, &y);
	ptr->exit_o.ptr = mlx_xpm_file_to_image(ptr->mlx, "img/exit2.xpm", &x, &y);
	ptr->collect.ptr = mlx_xpm_file_to_image(ptr->mlx, "img/key.xpm", &x, &y);
}

void	ft_img_init(t_ptr *ptr)
{
	ft_player_img(ptr);
	ft_map_img(ptr);
}

int	ft_check_ext(char *file)
{
	char	*ext;

	ext = ft_strchr(file, '.') + 1;
	if (ft_strlen(ext) != 3)
		return (1);
	return (ft_strncmp(ext, "ber", 3));
}
