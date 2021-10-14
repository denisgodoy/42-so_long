/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_extension.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: degabrie <degabrie@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/14 00:43:21 by degabrie          #+#    #+#             */
/*   Updated: 2021/10/14 00:43:34 by degabrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"../../so_long.h"

int	ft_check_ext(char *file)
{
	char	*ext;

	ext = ft_strchr(file, '.') + 1;
	if (ft_strlen(ext) != 3)
		return (1);
	return (ft_strncmp(ext, "ber", 3));
}
