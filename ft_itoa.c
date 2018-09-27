/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ychufist <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/07 16:58:02 by ychufist          #+#    #+#             */
/*   Updated: 2018/04/17 15:08:52 by ychufist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

static char		*print_positive_numbers(char *res, long long int n, int i)
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

char			*ft_itoa(long long int n)
{
	char				*res;
	long long int		np;
	int					i;

	np = n;
	i = 0;
	res = NULL;
	while (np != 0)
	{
		np = np / 10;
		i++;
	}
	//if (n < 0)
	//	return (print_negative_numbers(res, n, i));
	if (n > 0)
		return (print_positive_numbers(res, n, i));
	res = ft_memalloc(2);
	res[0] = '0';
	return (res);
}
