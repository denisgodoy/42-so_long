/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_args.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: degabrie <degabrie@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/14 00:43:21 by degabrie          #+#    #+#             */
/*   Updated: 2021/10/16 03:32:05 by degabrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"../../so_long.h"

static int	ft_check_ext(char *file);

void	ft_check_args(int argc, char **argv, t_game *game)
{
	if (argc == 2 && !ft_check_ext(argv[1]))
		game->filename = argv[1];
	else if (argc < 2)
		ft_error_handler("Please provide a map");
	else
	{
		if (ft_check_ext(argv[1]))
			ft_error_handler("Invalid file extension");
		else
			ft_error_handler("Invalid number of arguments");
	}
}

static int	ft_check_ext(char *file)
{
	if (!ft_strchr(file, '.'))
		ft_error_handler("Not a file");
	else if (ft_strlen(ft_strchr(file, '.') + 1) != 3)
		return (1);
	return (ft_strncmp(ft_strchr(file, '.') + 1, "ber", 3));
}
