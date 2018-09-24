//
// Created by Yevheniya CHUFISTOVA on 7/11/18.
//

#include "libft.h"
#include "ft_printf.h"

char    *ft_print_o(va_list ap, t_flagsntype flntp, char *res)
{
    uintmax_t n;
    intmax_t s;
    int j;

    j = 0;
    if (flntp.type == 'O' || flntp.hljz.ll != 0 || flntp.hljz.l != 0)
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
        if ((flntp.oct == 0 && flntp.dot != 0) || flntp.sizenoll != 0)
            return (flag_space(res, flntp, n));
        // else
        // {
        //     flntp.number = (flntp.noll == 1) ? flntp.number - 1 : flntp.number;
        //     return (ft_add_char(flag_space(res, flntp, n), '0'));
        // }
        else 
        {
            flntp.number = (flntp.minus || flntp.noll) ? flntp.number - 1 : flntp.number;
            if (flntp.minus == 1)
            {
                res = ft_add_char(res, '0');
                //flntp.number--;
                while (j++ < flntp.number - (flntp.sizenoll > ft_intlength(n) ? flntp.sizenoll : ft_intlength(n)))
                    res = ft_add_char(res, ' ');
                return (flag_space(res, flntp, n));
            }
            else
                return (ft_add_char(flag_space(res, flntp, n), '0'));
        }
    }
    s = ft_strlen((ft_itoa_base_uns((intmax_t)n, 8, flntp)));
    //j = (j > flntp.sizenoll) ? j : flntp.sizenoll;
    if (flntp.oct == 1)// && flntp.sizenoll < flntp.number)
    {
        flntp.number--;
        flntp.sizenoll = (flntp.sizenoll > 0) ? flntp.sizenoll - 1 : flntp.sizenoll;
    }
    res = (flntp.oct == 1) ? ft_octflag(res, flntp, s) : flag_space(res, flntp, s);
    res = ft_strjoin(res, ft_itoa_base_uns((intmax_t)n, 8, flntp));
    j = 0;
    if (flntp.minus == 1)
    {
        while (j++ < flntp.number - (flntp.sizenoll > s ? flntp.sizenoll : s))
            res = ft_add_char(res, ' ');
    }
    return (res);
}
