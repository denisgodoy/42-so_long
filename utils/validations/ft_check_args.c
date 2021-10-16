/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_file.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: degabrie <degabrie@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/14 00:43:21 by degabrie          #+#    #+#             */
/*   Updated: 2021/10/15 10:30:11 by degabrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"../../so_long.h"

static int	ft_check_ext(char *file);

void	ft_check_args(int argc, char **argv, t_game *game)
{
	if (argc == 2 && !ft_check_ext(argv[1]))
		game->filename = argv[1];
	else if (argc < 2)
	{
		printf("Error\nPlease provide a map\n");
		exit(1);
	}
	else
	{
		if (ft_check_ext(argv[1]))
			printf("Error\nInvalid file extension\n");
		else
			printf("Error\nInvalid number of arguments\n");
		exit(1);
	}
}

static int	ft_check_ext(char *file)
{
	if (!ft_strchr(file, '.'))
	{
		printf("Error\nNot a file\n");
		exit(1);
	}
	else if (ft_strlen(ft_strchr(file, '.') + 1) != 3)
		return (1);
	return (ft_strncmp(ft_strchr(file, '.') + 1, "ber", 3));
}
