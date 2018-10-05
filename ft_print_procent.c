//
// Created by echufy on 08.08.18.
//

#include "libft.h"
#include "ft_printf.h"

char *procent(va_list ap, const char *format, unsigned int *i, char *res)
{
    char *res1;

    while (format[*i] != '%' && format[*i] != '\0')
    {
        ft_putchar(format[*i]);
        (*i)++;
    }
    //va_arg(ap, int);
    (*i)++;
    if (format[*i] == '%' && format[*i] != '%')
    {
        res1 = procent(ap, format, i, res);
        res = ft_strjoin_free(&res, &res1);
    }
    return (res);
}