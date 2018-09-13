//
// Created by echufy on 08.08.18.
//

#include "libft.h"
#include "ft_printf.h"

char    *ft_print_int(va_list ap, t_flagsntype flntp, char *res)
{
    intmax_t n;
    int s;
    int i;

    if (flntp.hljz.l == 1 || flntp.type == 'D')
        n = va_arg(ap, long int);//res = ft_strjoin(res, ft_itoa(va_arg(ap, long int)));
    else if (flntp.hljz.ll == 1)
        n = va_arg(ap, long long int);//res = ft_strjoin(res, ft_itoa(va_arg(ap, long long int)));
	else if (flntp.hljz.h == 1)
        n = (short)va_arg(ap, int);
    else if (flntp.hljz.hh == 1)
        n = (signed char)va_arg(ap, int);
	else if (flntp.hljz.j == 1)
        n = va_arg(ap, intmax_t);
    else if (flntp.hljz.z == 1)
        n = va_arg(ap, size_t);
    else
        n = va_arg(ap, int);//res = ft_strjoin(res, ft_itoa(va_arg(ap, int)));
    //else if (flntp.hljz.h == 1 && (flntp.type == 'i' || flntp.type == 'd'))
    //  res = ft_strjoin(res, ft_itoa(va_arg(ap, short int)));
    //else if (flntp.hljz.hh == 1 && (flntp.type == 'i' || flntp.type == 'd'))
    //   res = ft_strjoin(res, ft_itoa(va_arg(ap, short short int)));
    //  printf("n: %ji\n", n);
    //res = flag_space(res,flntp, &n);
    if (flntp.minus == 1 && n != 0)
    {
        if (n < 0)
        {
            if (flntp.dot == 0)
                res = ft_add_char(res, '-');
            flntp.number--;
        }
        if (flntp.plus == 1 && n >= 0)
        {
          //  res = ft_add_char(res, '+');
            flntp.number--;
        }
        i = ft_intlength(n);
//        i--;
////        printf("%d\n", flntp.sizenoll - i);
//        while (i++ < flntp.sizenoll - i)
//            res = ft_add_char(res, '0');
        res = ft_strjoin(flag_space(res, flntp, n), ft_itoa_signed(n));
        i = 0;
        if (flntp.dot == 1 && n == 0)//(n == 0 || res[ft_strlen(res) - 1] == '0'))
            res[ft_strlen(res) - 1] = '\0';
        //printf("i: %d\n", i);
        while (i++ < flntp.number - (flntp.sizenoll > ft_intlength(n) ? flntp.sizenoll : ft_intlength(n)))
            res = ft_add_char(res, ' ');
        return (res);
    }
    //res = (n == 0 ? ft_add_char(flag_space(res,flntp, &n), '0') : ft_strjoin(flag_space(res,flntp, &n), ft_itoa_unsigned(n)));
	 if (n == 0)
    {
        if (flntp.plus == 1 && n >= 0)
            flntp.number--;
        if (flntp.dot == 1)
            return (flag_space(res, flntp, n));
        else if (flntp.minus == 1)
        {

            res = ft_strjoin(flag_space(res, flntp, n), ft_itoa_signed(n));
            i  = 1;
            while (i++ < flntp.number - (flntp.sizenoll > ft_intlength(n) ? flntp.sizenoll : ft_intlength(n)))
                res = ft_add_char(res, ' ');
        }
        else
        {
            flntp.number = (flntp.noll == 1) ? flntp.number - 1 : flntp.number;
            return (ft_add_char(flag_space(res, flntp, n), '0'));
        }
    }
    else
        return (ft_strjoin(flag_space(res,flntp, n), ft_itoa_signed(n)));
    return (res);
}
