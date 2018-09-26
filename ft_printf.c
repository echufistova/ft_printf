//
// Created by Yevheniya CHUFISTOVA on 7/3/18.
//

#include <stdarg.h>
#include "libft.h"
#include "ft_printf.h"

char *what_to_print(char *res, t_flagsntype flntp, va_list ap, int *len)
{
    if (flntp.zirka1 == 1)
        flntp.number = va_arg(ap, int);
    if (flntp.zirka2 == 1)
        flntp.sizenoll = va_arg(ap, int);
    if (flntp.type == 'i' || flntp.type == 'd' || flntp.type == 'D')
        res = ft_print_int(ap, flntp, res);
    else if (flntp.type == 'u' || flntp.type == 'U')
        res = ft_print_u(ap, flntp, res);
    else if (flntp.type == 'o' || flntp.type == 'O')
        res = ft_print_o(ap, flntp, res);
    else if (flntp.type == 'x' || flntp.type == 'X')
        res = ft_print_x(ap, flntp, res);
    else if (flntp.type == 'c' || flntp.type == 'C')
        res = ft_print_c(ap, flntp, res, len);
    else if (flntp.type == 'p')
        res = ft_print_p(ap, flntp, res);
    else if (flntp.type == 's' && flntp.hljz.l == 0)
        res = ft_print_s(ap, flntp, res, len);
    else if (flntp.type == 'S' || flntp.hljz.l == 1)
        res = ft_print_S(ap, flntp, res, len);
    // else if (flntp.type == 'p')
    //     res = ft_print_p(ap, flntp, res);
    return (res);
}

int ft_printf(const char *restrict format, ...)
{
    unsigned int i;
    unsigned int j;
    int len;
    t_flagsntype flntp;
    va_list ap;
    char *res;

    i = 0;
    len = 0;
    res = ft_strnew(1);
    va_start(ap, format);

    while (format[i] != '\0')
    {
        j = i;
        while (format[i] != '\0' && format[i] != '%')
            i++;
            res = ft_strjoin(res, ft_strsub(format, j, i - j));
        if (format[i] != '\0')
			i++;
        if (format[i] != '\0' && format[i] != '%' && format[i - 1] == '%')
        {
            flntp = ft_get_flntp(format, &i, format);
            if (flntp.type == 'F' || flntp.type == 'f' || flntp.type == 'A' || flntp.type == 'a' ||
            flntp.type == 'G' || flntp.type == 'g' || flntp.type == 'E' || flntp.type == 'e')
                return (0);
            if (!is_type(flntp.type) ) {
                res = no_params(res, flntp, &i);
                continue;
            }
            res = what_to_print(res, flntp, ap, &len);
            len += (flntp.type == 'c' || flntp.type == 's' || flntp.type == 'C' || flntp.type == 'S')? ft_strlen(res) : 0;
            if (flntp.type == 'c' || flntp.type == 's' || flntp.type == 'C' || flntp.type == 'S')
                ft_bzero(res, ft_strlen(res));
        }
        else if (format[i] != '\0' && format[i] == '%' && format[i - 1] == '%')
        {
            res = ft_strjoin(res, ft_strsub(format, i, 1));
            res = procent(ap, format, &i, res);
        }
    }
    if (format[i] == '\0')
        ft_putstr(res);
    va_end(ap);
    return ((int)(ft_strlen(res) + len));//(int)ft_strlen(res));
}

// int main (void)
// {
//     setlocale(LC_ALL, "");
//  int p;
//  //    #define PRINTF  "{%(+-# 0)(20.2)(ll)(d)}\n", 9223372036854775807
//      #define PRINTF "{%05.s}", 0//"*Kashim a %c histoires à raconterIl fait au moins %c\n", 945
//     //unsigned int i = -4294967295;
//     //short int i = 3237;
// //    int i = -963987432;
//     //short short int i = 1;
// //    char *str = "Здравствуй, если не шутишь!";
// //    char c = -45;
// //    int a = 10;
// //    int *b = &a;
// //    printf("%p\n",b);
// //    ft_printf("%p\n",b);
//     //printf("%d\n", ft_intlength(543));
// //    printf("   printf: hello %s haha %%s tut\n", str);
// //    ft_printf("ft_printf: hello %s haha %%s tut\n", str);
//     //printf("   pr %s $\n", "this is a string");
//     //ft_printf("ft_pr %s $\n", "this is a string");
//     printf("%x\n", 5);
//    		ft_printf("%x\n", 5);
// //    printf(" %d\n", printf(PRINTF));
// //    printf(" %d\n", ft_printf(PRINTF));
//  //   unsigned long l = -42;
//  //   ft_printf("ft: %lu\n", l);
//   //  printf("pr: %lu\n", l);
//         system("leaks a.out");
//     return (0);
// }
