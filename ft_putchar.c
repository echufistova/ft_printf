/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ychufist <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/01 14:39:58 by ychufist          #+#    #+#             */
/*   Updated: 2018/10/05 18:57:02 by ychufist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putchar(unsigned int c)
{
	write(1, &c, 1);
}

void	ft_putchar_w(wchar_t c)
{
	unsigned char	uni[4];
	unsigned int	i;

	i = (unsigned int)c;
	if (i < 128)
		write(1, &c, 1);
	else if (i < 2048)
	{
		uni[1] = 128 | (i & 63);
		uni[0] = 192 | (i >> 6);
		write(1, &uni, 2);
	}
	else if (i < 65536)
	{
		uni[2] = 128 | (i & 63);
		uni[1] = 128 | ((i >> 6) & 63);
		uni[0] = 224 | (i >> 12);
		write(1, &uni, 3);
	}
	else if (i < 1114112)
	{
		uni[3] = 128 | (i & 63);
		uni[2] = 128 | ((i >> 6) & 63);
		uni[1] = 128 | ((i >> 12) & 63);
		uni[0] = 240 | (i >> 18);
		write(1, &uni, 4);
	}
}
