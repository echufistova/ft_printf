/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ychufist <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/03 19:44:22 by ychufist          #+#    #+#             */
/*   Updated: 2018/09/24 21:01:11 by ychufist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	int			i;
	int			len;
	char		*res;

	i = 0;
	if (s1 && s2)
	{
		len = ft_strlen(s1) + ft_strlen(s2) + 1;
		res = (char*)malloc(sizeof(char) * len);
		if (res == NULL)
			return (NULL);
		while (s1[i] != '\0')
		{
			res[i] = s1[i];
			i++;
		}
		while (s2[i - ft_strlen(s1)] != '\0')
		{
			res[i] = s2[i - ft_strlen(s1)];
			i++;
		}
		res[i] = '\0';
		//ft_bzero(s1, ft_strlen(s1));
		//ft_bzero(s2, ft_strlen(s2));
		return (res);
	}
	//ft_bzero(s1, ft_strlen(s1));
	//ft_bzero(s2, ft_strlen(s2));
	return (NULL);
}
