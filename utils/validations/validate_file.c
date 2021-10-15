/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_file.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: degabrie <degabrie@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/14 00:43:21 by degabrie          #+#    #+#             */
/*   Updated: 2021/10/14 23:11:48 by degabrie         ###   ########.fr       */
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
			printf("Error\nInvalid map extension\n");
		else
			printf("Error\nInvalid number of arguments\n");
		exit(1);
	}
}

static int	ft_check_ext(char *file)
{
	char	*ext;

	ext = ft_strchr(file, '.') + 1;
	if (ft_strlen(ext) != 3)
		return (1);
	return (ft_strncmp(ext, "ber", 3));
}
