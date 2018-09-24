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

char *ft_print_S(va_list ap, t_flagsntype flntp, char *res, int *len)
{
    wchar_t *w_str;
    int i;
    int j;

    w_str = va_arg(ap, wchar_t*);
    if (!w_str)
        w_str = L"(null)";
    i = 0;
    j = 0;

    if (flntp.minus == 1 && flntp.dot == 0)
    {
        //printf("res do %s\n", res);
        ft_putstr(res);
        *len += ft_strlen(res);
        ft_bzero(res, ft_strlen(res));
        while (i < flntp.sizenoll)
            ft_putchar_w(w_str[i++]);//res = ft_add_char(res, w_str[i++]);
      //  printf("\nlen do v %d\n", *len);
            *len += i;
      //  printf("\nlen posle v %d\n", *len);
        if (ft_strlen_w(w_str) == 0)
            flntp.sizenoll = 0;
        if (flntp.dot == 0)// && ft_strcmp(w_str, "(null)") != 0)
        {
            ft_putstr(res);
            ft_putstr_w(w_str);
            // res = ft_strjoin(res, w_str);
        }
        //printf("res do %s\n", res);
        //i = (int)ft_strlen(str);
        i = 0;
        j = (flntp.dot == 1 ? flntp.sizenoll : ft_strlen_w(w_str));
        while (i++ < flntp.number - j)
            res = ft_add_char(res, ' ');
    }
    if (flntp.noll == 1 && ft_strcmp_w(w_str, "(null)") != 0)
    {
        while (i++ < (int)(flntp.number - ft_strlen_w(w_str)))
            res = ft_add_char(res, '0');
        ft_putstr(res);
        ft_putstr_w(w_str);
        //res = ft_strjoin(res, str);
        i = 0;
    }
    else if (flntp.number != 0 && flntp.dot == 0 && flntp.noll == 0)
    {
        while (i++ < (int)(flntp.number - ft_strlen_w(w_str)))
            res = ft_add_char(res, ' ');
        i = 0;
    }
    else if (flntp.dot == 1)
    {
        if (ft_strlen_w(w_str) == 0)
            flntp.sizenoll = 0;
        while (i++ < flntp.number - flntp.sizenoll)
            res = ft_add_char(res, ' ');
        i = 0;
        if (flntp.minus == 0)
        {
            ft_putstr(res);
            *len += ft_strlen(res);
            ft_bzero(res, ft_strlen(res));
            while (i < flntp.sizenoll)
                ft_putchar_w(w_str[i++]);
            //*len += i - 1;//res = ft_add_char(res, w_str[i++]);
        }
    }
    if (ft_strcmp_w(w_str, "(null)") == 0)
    {
        res = ft_strjoin(res, "(null)");
        ft_putstr(res);
    }
    else
    {
        if (flntp.dot == 0 && flntp.noll == 0 && flntp.minus == 0)
        {
            ft_putstr(res);
            *len += ft_strlen(res);
            ft_bzero(res, ft_strlen(res));
            ft_putstr_w(w_str);//res = ft_strjoin(res, w_str);
        }
        //ft_putstr(res);
    }
    *len += ft_strlen_w(w_str);
    ft_putstr(res);
    return (res);
}
