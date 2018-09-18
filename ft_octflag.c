//
// Created by Yevheniya CHUFISTOVA on 8/16/18.
//

#include "ft_printf.h"

char *insertoct(char *res, t_flagsntype flntp, intmax_t n)
{
    if (n != 0 && (flntp.type == 'x' || flntp.type == 'p'))
    {
        res = ft_add_char(res, '0');
        res = ft_add_char(res, 'x');
    }
    else if (flntp.type == 'X' && n != 0)
    {
        res = ft_add_char(res, '0');
        res = ft_add_char(res, 'X');
    }
    else if ((flntp.type == 'o' || flntp.type == 'O') && n != 0)
        res = ft_add_char(res, '0');
    return (res);
}

char *ft_octflag(char *res, t_flagsntype flntp, intmax_t n)
{
    uintmax_t nb;
    int i;
    intmax_t j;

    i = 0;
    nb = (uintmax_t )(n < 0 ? (-(n)) : n);
    j = ((flntp.type == 'x' || flntp.type == 'X' || flntp.type == 'o' || flntp.type == 'O' || flntp.type == 'p') ? n : ft_intlength(nb));
    if (flntp.oct == 1 && n != 0)
    {
        if ((flntp.noll == 1 || flntp.sizenoll > flntp.number) && flntp.minus == 0 )
        {
            if (n < 0 && (flntp.type == 'i' || flntp.type == 'd' || flntp.type == 'D'))
               res = ft_add_char(res, '-');
            else if (flntp.plus == 1 && (flntp.type == 'i' || flntp.type == 'd' || flntp.type == 'D'))
                res = ft_add_char(res, '+');
             else if (flntp.space == 1 && (flntp.type == 'i' || flntp.type == 'd' || flntp.type == 'D'))
                res = ft_add_char(res, ' ');
            res = insertoct(res, flntp, n);
//            printf("numr %d\n", flntp.number);
//            printf("ft_intlength((uintmax_t)(nb) %d\n", ft_intlength((uintmax_t)(nb)));
            while (i++ < (flntp.sizenoll > flntp.number ? flntp.sizenoll : flntp.number) - j)
                 res = ft_add_char(res, '0');
        }
        else if (flntp.noll == 0 && flntp.sizenoll == 0 && flntp.minus == 0 && flntp.noll2 == 0)
        {
            while (i++ < flntp.number - j)
                 res = ft_add_char(res, ' ');
            if (n < 0 && (flntp.type == 'i' || flntp.type == 'd' || flntp.type == 'D'))
                res = ft_add_char(res, '-');
            else if (flntp.plus == 1 && (flntp.type == 'i' || flntp.type == 'd' || flntp.type == 'D'))
                res = ft_add_char(res, '+');
            res = insertoct(res, flntp, n);
        }
        else if (flntp.sizenoll  < flntp.number && flntp.minus == 0)
        {
//            printf("flntp len %d\n", ft_intlength(n));
//            printf("flntp number %d\n", flntp.number);
//            printf("flntp  %d\n", flntp.sizenoll > j ? flntp.sizenoll : j);
//            printf("flntp - %d\n", flntp.number - (flntp.sizenoll > j ? flntp.sizenoll :
//                                                   j) + ((flntp.type == 'x' || flntp.type == 'X') ? 1 : 0));
            if (is_type(flntp.type)) {
                while (i++ < flntp.number - (flntp.sizenoll > j ? flntp.sizenoll :
                                             j) )//+ ((flntp.type == 'x' || flntp.type == 'X') ? 1 : 0))
                    res = ft_add_char(res, ' ');
            }
            if (n < 0 && (flntp.type == 'i' || flntp.type == 'd' || flntp.type == 'D'))
                res = ft_add_char(res, '-');
            else if (flntp.plus == 1 && n >= 0 && (flntp.type == 'i' || flntp.type == 'd' || flntp.type == 'D'))
                res = ft_add_char(res, '+');
            res = insertoct(res, flntp, n);
//            printf("flntp number %d\n", flntp.number);
//            printf("flntp number %d\n", ft_intlength(n));
            while (i++ < flntp.number -  j + ((flntp.type == 'x' ||
                    flntp.type == 'X' || (flntp.type == 'i' || flntp.type == 'd' || flntp.type == 'D')) ? 1 : 0))
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
            res = insertoct(res, flntp, n);
           // if  (flntp.number >= flntp.sizenoll && flntp.sizenoll != 0 && flntp.noll2 == 3) {
           //          while (i++ < flntp.number - j)
           //              res = ft_add_char(res, '0');
           //      }
        }
    }
	else
    {
        flntp.number--;
        if (flntp.number > flntp.sizenoll && flntp.noll == 0 && flntp.minus == 0)
        {
             while (i++ < flntp.number)
                res = ft_add_char(res, ' ');
        }
        if (flntp.plus == 1 && n >= 0 && (flntp.type == 'i' || flntp.type == 'd' || flntp.type == 'D'))
            res = ft_add_char(res, '+');
        else if (flntp.space == 1 && (flntp.type == 'i' || flntp.type == 'd' || flntp.type == 'D'))
        {
            res = ft_add_char(res, ' ');
            flntp.number--;
        }
        if (flntp.sizenoll > flntp.number)
        {
            while (i++ < (flntp.sizenoll > flntp.number ? flntp.sizenoll : flntp.number) - j)
                res = ft_add_char(res, '0');
        }
        else if (flntp.number != 0 && flntp.noll == 1 && flntp.minus == 0 && flntp.dot == 0)
        {
            flntp.number = (flntp.noll == 1) ? flntp.number + 1 : flntp.number;
            while (i++ < flntp.number)// - 1)
                res = ft_add_char(res, '0');
        }
        return (res);
    }
    return (res);
}
