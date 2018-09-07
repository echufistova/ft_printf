/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flags.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ychufist <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/07 15:28:17 by ychufist          #+#    #+#             */
/*   Updated: 2018/09/07 15:33:56 by ychufist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_printf.h"

char	*flag_space(char *res, t_flagsntype flntp, intmax_t n)
{
	int			i;
	int			j;
	uintmax_t	nb;

	i = 0;
	nb = (uintmax_t )(n < 0 ? (-n) : n);
	j = ((flntp.type == 'x' || flntp.type == 'X' || flntp.type == 'o' ||
				flntp.type == 'O') ? n : ft_intlength(nb));
	if (n < 0 || (flntp.plus == 1 && (flntp.type == 'i' || 
					flntp.type == 'd' ||flntp.type == 'D')))
		flntp.number--;
	if (flntp.oct == 1)
		return (ft_octflag(res, flntp, n));
	if (flntp.dot == 1)
		return(ft_presflags(res, flntp, n));
	if (flntp.plus == 1 && n >= 0 && (flntp.type == 'd' ||
				flntp.type == 'D' || flntp.type == 'i') )
		res = ft_add_char(res, '+');
    else if (flntp.space == 1 && flntp.plus == 0 && n > 0 && (flntp.type == 'd' ||
            flntp.type == 'D' || flntp.type == 'i'))
		res = ft_add_char(res, ' ');
	if (flntp.noll == 1 && flntp.minus == 0)
	{
		if (n < 0)
			res = ft_add_char(res, '-');
		while (i++ < flntp.number - j)
			res = ft_add_char(res, '0');
		i = 0;
	}
	if (flntp.noll == 0 && flntp.number != 0 && flntp.minus == 0)
	{
		while (i++ < flntp.number - j)
			res = ft_add_char(res, ' ');
		if (n < 0 && (flntp.type == 'i' || flntp.type == 'd' || flntp.type == 'D'))
			res = ft_add_char(res, '-');
		i = 0;
	}
    return (res);
}

char	*unsflag_space(char *res, t_flagsntype flntp, uintmax_t n)
{
	int		i;
	int		j;

	i = 0;
	j = ((flntp.type == 'x' || flntp.type == 'X' || flntp.type == 'o' ||
				flntp.type == 'O') ? n : ft_intlength(n));
	if (flntp.plus == 1 && (flntp.type == 'i' ||
				flntp.type == 'd' ||flntp.type == 'D'))
		flntp.number--;
	if (flntp.oct == 1)
		return (ft_octflag(res, flntp, n));
	if (flntp.dot == 1)
		return(ft_presflags(res, flntp, n));
	if (flntp.noll == 1 && flntp.minus == 0)
	{
		while (i++ < flntp.number - j)
			res = ft_add_char(res, '0');
		i = 0;
	}
	if (flntp.noll == 0 && flntp.number != 0 && flntp.minus == 0)
	{
		while (i++ < flntp.number - j)
			res = ft_add_char(res, ' ');
		i = 0;
	}
	return (res);
}

