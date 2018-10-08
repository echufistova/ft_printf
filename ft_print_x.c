/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_x.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ychufist <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/05 18:23:17 by ychufist          #+#    #+#             */
/*   Updated: 2018/10/05 18:27:35 by ychufist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "ft_printf.h"

char	*ifx1(char *res, t_flagsntype flntp, unsigned long int n)
{
	int		j;
	char	*res1;

	j = 0;
	if (flntp.dot == 1)
		return (flag_space(res, flntp, n));
	else
	{
		flntp.number = (flntp.noll == 1 || flntp.minus) ? flntp.number - 1 :
			flntp.number;
		if (flntp.minus == 1)
		{
			res = ft_add_char(&res, '0');
			while (j++ < flntp.number)
				res = ft_add_char(&res, ' ');
			return (res);
		}
		res1 = flag_space(res, flntp, n);
		return (ft_add_char(&res1, '0'));
	}
}

char	*ifx2(char *res, t_flagsntype flntp, unsigned long int n)
{
	int		j;
	int		s;
	char	*res1;

	res1 = ft_itoa_base_uns((intmax_t)n, 16, flntp);
	s = ft_strlen(res1);
	if (flntp.oct == 1 && flntp.sizenoll < flntp.number)
		flntp.number = flntp.number - 2;
	res = (flntp.oct == 1) ? ft_octflag(res, flntp, s) :
		flag_space(res, flntp, s);
	j = (int)ft_strlen(res1);
	j = (j > flntp.sizenoll) ? j : flntp.sizenoll;
	res = ft_strjoin_free(&res, &res1);
	if (flntp.minus == 1)
	{
		while (j++ < flntp.number)
			res = ft_add_char(&res, ' ');
	}
	return (res);
}

char	*ft_print_x(va_list ap, t_flagsntype flntp, char *res)
{
	unsigned long int	n;
	int					j;

	j = 0;
	if (flntp.hljz.ll != 0 || flntp.hljz.l != 0)
		n = (flntp.hljz.ll == 1 ? va_arg(ap, unsigned long long int) :
				va_arg(ap, unsigned long int));
	else if (flntp.hljz.h == 1)
		n = (unsigned short)va_arg(ap, int);
	else if (flntp.hljz.hh == 1)
		n = (unsigned char)va_arg(ap, int);
	else if (flntp.hljz.j == 1)
		n = va_arg(ap, uintmax_t);
	else if (flntp.hljz.z == 1)
		n = va_arg(ap, size_t);
	else
		n = va_arg(ap, unsigned int);
	if (n == 0)
		return (ifx1(res, flntp, n));
	return (ifx2(res, flntp, n));
}
