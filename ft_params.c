/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_params.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ychufist <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/24 20:30:38 by ychufist          #+#    #+#             */
/*   Updated: 2018/09/25 19:34:12 by ychufist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_printf.h"

int		is_type(char c)
{
	if (c == 's' || c == 'S' || c == 'p' || c == 'd' || c == 'D' || c == 'i' ||
		c == 'o' || c == 'O' || c == 'u' || c == 'U' || c == 'x' || c == 'X' ||
		c == 'c' || c == 'C')
		return (1);
	return (0);
}

char	*no_params(char *res, t_flagsntype flntp, unsigned int *i)
{
	int		j;

	j = 0;
	(*i)--;
	flntp.dot = (flntp.noll2 == 3) ? 1 : 0;
	flntp.oct = 0;
	if (flntp.minus == 0)
		res = flag_space(res, flntp, 1);
	res = ft_add_char(&res, flntp.type);
	if (flntp.minus == 1)
	{
		while (j++ < flntp.number - 1)
			res = ft_add_char(&res, ' ');
	}
	(*i)++;
	return (res);
}

int		ft_intlength(intmax_t n)
{
	int		i;

	i = 0;
	while (n != 0)
	{
		n /= 10;
		i++;
	}
	return (i);
}

int		ft_intlength_uns(uintmax_t n)
{
	int		i;

	i = 0;
	while (n != 0)
	{
		n /= 10;
		i++;
	}
	return (i);
}
