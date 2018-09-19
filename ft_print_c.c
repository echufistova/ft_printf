//
// Created by Yevheniya CHUFISTOVA on 8/13/18.
//

#include "libft.h"
#include "ft_printf.h"

void ft_printnull(char *res, t_flagsntype flntp, unsigned int c, wchar_t w)
{
    if (flntp.minus == 0)
    ft_putstr(res);
        if (flntp.type == 'c')
            ft_putchar(c);
        else if (flntp.type == 'C' || flntp.hljz.l == 1)
            ft_putchar_w(w);
}

char *ft_print_c(va_list ap, t_flagsntype flntp, char *res, int *len)
{
    wchar_t w;
    char p;
    int c;
    int i;

    i = 0;
    c = 0;
    w = 0;
    if (flntp.type == 'c')
        c = (unsigned int)(va_arg(ap, int));
    else if (flntp.type == 'C' || flntp.hljz.l == 1)
        w = va_arg(ap, wchar_t);
    p = 0;
    if (flntp.noll == 1 || flntp.number != 0) {
        if (flntp.noll == 1)
            p = '0';
        else if (flntp.noll == 0)
            p = ' ';
        if (flntp.minus == 1) {
            i = 1;
            if (flntp.type == 'c')
                res = ft_add_char(res, (char) c);
            else
                {
                ft_putstr(res);
                    (*len)++;
                ft_bzero(res, ft_strlen(res));
                ft_printnull(res, flntp, c, w);
            }
            while (i++ < flntp.number)
                res = ft_add_char(res, ' ');
           // if (flntp.type == 'c')
                ft_putstr(res);
        }
        else {
            while (i++ < flntp.number - 1)
                res = ft_add_char(res, p);
        }
        //return (res);
    }
    if (!flntp.minus)
        ft_printnull(res, flntp, c, w);
    (flntp.minus == 0) ? (*len)++ : (*len); //+ ((c == '\0') ? 1 : 0);
    return (res);
}
