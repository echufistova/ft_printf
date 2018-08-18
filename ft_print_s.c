//
// Created by Yevheniya CHUFISTOVA on 8/9/18.
//

#include "libft.h"
#include "ft_printf.h"

char *ft_print_s(va_list ap, t_flagsntype flntp, char *res)
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
		if (flntp.dot == 0)
       		 res = ft_strjoin(res, str);
        //printf("res do %s\n", res);
        //i = (int)ft_strlen(str);
        i = 0;
        j = (flntp.dot == 1 ? flntp.sizenoll :ft_strlen(str));
        while (i++ < flntp.number - j)//flntp.sizenoll)
            res = ft_add_char(res, ' ');
        // printf("res posle  %s", res);
        return (res);
     }
    if (flntp.noll == 1)
    {
        while (i++ < flntp.number - ft_strlen(str))
            res = ft_add_char(res, '0');
        i = 0;
    }
    if (flntp.number != 0 && flntp.dot == 0)
    {
        while (i++ < flntp.number - ft_strlen(str))
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
        while (i < flntp.sizenoll)
            res = ft_add_char(res, str[i++]);
        return (res);

    }
	 res = ft_strjoin(res, str);
    return (res);
}
