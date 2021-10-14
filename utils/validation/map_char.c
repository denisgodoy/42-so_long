/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_char.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: degabrie <degabrie@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/14 02:11:40 by degabrie          #+#    #+#             */
/*   Updated: 2021/10/14 02:40:40 by degabrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"../../so_long.h"

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
			printf("Error\nInvalid map!\n");
			exit(1);
		}
	 	i++;
	}
	if (!(c > 0 && p == 1 && e == 1))
	{
		printf("Error\nInvalid map!\n");
		exit(1);
	}
}
