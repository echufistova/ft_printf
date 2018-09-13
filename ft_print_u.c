//
// Created by Yevheniya CHUFISTOVA on 7/9/18.
//

#include "libft.h"
#include "ft_printf.h"

char    *ft_print_u(va_list ap, t_flagsntype flntp, char *res)
{
    uintmax_t n;
    int i;

    if (flntp.hljz.l == 1 || flntp.type == 'U')
        n = va_arg(ap, unsigned long);
    else if (flntp.hljz.ll == 1)
        n = va_arg(ap, unsigned long long);
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
//    printf("hello %ju\n", n );
//    if (flntp.plus == 1 && n > 0)
//    {
//        res = ft_add_char(res, '+');
//        flntp.sizenoll--;
//    }
//    if (flntp.noll == 1)
//    {
//        while (i++ < flntp.sizenoll - ft_intlength(n))
//            res = ft_add_char(res, '0');
//    }
    if (n == 0)
        flntp.number = (flntp.minus || flntp.noll) ? flntp.number - 1 : flntp.number;
    res = ft_strjoin(unsflag_space(res, flntp, n), ft_itoa_unsigned(n));
    if (flntp.minus == 1)
    {
        i = ft_intlength_uns(n);
        while (i++ < flntp.number)
            res = ft_add_char(res, ' ');
    }
    if (flntp.dot == 1 && n == 0)//(n == 0 || res[ft_strlen(res) - 1] == '0'))
        res[ft_strlen(res) - 1] = '\0';
    return (res);
}
