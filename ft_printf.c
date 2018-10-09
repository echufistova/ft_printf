/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ychufist <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/08 19:09:40 by ychufist          #+#    #+#             */
/*   Updated: 2018/10/08 19:14:27 by ychufist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include "libft/libft.h"
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
        res = (ft_print_x(ap, flntp, res));
    else if (flntp.type == 'c' || flntp.type == 'C')
        res = ft_print_c(ap, flntp, res, len);
    else if (flntp.type == 'p')
        res = ft_print_p(ap, flntp, res);
    else if (flntp.type == 's' && flntp.hljz.l == 0)
        res = ft_print_s(ap, flntp, res);
    else if (flntp.type == 'S' || flntp.hljz.l == 1)
        res = ft_print_bigs(ap, flntp, res, len);
    return (res);
}

int konec(char **res, int len)
{
	len = (int)(ft_strlen(*res) + len);
    ft_putstr(*res);
    ft_strdel(res);
	return (len);
}

int ft_printf(const char *restrict format, ...)
{
    unsigned int i;
    unsigned int j;
    int len;
    t_flagsntype flntp;
    va_list ap;
    char *res;
    char *res1;

    i = 0;
    len = 0;
    res = ft_strnew(1);
    va_start(ap, format);

    while (format[i] != '\0')
    {
        j = i;
        while (format[i] != '\0' && format[i] != '%')
            i++;
        res1 = ft_strsub(format, j, i - j);
        res = ft_strjoin_free(&res, &res1);
        if (format[i] != '\0')
			i++;
        if (format[i] != '\0' && format[i] != '%' && format[i - 1] == '%')
        {
            flntp = ft_get_flntp(format, &i, format);
            if (flntp.type == 'F' || flntp.type == 'f' || flntp.type == 'A'
		|| flntp.type == 'a' || flntp.type == 'G' || flntp.type == 'g' ||
			flntp.type == 'E' || flntp.type == 'e')
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
            res1 = ft_strsub(format, i, 1);
            res = ft_strjoin_free(&res, &res1);
            res = procent(ap, format, &i, res);
        }
    }
    len = (format[i] == '\0') ? konec(&res, len) : 0;
    va_end(ap);
    return (len);//(int)ft_strlen(res));
}

//  int main (void)
//  {
//      setlocale(LC_ALL, "");
//   int p;
//   //    #define PRINTF  "{%(+-# 0)(20.2)(ll)(d)}\n", 9223372036854775807
//      #define PRINTF "%d%d\n", 42, 41
//      printf("|%20p|\n", &p);
//     		ft_printf("|%20p|\n", &p);
// // //    printf(" %d\n", printf(PRINTF));
// // //    printf(" %d\n", ft_printf(PRINTF));
//     return (0);
// }
