/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_add_char.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ychufist <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/24 19:56:42 by ychufist          #+#    #+#             */
/*   Updated: 2018/09/24 19:56:54 by ychufist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"

char	*ft_add_char(char *str, char c)
{
	int i;
	char *res;

	i = 0;
	res = (char *) ft_memalloc(sizeof(char) * (ft_strlen(str) + 2));
	if (str != NULL)
	{
		while (str[i] != '\0')
		{
			res[i] = str[i];
			i++;
		}
	}
	res[i] = c;
	if (str)
		ft_bzero(str, ft_strlen(res));
    return (res);
}
