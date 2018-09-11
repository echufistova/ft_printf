//
// Created by Yevheniya CHUFISTOVA on 8/16/18.
//

#include "libft.h"
#include "ft_printf.h"

char *ft_presflags(char *res, t_flagsntype flntp, intmax_t n)
{
    int i;
    intmax_t j;

    i = 0;

    j = ((flntp.type == 'x' || flntp.type == 'X' || flntp.type == 'o' || flntp.type == 'O') ? n : ft_intlength(n));
    if (flntp.sizenoll > flntp.number)
    {
		if (n < 0 && (flntp.type == 'i' || flntp.type == 'd' || flntp.type == 'D'))
            res = ft_add_char(res, '-');
        else if (flntp.plus == 1 && n >= 0 && (flntp.type == 'i' || flntp.type == 'd' || flntp.type == 'D'))
            res = ft_add_char(res, '+');
		else if (flntp.space == 1 && (flntp.type == 'i' || flntp.type == 'd' || flntp.type == 'D'))
            res = ft_add_char(res, ' ');
       // printf("hello1");
        while (i++ < flntp.sizenoll - j)
        {
            res = ft_add_char(res, '0');
        }
    }
	else if (flntp.minus == 0 && n != 0 && is_type(flntp.type))
	{
//        if (flntp.type == 'x' || flntp.type == 'X')
//            j = ft_strlen(ft_itoa_base_uns(n, 16, flntp));
//        else if ((flntp.type == 'o' || flntp.type == 'O'))
//            j = ft_strlen(ft_itoa_base_uns(n, 8, flntp));
//        else
//            j = ft_intlength(n);
             if (flntp.space == 1)
        {
            res = ft_add_char(res, ' ');
            flntp.number--;
        }
        while (i++ < flntp.number - (flntp.sizenoll > j ? flntp.sizenoll : j))
            res = ft_add_char(res, ' ');
        if (n < 0 && (flntp.type == 'i' || flntp.type == 'd' || flntp.type == 'D'))
            res = ft_add_char(res, '-');
        if (flntp.plus == 1 && n >= 0 && (flntp.type == 'i' || flntp.type == 'd' || flntp.type == 'D'))
            res = ft_add_char(res, '+');
        while (i++ <= flntp.number - j)
            res = ft_add_char(res, '0');
	}
    else
    {
        if (n < 0 && (flntp.type == 'i' || flntp.type == 'd' || flntp.type == 'D'))
            res = ft_add_char(res, '-');
        if (flntp.plus == 1 && n >= 0 && (flntp.type == 'i' || flntp.type == 'd' || flntp.type == 'D'))
            res = ft_add_char(res, '+');
        else if (flntp.space == 1 && (flntp.type == 'i' || flntp.type == 'd' || flntp.type == 'D'))
            res = ft_add_char(res, ' ');
        //printf("herre %d\n", flntp.sizenoll > j ? flntp.sizenoll : j);
        while (i++ < (flntp.sizenoll > j ? flntp.sizenoll : j) - j)
            res = ft_add_char(res, '0');
    }
    return (res);
}
