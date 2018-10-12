/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ychufist <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/24 17:24:21 by ychufist          #+#    #+#             */
/*   Updated: 2018/10/10 19:10:37 by ychufist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t		ft_strlen(const char *str)
{
	size_t i;

	i = 0;
	if (str)
	{
		while (str[i] != '\0')
			i++;
	}
	return (i);
}

size_t		ft_strlen_w(wchar_t *w_str)
{
	int i;
	size_t len;

	i = 0;
	len = 0;
	if (w_str)
	{
		while (w_str[i] != '\0')
		{	
			if (w_str[i] <= 127)
  				len += 1;
 			else if (w_str[i] <= 2047)
  				len += 2;
 			else if (w_str[i] <= 65535)
  				len += 3;
 			else
  				len += 4;
			i++;
		}
	}
	return (len);
}
