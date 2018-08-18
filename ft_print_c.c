//
// Created by Yevheniya CHUFISTOVA on 8/13/18.
//

#include "libft.h"
#include "ft_printf.h"

char *ft_print_c(va_list ap, t_flagsntype flntp, char *res)
{
    char p;
    char c;
    int i;

    i = 0;
    c = (char)(va_arg(ap, int));
    //printf("c: %c\n", c);
    p = 0;
    if (flntp.noll == 1 || flntp.number != 0)
    {
        if (flntp.noll == 1)
            p = '0';
        else if (flntp.noll == 0)
            p = ' ';
        // printf("flntp.number %d\n", flntp.number);
        // printf("flntp.number - ft_intlength((uintmax_t)(nb)) %d\n", flntp.number - ft_intlength((uintmax_t)(nb)));
        if (flntp.minus == 1)
        {
            i = 1;
            res = ft_add_char(res, c);
            while (i++ < flntp.number)
                res = ft_add_char(res, ' ');
            i = 0;
        }
        else
        {
            while (i++ < flntp.number - 1)
                res = ft_add_char(res, p);
        }
        i = 0;
    }
    else
        res = ft_add_char(res, c);
//    if (flntp.minus == 1)
//    {
//        i = 1;
//        while (i++ < flntp.number)
//            res = ft_add_char(res, ' ');
//    }
    return (flag_space(res, flntp, (int)c));
}
