/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_octflag.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ychufist <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/07 15:52:50 by ychufist          #+#    #+#             */
/*   Updated: 2018/09/07 15:59:58 by ychufist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*insertoct(char *res, t_flagsntype flntp, intmax_t n)
{
	if (n != 0 && (flntp.type == 'x' || flntp.type == 'p'))
	{
		res = ft_add_char(res, '0');
		res = ft_add_char(res, 'x');
	}
	else if (flntp.type == 'X' && n != 0)
	{
		res = ft_add_char(res, '0');
		res = ft_add_char(res, 'X');
	}
	else if ((flntp.type == 'o' || flntp.type == 'O') && n != 0)
		res = ft_add_char(res, '0');
	return (res);
}

char	*ft_octflag(char *res, t_flagsntype flntp, intmax_t n)
{
	uintmax_t nb;
	int i;
	intmax_t j;

	i = 0;
	nb = (uintmax_t )(n < 0 ? (-(n)) : n);
	j = ((flntp.type == 'x' || flntp.type == 'X' || flntp.type == 'o' ||
				flntp.type == 'O') ? n : ft_intlength(nb));
	if (flntp.oct == 1 && n != 0)
	{
		if ((flntp.noll == 1 || flntp.sizenoll > flntp.number) &&
				flntp.minus == 0)
		{
			if (n < 0 && (flntp.type == 'i' || flntp.type == 'd' ||
						flntp.type == 'D'))
				res = ft_add_char(res, '-');
			else if (flntp.plus == 1 && (flntp.type == 'i' ||
						flntp.type == 'd' || flntp.type == 'D'))
				res = ft_add_char(res, '+');
			res = insertoct(res, flntp, n);
			while (i++ < (flntp.sizenoll > flntp.number ? flntp.sizenoll
						: flntp.number) - j)
				res = ft_add_char(res, '0');
		}
		else if (flntp.noll == 0 && flntp.sizenoll == 0 && flntp.minus == 0)
		{
			while (i++ < flntp.number - j)
				res = ft_add_char(res, ' ');
			if (n < 0 && (flntp.type == 'i' || flntp.type == 'd' ||
						flntp.type == 'D'))
				res = ft_add_char(res, '-');
			else if (flntp.plus == 1 && (flntp.type == 'i' ||
						flntp.type == 'd' || flntp.type == 'D'))
				res = ft_add_char(res, '+');
			res = insertoct(res, flntp, n);
		}
		else if (flntp.sizenoll  < flntp.number && flntp.minus == 0)
		{
			if (is_type(flntp.type)) {
				while (i++ < flntp.number - (flntp.sizenoll > j ?
							flntp.sizenoll : j) + ((flntp.type == 'x'
									|| flntp.type == 'X') ? 1 : 0))
					res = ft_add_char(res, ' ');
			}
			if (n < 0 && (flntp.type == 'i' || flntp.type == 'd' ||
						flntp.type == 'D'))
				res = ft_add_char(res, '-');
			else if (flntp.plus == 1 && (flntp.type == 'i' ||
						flntp.type == 'd' || flntp.type == 'D'))
				res = ft_add_char(res, '+');
			res = insertoct(res, flntp, n);
			while (i++ < flntp.number -  j + ((flntp.type == 'x' ||
							flntp.type == 'X') ? 1 : 0))
				res = ft_add_char(res, '0');
		}
		else
			res = insertoct(res, flntp, n);
	}
	else
	{
		if (flntp.plus == 1 && n >= 0 && (flntp.type == 'i' ||
					flntp.type == 'd' || flntp.type == 'D'))
			res = ft_add_char(res, '+');
		if (flntp.sizenoll > flntp.number)
		{
			while (i++ < (flntp.sizenoll > flntp.number ?
						flntp.sizenoll : flntp.number) - j)
				res = ft_add_char(res, '0');
		}
		return (res);
	}
	return (res);
}
