//
// Created by Yevheniya CHUFISTOVA on 7/10/18.
//

#include "libft.h"
#include "ft_printf.h"

char    *ft_print_x(va_list ap, t_flagsntype flntp, char *res)
{
    unsigned long int n;
    intmax_t s;
    int j;

    if (flntp.hljz.ll != 0 || flntp.hljz.l != 0)
        n = (flntp.hljz.ll == 1 ? va_arg(ap, unsigned long long int) : va_arg(ap, unsigned long int));
    else if (flntp.hljz.h == 1)
        n = (unsigned short)va_arg(ap, int);
    else if (flntp.hljz.hh == 1)
        n = (unsigned char)va_arg(ap, int);
    else if (flntp.hljz.j == 1)
        n = va_arg(ap, uintmax_t);
    else if (flntp.hljz.z == 1)
        n = va_arg(ap, size_t);
    else
        n = va_arg(ap, unsigned int);
    if (n == 0)
    {
        if (flntp.dot == 1)
            return (flag_space(res, flntp, n));
        else
        {
            flntp.number--;
            return (ft_add_char(flag_space(res, flntp, n), '0'));
        }
    }
    s = ft_strlen(ft_itoa_base_uns((intmax_t)n, 16, flntp));
	if (flntp.oct == 1 && flntp.sizenoll < flntp.number)
        flntp.number = flntp.number - 2;
    res = (flntp.oct == 1) ? ft_octflag(res, flntp, s) : flag_space(res, flntp, s);
    j = (int)ft_strlen(ft_itoa_base_uns((intmax_t)n, 16, flntp));
    res = ft_strjoin(res, ft_itoa_base_uns((intmax_t)n, 16, flntp));
    if (flntp.minus == 1)
    {
        while (j++ < flntp.number)
            res = ft_add_char(res, ' ');
    }
    return (res);
}
