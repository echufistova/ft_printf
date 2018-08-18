//
// Created by Yevheniya CHUFISTOVA on 8/18/18.
//

#include "ft_printf.h"

char *ft_print_p(va_list ap, t_flagsntype flntp, char *res)
{
    unsigned long n;
    char *s;

    n = (unsigned long)va_arg(ap, void *);

    s = ft_itoa_base_uns(n, 16, flntp);
    res = (flag_space(res, flntp, n));

    res = ft_strjoin(insertoct(res, flntp, n), s);
    return (res);
}
