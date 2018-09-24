/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_presflags.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ychufist <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/24 20:33:22 by ychufist          #+#    #+#             */
/*   Updated: 2018/09/24 20:37:35 by ychufist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_printf.h"

char	*plminsp(char *res, t_flagsntype flntp, intmax_t n)
{
	if (n < 0 && (flntp.type == 'i' || flntp.type == 'd' || flntp.type == 'D'))
		res = ft_add_char(res, '-');
	else if (flntp.plus == 1 && n >= 0 && (flntp.type == 'i' || flntp.type == 'd' || flntp.type == 'D'))
		res = ft_add_char(res, '+');
	else if (flntp.space == 1 && (flntp.type == 'i' || flntp.type == 'd' || flntp.type == 'D'))
		res = ft_add_char(res, ' ');
	return (res);
}

char	*ft_presflags(char *res, t_flagsntype flntp, intmax_t n)
{
	int			i;
	intmax_t	j;

	i = 0;
	
	j = (flntp.type == 'x' || flntp.type == 'X' || flntp.type == 'o' ||
		flntp.type == 'O' || flntp.type == 'p') ? n : ft_intlength(n);
	if (flntp.sizenoll > flntp.number)
	{
		res = ft_strdup(plminsp(res, flntp, n));
		while (i++ < flntp.sizenoll - j)
			res = ft_add_char(res, '0');
	}
	else if (flntp.minus == 0 && n != 0 && is_type(flntp.type))
	{
		if (flntp.space == 1 && (flntp.type == 'i' || flntp.type == 'd' || flntp.type == 'D'))
		{
			res = ft_add_char(res, ' ');
			flntp.number--;
		}
		while (i++ < flntp.number - (flntp.sizenoll > j ? flntp.sizenoll : j))
			res = ft_add_char(res, ' ');
		if (n < 0 && (flntp.type == 'i' || flntp.type == 'd' || flntp.type == 'D'))
			res = ft_add_char(res, '-');
		else if (flntp.plus == 1 && n >= 0 && (flntp.type == 'i' || flntp.type == 'd' || flntp.type == 'D'))
			res = ft_add_char(res, '+');
		while (i++ <= flntp.number - j)
			res = ft_add_char(res, '0');
	}
	else
	{
		if (flntp.number > 0 && flntp.sizenoll == 0 && flntp.minus == 0
				&& flntp.oct == 0 && flntp.noll2 == 0)
		{
			if ((flntp.plus || flntp.space || n < 0 ) && (flntp.type == 'i'
						|| flntp.type == 'd' || flntp.type == 'D'))
				flntp.number--;
			while (i++ < flntp.number - ft_intlength(n))
				res = ft_add_char(res, ' ');
			res = ft_strdup(plminsp(res, flntp, n));
			return (res);
		}
		res = ft_strdup(plminsp(res, flntp, n));
		if (!is_type(flntp.type))
        {
			if (flntp.noll2 == 3 && flntp.number > flntp.sizenoll)
			{
				while (i++ < flntp.number - 1)
					res = ft_add_char(res, '0');
			}
			else
			{
				while (i++ < flntp.number - 1)
					res = ft_add_char(res, ' ');
			}
		}
		while (i++ < (flntp.sizenoll > j ? flntp.sizenoll : j) - j)
			res = ft_add_char(res, '0');
	}
	return (res);
}
