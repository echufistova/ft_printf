//
// Created by Yevheniya CHUFISTOVA on 8/18/18.
//

#include "ft_printf.h"

char *ft_print_p(va_list ap, t_flagsntype flntp, char *res)
{
    unsigned long n;
    char *s;
    int i;

    i = 0;
    n = (unsigned long)va_arg(ap, void *);

	if (n != 0)
	    s = ft_itoa_base_uns(n, 16, flntp);
	else if (flntp.dot && !flntp.sizenoll)
	{
		s = "0x";
		//flntp.number--;
	}
	else
	{
		s = "0x0";
		flntp.number--;
	}
	flntp.number-=2;
	if (flntp.minus == 1 || flntp.noll == 1)
	{
//		if (flntp.noll == 1)
//			flntp.number--;
		res = ft_strjoin(insertoct(res, flntp, n), s);//ft_strjoin(insertoct(res, flntp, n), s);
        if (flntp.noll == 1 && flntp.minus == 0) {
            while (i++ < flntp.number)
                res = ft_add_char(res, '0');
        }
        else if (flntp.minus == 1 && flntp.number != 0)
        {
            if (flntp.number > 0 && flntp.number > ft_strlen(s))
            {
            	while (i++ < flntp.number - ft_strlen(s))
                	res = ft_add_char(res, ' ');
            }
        }
		//res = ft_strjoin(res, s);
	}
	else if (flntp.oct == 0 && n != 0)
		res = (flntp.number > flntp.sizenoll)?
			  ft_strjoin(insertoct(flag_space(res, flntp, ft_strlen(s)), flntp, ft_strlen(s)), s) :
			  ft_strjoin(flag_space(insertoct(res, flntp, ft_strlen(s)), flntp, ft_strlen(s)), s);
	else
	{
		flntp.oct = 0;
		while (i++ < flntp.number)
			res = ft_add_char(res, ' ');
		if (flntp.sizenoll > flntp.number)
		{
			res = ft_strjoin(res, s);
			while (i++ < flntp.sizenoll)
				res = ft_add_char(res, '0');
		}
		else
			res = ft_strjoin(res, s);
		//res = (flag_space(res, flntp, n));
		//res = ft_strjoin(flag_space(res, flntp, ft_strlen(s)), s);
	}
    return (res);
}
