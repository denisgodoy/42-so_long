/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_args_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: degabrie <degabrie@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/14 00:43:21 by degabrie          #+#    #+#             */
/*   Updated: 2021/10/28 17:10:17 by degabrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"so_long_bonus.h"

static int	ft_check_ext(t_game *game, char *file);

void	ft_check_args(int argc, char **argv, t_game *game)
{
	if (argc == 2 && !ft_check_ext(game, argv[1]))
		game->filename = argv[1];
	else if (argc < 2)
		ft_error_handler(game, "Please provide a map", quit);
	else
	{
		if (ft_check_ext(game, argv[1]))
			ft_error_handler(game, "Invalid file extension", quit);
		else
			ft_error_handler(game, "Invalid number of arguments", quit);
	}
	return ;
}

static int	ft_check_ext(t_game *game, char *file)
{
	if (!ft_strchr(file, '.'))
		ft_error_handler(game, "Not a file", quit);
	else if (ft_strlen(ft_strchr(file, '.') + 1) != 3)
		return (1);
	return (ft_strncmp(ft_strchr(file, '.') + 1, "ber", 3));
}
