//
// Created by Yevheniya CHUFISTOVA on 8/9/18.
//

#include "libft.h"
#include "ft_printf.h"

size_t ft_strlen_w(wchar_t *w_str)
{
    size_t i;

    i = 0;
    if (w_str != NULL)
    {
        while (w_str[i])
        i++;
    }
    return (i);
}

void ft_putstr_w(wchar_t *w_str)
{
    int i;

    i = 0;
    while (w_str[i])
    {
        ft_putchar_w(w_str[i]);
        i++;
    }
}

int ft_strcmp_w(const wchar_t *str1, const char *str2)
{
    int             i;
    unsigned char   *s1;
    unsigned char   *s2;

    i = 0;
    s1 = (unsigned char *)str1;
    s2 = (unsigned char *)str2;
    while (s1[i] != '\0' && s2[i] != '\0')
    {
        if (s1[i] != s2[i])
            return (s1[i] - s2[i]);
        i++;
    }
    return (s1[i] - s2[i]);
}

char *flntpminus(char *res, t_flagsntype *flntp, char *str, int *i)
{
    int j;

    while (*i < flntp->sizenoll)
        res = ft_add_char(&res, str[(*i)++]);
    if (ft_strlen(str) == 0)
        flntp->sizenoll = 0;
    if (flntp->dot == 0 && ft_strcmp(str, "(null)") != 0)
        res = ft_strjoin(res, str);
    *i = 0;
    j = (flntp->dot == 1 ? flntp->sizenoll : ft_strlen(str));
    while ((*i)++ < flntp->number - j)
        res = ft_add_char(&res, ' ');
    return (res);
}

char *flntpdot(char *res, t_flagsntype *flntp, char *str, int *i)
{
    if (ft_strlen(str) == 0)
            flntp->sizenoll = 0;
        if (flntp->sizenoll > 0 || ft_strlen(str) == 0) {
            while ((*i)++ < flntp->number - (flntp->sizenoll < (int) ft_strlen(str) ?
                                         flntp->sizenoll : (int) ft_strlen(str)))
                res = ft_add_char(&res, ' ');
        }
        else
        {
            while ((*i)++ < flntp->number - (flntp->sizenoll < (int) ft_strlen(str) ?
                                         flntp->sizenoll : (int) ft_strlen(str)))
                res = ft_add_char(&res, '0');
        }
        *i = 0;
        if (flntp->minus == 0)
        {
            while (*i < flntp->sizenoll)
                res = ft_add_char(&res, str[(*i)++]);
        }
        return (res);
}

char *nollbla(char *res, t_flagsntype flntp, char *str, int i)
{
    if (flntp.noll == 1 && ft_strcmp(str, "(null)") != 0)
    {
        while (i++ < (int)(flntp.number - ft_strlen(str)))
            res = ft_add_char(&res, '0');
        res = ft_strjoin(res, str);
        i = 0;
    }
    if (flntp.number != 0 && flntp.dot == 0 && flntp.noll == 0)
    {
        while (i++ < (int)(flntp.number - ft_strlen(str)))
            res = ft_add_char(&res, ' ');
        i = 0;
    }
    return (res);
}

char *ft_print_s(va_list ap, t_flagsntype flntp, char *res)
{
    char *str;
    int i;
	int j;

    str = ft_strdup(va_arg(ap, char*));
    i = 0;
    if (flntp.minus == 1)
        res = flntpminus(res, &flntp, str, &i);
    res = nollbla(res, flntp, str, i);
    if (flntp.dot == 1)
        res = flntpdot(res, &flntp, str, &i);
    if (ft_strcmp(str, "(null)") == 0)
    {
        res = ft_strjoin(res, "(null)");
        ft_putstr(res);
    }
    else
    {
		if (flntp.dot == 0 && flntp.noll == 0 && flntp.minus == 0)
            res = ft_strjoin_free(&res, &str);
        ft_putstr(res);
    }
    return (res);
}




