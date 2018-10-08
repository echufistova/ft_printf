/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_unsigned.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ychufist <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/24 20:10:18 by ychufist          #+#    #+#             */
/*   Updated: 2018/09/27 17:07:33 by ychufist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "ft_printf.h"

static char		*print_positive_numbers(char *res, intmax_t n, int i)
{
	n = (n > 0 ? n : -n);
	if (!(res = (char*)ft_memalloc(sizeof(char) * (i + 1))))
		return (NULL);
	while (i > 0)
	{
		res[i - 1] = (uintmax_t)n % 10 + 48;
		n = (uintmax_t)n / 10;
		i--;
	}
	return (res);
}

static char		*print_positive_numbers_uns(char *res, uintmax_t n, int i)
{
	if (!(res = (char*)ft_memalloc(sizeof(char) * (i + 1))))
		return (NULL);
	while (i > 0)
	{
		res[i - 1] = n % 10 + 48;
		n = n / 10;
		i--;
	}
	return (res);
}

char			*ft_itoa_signed(intmax_t n)
{
	char				*res;
	int					i;

	res = NULL;
	i = ft_intlength((uintmax_t)n);
	if (n != 0)
		return (print_positive_numbers(res, n, i));
	res = ft_memalloc(2);
	res[0] = '0';
	return (res);
}

char			*ft_itoa_unsigned(uintmax_t n)
{
	char				*res;
	int					i;

	res = NULL;
	i = ft_intlength_uns(n);
	if (n != 0)
		return (print_positive_numbers_uns(res, n, i));
	res = ft_memalloc(2);
	res[0] = '0';
	return (res);
}
