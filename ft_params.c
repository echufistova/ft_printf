//
// Created by echufy on 08.08.18.
//

#include "libft.h"
#include "ft_printf.h"

int ft_intlength(intmax_t n)
{
    int i;

    i = 0;
        while (n != 0)
        {
            n /= 10;
            i++;
        }
        //printf("intlength %d\n", i);
    return (i);
}