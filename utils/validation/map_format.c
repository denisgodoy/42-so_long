/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_format.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: degabrie <degabrie@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/14 15:43:39 by degabrie          #+#    #+#             */
/*   Updated: 2021/10/14 21:06:27 by degabrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"../../so_long.h"

void	ft_valid_map(t_ptr *ptr, char *map_read)
{
	ft_map_char(map_read);
	ft_map_format(ptr, map_read);
	if (ptr->map_utils.height == ptr->map_utils.width)
	{
		printf("Error\nMap is not rectangular\n");
		exit(1);
	}
}

void	ft_map_char(char *map_read)
{
	int	i;
	int	p;
	int	c;
	int	e;

	i = 0;
	p = 0;
	c = 0;
	e = 0;
	while (map_read[i])
	{
		if (map_read[i] == 'C')
			c++;
		else if (map_read[i] == 'P')
			p++;
		else if (map_read[i] == 'E')
			e++;
	 	else if (!ft_strchr("10CPE\n", map_read[i]))
		{
			printf("Error\nInvalid map\n");
			exit(1);
		}
	 	i++;
	}
	if (!(c > 0 && p == 1 && e == 1))
	{
		printf("Error\nInvalid map\n");
		exit(1);
	}
}

void	ft_map_format(t_ptr *ptr, char *map)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (map[i])
	{
		if (map[i] == '\n')
			j++;
		i++;
	}
	ptr->map_utils.width = (i / (j + 1) - 1);
	ptr->map_utils.height = j;
}
