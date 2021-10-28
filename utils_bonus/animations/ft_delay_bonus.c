/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_delay_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: degabrie <degabrie@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/20 23:41:05 by degabrie          #+#    #+#             */
/*   Updated: 2021/10/28 17:07:33 by degabrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"so_long_bonus.h"

void	ft_delay(int ms)
{
	long	pause;
	clock_t	now;
	clock_t	then;

	pause = ms * (CLOCKS_PER_SEC / 1000);
	then = clock();
	now = then;
	while ((now - then) < pause)
		now = clock();
}
