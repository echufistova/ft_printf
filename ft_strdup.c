/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ychufist <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/24 17:25:16 by ychufist          #+#    #+#             */
/*   Updated: 2018/09/03 14:47:51 by ychufist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *src)
{
	int		i;
	char	*str;

	i = 0;

	if (src != NULL) {
		if (!(str = (char*)malloc(sizeof(char) * (ft_strlen(src) + 1))))
			return (0);
		while (src[i] != '\0') {
			str[i] = src[i];
			i++;
		}
		str[i] = '\0';
		return (str);
	}
	ft_bzero((char *)src, ft_strlen(src));
	return ("(null)");
}

