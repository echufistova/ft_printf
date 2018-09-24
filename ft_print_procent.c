//
// Created by echufy on 08.08.18.
//

#include "libft.h"
#include "ft_printf.h"

char *procent(va_list ap, const char *format, unsigned int *i, char *res)
{
    while (format[*i] != '%' && format[*i] != '\0')
    {
        ft_putchar(format[*i]);
        (*i)++;
    }
    //va_arg(ap, int);
    (*i)++;
    if (format[*i] == '%' && format[*i] != '%')
        res = ft_strjoin(res, procent(ap, format, i, res));
    //return (0);
    return (res);
}