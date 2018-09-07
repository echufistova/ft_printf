/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_params.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ychufist <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/07 16:00:45 by ychufist          #+#    #+#             */
/*   Updated: 2018/09/07 16:02:30 by ychufist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_printf.h"

int		ft_intlength(intmax_t n)
{
	int i;

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
	int i;

	i = 0;
	while (n != 0)
	{
		n /= 10;
		i++;
	}
	return (i);
}

