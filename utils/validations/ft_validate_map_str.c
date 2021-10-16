/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_validate_map_str.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: degabrie <degabrie@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/15 22:04:07 by degabrie          #+#    #+#             */
/*   Updated: 2021/10/15 22:30:16 by degabrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"../../so_long.h"

void	ft_validate_map_str(char *map)
{
	int	i;

	i = 0;
	if (map[i] == '\0')
	{
		printf("Error\nInvalid map\n");
		exit(1);
	}
	while (map[i])
	{
		if (map[i] == '\n' && map[i + 1] != '1')
		{
			printf("Error\nInvalid map\n");
			exit(1);
		}
		i++;
	}
}
