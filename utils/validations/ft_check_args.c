/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_args.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: degabrie <degabrie@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/14 00:43:21 by degabrie          #+#    #+#             */
/*   Updated: 2021/10/21 22:12:13 by degabrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"../../so_long.h"

static int	ft_check_ext(t_game *game, char *file);

void	ft_check_args(int argc, char **argv, t_game *game)
{
	if (argc == 2 && !ft_check_ext(game, argv[1]))
		game->filename = argv[1];
	else if (argc < 2)
		ft_error_handler(game, "Error\nPlease provide a map", quit);
	else
	{
		if (ft_check_ext(game, argv[1]))
			ft_error_handler(game, "Error\nInvalid file extension", quit);
		else
			ft_error_handler(game, "Error\nInvalid number of arguments", quit);
	}
}

static int	ft_check_ext(t_game *game, char *file)
{
	if (!ft_strchr(file, '.'))
		ft_error_handler(game, "Error\nNot a file", quit);
	else if (ft_strlen(ft_strchr(file, '.') + 1) != 3)
		return (1);
	return (ft_strncmp(ft_strchr(file, '.') + 1, "ber", 3));
}
