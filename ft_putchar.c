/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ychufist <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/01 14:39:58 by ychufist          #+#    #+#             */
/*   Updated: 2018/09/07 18:24:24 by ychufist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putchar(int c)
{
	unsigned char uni[4];
	unsigned int i;

	i = (unsigned int)c;
	if (i  < 128)
	{
		uni[3] = c;
		write(1, &uni[3], 1);
	}
	else if (i < 2048)
	{
		uni[3] = 128 | (i & 63);
		uni[2] = 192 | (i >> 6);
		write(1, &uni[2], 1);
		write(1, &uni[3], 1);
	}
	else if (i < 65536)
	{
		uni[3] = 128 | (i & 63);
		uni[2] = 128 | ((i >> 6) & 63);
		uni[1] = 224 | (i >> 12);
		write(1, &uni[1], 1);
	write(1, &uni[2], 1);
		write(1, &uni[3], 1);
	}
	else if (c < 1114112) {
		uni[3] = 128 | (i & 63);
		uni[2] = 128 | ((i >> 6) & 63);
		uni[1] = 128 | ((i >> 12) & 63);
		uni[0] = 240 | (i >> 21);
	write(1, &uni[0], 1);
	write(1, &uni[1], 1);
	write(1, &uni[2], 1);
		write(1, &uni[3], 1);
	}
}
