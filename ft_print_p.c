//
// Created by Yevheniya CHUFISTOVA on 8/18/18.
//

#include "ft_printf.h"

char *ft_print_p(va_list ap, t_flagsntype flntp, char *res)
{
    unsigned long n;
    char *s;

    n = (unsigned long)va_arg(ap, void *);

	if (n != 0)
	    s = ft_itoa_base_uns(n, 16, flntp);
	else
	{
		s = "0x0";
		flntp.number--;
	}
	flntp.number--;
	if (flntp.minus == 1 || flntp.noll == 1)
	{
		if (flntp.noll == 1)
			flntp.number--;
		//res = ft_strjoin(insertoct(res, flntp, n), s);
		res = (flag_space(ft_strjoin(insertoct(res, flntp, n), s), flntp, n));
	}
	else
	{
		//res = (flag_space(res, flntp, n));
		res = ft_strjoin(insertoct(flag_space(res, flntp, n), flntp, n), s);
	}
    return (res);
}
