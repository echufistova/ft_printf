//
// Created by Yevheniya CHUFISTOVA on 8/9/18.
//

#include "libft.h"
#include "ft_printf.h"

char *ft_print_s(va_list ap, t_flagsntype flntp, char *res, int *len)
{
    char *str;
    int i;
	int j;

    str = ft_strdup(va_arg(ap, char*));
    //printf("%s\n", str);
    i = 0;
    if (flntp.minus == 1)
    {
		//printf("res do %s\n", res);
            while (i < flntp.sizenoll)
                res = ft_add_char(res, str[i++]);
        if (ft_strlen(str) == 0)
            flntp.sizenoll = 0;
		if (flntp.dot == 0 && ft_strcmp(str, "(null)") != 0)
       		 res = ft_strjoin(res, str);
        //printf("res do %s\n", res);
        //i = (int)ft_strlen(str);
        i = 0;
        j = (flntp.dot == 1 ? flntp.sizenoll :ft_strlen(str));
        while (i++ < flntp.number - j)//flntp.sizenoll)
            res = ft_add_char(res, ' ');
        // printf("res posle  %s", res);
        //return (res);

     }
    if (flntp.noll == 1 && ft_strcmp(str, "(null)") != 0)
    {
        while (i++ < (int)(flntp.number - ft_strlen(str)))
            res = ft_add_char(res, '0');
        res = ft_strjoin(res, str);
        i = 0;
    }
    if (flntp.number != 0 && flntp.dot == 0 && flntp.noll == 0)
    {
        while (i++ < (int)(flntp.number - ft_strlen(str)))
            res = ft_add_char(res, ' ');
        i = 0;
    }
    if (flntp.dot == 1)
    {
		if (ft_strlen(str) == 0)
            flntp.sizenoll = 0;
        while (i++ < flntp.number - flntp.sizenoll) //> (int)ft_strlen(str) ? flntp.sizenoll : (int)ft_strlen(str)))
            res = ft_add_char(res, ' ');
        i = 0;
        if (flntp.minus == 0)
        {
            while (i < flntp.sizenoll)
                res = ft_add_char(res, str[i++]);
        }

      //  return (res);

    }
    if (ft_strcmp(str, "(null)") == 0)//(!str && !*str)//str == 0)
    {
        res = ft_strjoin(res, "(null)");
        ft_putstr(res);
        //(*len) += 6;
    }
        //else if (ft_strlen(str) == 0
    else
    {
		if (flntp.dot == 0 && flntp.noll == 0 && flntp.minus == 0)
            res = ft_strjoin(res, str);
       // if (flntp.dot == 1 || flntp.noll == 1 || flntp.minus == 1 || (flntp.number > 0 && (flntp.dot == 1  || flntp.noll == 1)))
         //   ft_bzero(str, ft_strlen(str));
        //res = ft_strjoin(res, str);
        //ft_putstr(ft_strjoin(res, str));
        ft_putstr(res);
    }
    return (res);
}
