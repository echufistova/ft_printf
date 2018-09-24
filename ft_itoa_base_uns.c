/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base_uns.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ychufist <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/24 20:08:21 by ychufist          #+#    #+#             */
/*   Updated: 2018/09/24 20:09:33 by ychufist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_itoa_base_uns(uintmax_t value, int base, t_flagsntype flntp)
{
	char		*s;
	char		c;
	uintmax_t	i;
	uintmax_t	n;
	int			sign;

	c = (char)((flntp.type == 'X') ? 'A' : 'a');
	n = value;
	sign = (value > 0 && base == 10) ? -1 : 0;
	i = (sign == -1) ? 2 : 1;
	while ((n /= base) >= 1)
		i++;
	s = (char*)malloc(sizeof(char) * (i + 1));
	s[i] = '\0';
	n = value;
	while (i-- + sign)
	{
		s[i] = (n % base < 10) ? n % base + '0' : n % base - 10 + c;
		n /= base;
	}
	(i == 0) ? s[i] = '-' : 0;
	return (s);
}
