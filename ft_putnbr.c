/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ychufist <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/01 18:17:35 by ychufist          #+#    #+#             */
/*   Updated: 2018/04/03 19:59:49 by ychufist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr(int nbr)
{
    long long int nb;

    nb = nbr;
	if (nb < 0 && nb != -2147483648)
	{
		nb = -nb;
		ft_putchar('-');
	}
	if (nb == -2147483648)
	{
		nb = nb % 1000000000;
		nb = -nb;
		ft_putchar('-');
		ft_putchar('2');
	}
	if (nb < 10)
	{
		ft_putchar(nb + '0');
	}
	else
	{
		ft_putnbr(nb / 10);
		ft_putchar(nb % 10 + '0');
	}
}


void	ft_putnbr_ld(long int nbr)
{
    long int nb;

    nb = nbr;
    if (nb < 0 && nb != -2147483648)
    {
        nb = -nb;
        ft_putchar('-');
    }
    if (nb == -2147483648)
    {
        nb = nb % 1000000000;
        nb = -nb;
        ft_putchar('-');
        ft_putchar('2');
    }
    if (nb < 10)
    {
        ft_putchar(nb + '0');
    }
    else
    {
        ft_putnbr_ld(nb / 10);
        ft_putchar(nb % 10 + '0');
    }
}