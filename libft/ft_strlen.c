/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ychufist <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/24 17:24:21 by ychufist          #+#    #+#             */
/*   Updated: 2018/10/09 17:37:27 by ychufist         ###   ########.fr       */
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

size_t	ft_strlen_w(wchar_t *w_str)
{
	size_t i;

	i = 0;
	if (w_str != NULL)
	{
		while (w_str[i])
			i++;
	}
	return (i);
}