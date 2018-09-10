//
// Created by Yevheniya CHUFISTOVA on 8/13/18.
//

#include "libft.h"
#include "ft_printf.h"

void ft_printnull(char *res, t_flagsntype flntp, int c)
{
    //if (c == '\0')
    ft_putstr(res);
    if (flntp.minus == 0)
        ft_putchar(c);
}

char *ft_print_c(va_list ap, t_flagsntype flntp, char *res, int *len)
{
    char p;
    int c;
    int i;

    i = 0;
    c = (va_arg(ap, int));
    //printf("c: %c\n", c);
    p = 0;
    if (flntp.noll == 1 || flntp.number != 0)
    {
        if (flntp.noll == 1)
            p = '0';
        else if (flntp.noll == 0)
            p = ' ';
        if (flntp.minus == 1)
        {
            i = 1;
            res = ft_add_char(res, (char)c);
            while (i++ < flntp.number)
                res = ft_add_char(res, ' ');
        }
        else
        {
            while (i++ < flntp.number - 1)
                res = ft_add_char(res, p);
        }
        i = 0;
    }
    //else if (c != '\0')
   // {
        //res = ft_add_char(flag_space(res, flntp, (int)c), c);
        //ft_putchar('\0');
     //   *len += ((c == '\0') ? 1 : 0);
     //   printf("\nlen : %d\n", *len);
        //return (ft_itoa_unsigned(len));
    //}
    ft_printnull(res, flntp, c);
    (flntp.minus == 0) ? (*len)++ : (*len); //+ ((c == '\0') ? 1 : 0);
    return (res);
}
