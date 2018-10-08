/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_u.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ychufist <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/05 18:18:58 by ychufist          #+#    #+#             */
/*   Updated: 2018/10/05 18:21:24 by ychufist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "ft_printf.h"

char	*if1u(char *res, t_flagsntype flntp, uintmax_t n)
{
	int		i;
	char	*res1;
	char	*res2;

	i = 0;
	if (n == 0)
		flntp.number = (flntp.minus || flntp.noll) ?
			flntp.number - 1 : flntp.number;
	res1 = ft_itoa_unsigned(n);
	res2 = unsflag_space(res, flntp, n);
	res = ft_strjoin_free(&res2, &res1);
	if (flntp.minus == 1)
	{
		i = (ft_intlength_uns(n) > flntp.sizenoll) ? ft_intlength_uns(n) :
			flntp.sizenoll;
		while (i++ < flntp.number)
			res = ft_add_char(&res, ' ');
	}
	if (flntp.dot == 1 && n == 0)
		res[ft_strlen(res) - 1] = '\0';
	return (res);
}

char	*ft_print_u(va_list ap, t_flagsntype flntp, char *res)
{
	uintmax_t n;

	if (flntp.hljz.l == 1 || flntp.type == 'U')
		n = va_arg(ap, unsigned long);
	else if (flntp.hljz.ll == 1)
		n = va_arg(ap, unsigned long long);
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
	return (if1u(res, flntp, n));
}
