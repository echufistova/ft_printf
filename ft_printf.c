//
// Created by Yevheniya CHUFISTOVA on 7/3/18.
//

#include <stdarg.h>
#include "libft.h"
#include "ft_printf.h"

char *what_to_print(char *res, t_flagsntype flntp, va_list ap)
{
    if (flntp.type == 'i' || flntp.type == 'd' || flntp.type == 'D')
        res = ft_print_int(ap, flntp, res);
    else if (flntp.type == 'u' || flntp.type == 'U')
        res = ft_print_u(ap, flntp, res);
    else if (flntp.type == 'o' || flntp.type == 'O')
        res = ft_print_o(ap, flntp, res);
    else if (flntp.type == 'x' || flntp.type == 'X')
        res = ft_print_x(ap, flntp, res);
    else if (flntp.type == 's')
        res = ft_print_s(ap, flntp, res);
    else if (flntp.type == 'c')
        res = ft_print_c(ap, flntp, res);
    else if (flntp.type == 'p')
        res = ft_print_p(ap, flntp, res);
    return (res);
}

int is_type(const char *format, int i)
{
    if (format[i] == 's' || format[i] == 'S' || format[i] == 'p' || format[i] == 'd' || format[i] == 'D' || format[i] == 'i' ||
        format[i] == 'o' || format[i] == 'O' || format[i] == 'u' || format[i] == 'U' || format[i] == 'x' || format[i] == 'X' ||
        format[i] == 'c' || format[i] == 'C')
        return (1);
    return (0);
}

void show_structure(t_flagsntype flntp)
{
    printf("flntp.oct = %d\n", flntp.oct);
    printf("flntp.noll = %d\n", flntp.noll);
	printf("flntp.sizenoll = %d\n", flntp.sizenoll);
    printf("flntp.minus = %d\n", flntp.minus);
    printf("flntp.plus = %d\n", flntp.plus);
    printf("flntp.space = %d\n", flntp.space);
    printf("flnt.number %d\n", flntp.number);
	printf("flntp.dot = %d\n", flntp.dot);
    printf("flntp.hljz.ll = %d\n", flntp.hljz.ll);
    printf("flntp.hljz.l = %d\n", flntp.hljz.l);
    printf("flntp.hljz.hh = %d\n", flntp.hljz.hh);
    printf("flntp.hljz.h = %d\n", flntp.hljz.h);
    printf("flntp.hljz.j = %d\n", flntp.hljz.j);
    printf("flntp.hljz.z = %d\n", flntp.hljz.z);
    printf("flntp.type = %c\n", flntp.type);
}

int ft_printf(const char *restrict format, ...)
{
    unsigned int i;
    unsigned int j;
    t_flagsntype flntp;
    va_list ap;
    char *res;

    i = 0;
    res = ft_strnew(1);
    va_start(ap, format);

    while (format[i] != '\0')
    {

        j = i;
        while (format[i] != '\0' && format[i] != '%')
            i++;
        if (!res)
            res = ft_strsub(format, j, i - j);
        else
            res = ft_strjoin(res, ft_strsub(format, j, i - j));
        if (format[i] != '\0')
			i++;
        if (format[i] != '\0' && format[i] != '%' && format[i - 1] == '%')
        {
            flntp = ft_get_flntp(format, &i, format);
//            show_structure(flntp);
//            ft_putchar('\n');
            res = what_to_print(res, flntp, ap);
        }
        else if (format[i] != '\0' && format[i] == '%' && format[i - 1] == '%')
        {
            res = ft_strjoin(res, ft_strsub(format, i, 1));
            res = procent(ap, format, &i, res);
        }
        if (format[i] == '\0')
            ft_putstr(res);
    }
    va_end(ap);
    return ((int)ft_strlen(res));
}

//int main (void)
//{
////    #define PRINTF  "{%(+-# 0)(20.2)(ll)(d)}\n", 9223372036854775807
//    #define PRINTF  "%-5.2s is a string\n", ""
//    //unsigned int i = -4294967295;
//    //short int i = 3237;
////    int i = -963987432;
//    //short short int i = 1;
////    char *str = "Здравствуй, если не шутишь!";
////    char c = -45;
////    int a = 10;
////    int *b = &a;
////    printf("%p\n",b);
////    ft_printf("%p\n",b);
//    //printf("%d\n", ft_intlength(543));
////    printf("   printf: hello %s haha %%s tut\n", str);
////    ft_printf("ft_printf: hello %s haha %%s tut\n", str);
//    //printf("   pr %s $\n", "this is a string");
//    //ft_printf("ft_pr %s $\n", "this is a string");
//    printf(PRINTF);
//    ft_printf(PRINTF);
////    printf("%d\n", printf(PRINTF));
////    printf("%d\n", ft_printf(PRINTF));
//    return (0);
//}
