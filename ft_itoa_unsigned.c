//
// Created by echufy on 08.08.18.
//

#include "libft.h"
#include "ft_printf.h"

static char		*print_positive_numbers_uns(char *res, intmax_t n, int i)
{
    n = (n > 0 ? n : -n);
    if (!(res = (char*)ft_memalloc(sizeof(char) * (i + 1))))
        return (NULL);
    while (i > 0)
    {
        res[i - 1] = (uintmax_t )n % 10 + 48;
        n = (uintmax_t )n / 10;
        i--;
    }
    return (res);
}

char			*ft_itoa_unsigned(intmax_t n)
{
    char				*res;
    int					i;

    res = NULL;
    i = ft_intlength((uintmax_t )n);
    if (n != 0)
        return (print_positive_numbers_uns(res, n, i));
    res = ft_memalloc(2);
    res[0] = '0';
    return (res);
}
