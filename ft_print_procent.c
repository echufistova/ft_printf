/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_procent.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ychufist <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/05 18:06:30 by ychufist          #+#    #+#             */
/*   Updated: 2018/10/05 18:07:19 by ychufist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "ft_printf.h"

char	*procent(va_list ap, const char *format, unsigned int *i, char *res)
{
	char *res1;

	while (format[*i] != '%' && format[*i] != '\0')
	{
		ft_putchar(format[*i]);
		(*i)++;
	}
	(*i)++;
	if (format[*i] == '%' && format[*i] != '%')
	{
		res1 = procent(ap, format, i, res);
		res = ft_strjoin_free(&res, &res1);
	}
	return (res);
}
