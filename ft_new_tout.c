//
//
// Created by Yevheniya CHUFISTOVA on 7/16/18.
//

#include "libft.h"
#include "ft_printf.h"

int checkflags(char c)
{
    if (c == '#' || c == '0' || c == '-' ||
            c == '+' || c == ' ' || c == '.' || c == '*' || (c >= '0' && c <= '9'))
        return (1);
    return (0);
}

t_flagsntype	ft_new_flntp()
{
    t_flagsntype flagstype;

    flagstype.oct = 0;
    flagstype.noll = 0;
    flagstype.noll2 = 0;
	flagstype.sizenoll = 0;
    flagstype.minus = 0;
    flagstype.plus = 0;
    flagstype.space = 0;
	flagstype.dot = 0;
    flagstype.number = 0;
    flagstype.hljz.hh = 0;
    flagstype.hljz.h = 0;
    flagstype.hljz.ll = 0;
    flagstype.hljz.l = 0;
    flagstype.hljz.j = 0;
    flagstype.hljz.z = 0;
    flagstype.zirka1 = 0;
    flagstype.zirka2 = 0;
    flagstype.type = '0';
    return (flagstype);
}

t_flagsntype    ft_hljz(t_flagsntype flagstype, const char *fl_tp, unsigned int *i)
{
    if (fl_tp[*i] == 'l' && fl_tp[*i + 1] != 'l')
        flagstype.hljz.l = 1;
    else if (fl_tp[*i] == 'l' && fl_tp[*i + 1] == 'l')
    {
        flagstype.hljz.ll = 1;
        (*i)++;
    }
    else if (fl_tp[*i] == 'h' && fl_tp[*i + 1] != 'h')
        flagstype.hljz.h = 1;
    else if (fl_tp[*i] == 'h' && fl_tp[*i + 1] == 'h')
    {
        flagstype.hljz.hh = 1;
        (*i)++;
    }
    else if (fl_tp[*i] == 'j')
        flagstype.hljz.j = 1;
    else if (fl_tp[*i] == 'z')
        flagstype.hljz.z = 1;
    if (fl_tp[*i] == 'h' || fl_tp[*i] == 'l' || fl_tp[*i] == 'j' || fl_tp[*i] == 'z')
            (*i)++;
    flagstype.type = fl_tp[(*i)++];
    return (flagstype);
}

t_flagsntype	ft_get_flntp(const char *fl_tp, unsigned int *i, const char *format)
{
    t_flagsntype flagstype;
    unsigned int j;
    char *n;

    flagstype = ft_new_flntp();
    n = (char*)ft_memalloc(sizeof(char));
    while (format[*i] != '\0' && checkflags(fl_tp[*i]))
    {
        if (fl_tp[*i] == '#')
            flagstype.oct = 1;
        else if (fl_tp[*i] == '0')
            flagstype.noll = 1;
        else if (fl_tp[*i] == '-')
            flagstype.minus = 1;
        else if (fl_tp[*i] == '+')
            flagstype.plus = 1;
        else if (fl_tp[*i] == ' ')
            flagstype.space = 1;
        else if (fl_tp[*i] == '*')
            flagstype.zirka1 = 1;
        else if ((fl_tp[*i] >= '0' && fl_tp[*i] <= '9') || fl_tp[*i] == '.')
        {
            while (fl_tp[*i] != '\0' && fl_tp[*i] >= '0' && fl_tp[*i] <= '9')
                n = ft_add_char(n, fl_tp[(*i)++]);
			if (fl_tp[*i] == '.')
			{    
				flagstype.dot = 1;
				flagstype.noll2 = (flagstype.noll == 1) ? 3 : 0;
                flagstype.noll = 0;
				j = ++(*i);
                if (fl_tp[(*i)] == '*')
                {
                    flagstype.zirka2 = 1;
                    (*i)++;
                }
	            while (fl_tp[*i] >= 48 && fl_tp[*i] <= 57)
    	            (*i)++;
    	   	     flagstype.sizenoll = ft_atoi(ft_strsub(fl_tp, j, *i - j));
			}
            (*i)--;
        }
        (*i)++;
    }
    flagstype.number = ft_atoi(n);
    return (ft_hljz(flagstype, fl_tp, i));
}
