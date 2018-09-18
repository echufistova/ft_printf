//
// Created by Yevheniya CHUFISTOVA on 7/16/18.
//

#ifndef PRINTF_FT_PRINTF_H
#define PRINTF_FT_PRINTF_H

# include <unistd.h>
# include <stdio.h>
# include <string.h>
# include <stdlib.h>
# include <ctype.h>
# include <stdarg.h>
# include <stdint.h>
# include <locale.h>
# include <wchar.h>

typedef struct      s_hljz
{
    int             hh;
    int             h;
    int             ll;
    int             l;
    int             j;
    int             z;
}                   t_hljz;

typedef struct		s_flagsntype
{
    int             oct;
    int             noll;
    int             noll2;
	int				sizenoll;
    int             minus;
    int             plus;
    int             space;
	int				dot;
    int             number;
    char            type;
    t_hljz          hljz;
}					t_flagsntype;

t_flagsntype	ft_new_flntp();
t_flagsntype	ft_get_flntp(const char *fl_tp, unsigned int *i, const char *format);
char *what_to_print(char *res, t_flagsntype flntp, va_list ap, int *len);
char *no_params(char *res, t_flagsntype flntp, unsigned int *i);
char            *ft_add_char(char *str, char c);
char			*ft_itoa_unsigned(uintmax_t n);
char			*ft_itoa_signed(intmax_t n);
int ft_intlength(intmax_t n);
int ft_intlength_uns(uintmax_t n);
int is_type(char c);
int checkflags(char c);

char *ft_itoa_base(intmax_t value, int base, t_flagsntype flntp);
char *ft_itoa_base_uns(uintmax_t value, int base, t_flagsntype flntp);

char            *ft_print_int(va_list ap, t_flagsntype flntp, char *res);
char            *ft_print_u(va_list ap, t_flagsntype flntp, char *res);
char            *ft_print_o(va_list ap, t_flagsntype flntp, char *res);
char            *ft_print_x(va_list ap, t_flagsntype flntp, char *res);
char            *ft_print_s(va_list ap, t_flagsntype flntp, char *res, int *len);
char            *ft_print_c(va_list ap, t_flagsntype flntp, char *res, int *len);
char *ft_print_p(va_list ap, t_flagsntype flntp, char *res);
char            *ft_presflags(char *res, t_flagsntype flntp, intmax_t n);
char            *ft_octflag(char *res, t_flagsntype flntp, intmax_t n);
char			*ft_minusflags(char *res, t_flagsntype flntp, intmax_t n);
char            *procent(va_list ap, const char *format, unsigned int *i, char *res);
char *insertoct(char *res, t_flagsntype flntp, intmax_t n);

int				ft_atoi(const char *str);
void	ft_bzero(void *s, size_t n);
char			*ft_itoa(long long int n);
void	*ft_memalloc(size_t size);
void	ft_putchar(unsigned int c);
void    ft_putchar_w(wchar_t c);
void	ft_putnbr(int nbr);
void	ft_putstr(char const *s);
char	*ft_strjoin(char const *s1, char const *s2);
size_t		ft_strlen(const char *str);
char	*ft_strsub(char const *s, unsigned int start, size_t len);
char *flag_space(char *res, t_flagsntype flntp, intmax_t n);
char *unsflag_space(char *res, t_flagsntype flntp, uintmax_t n);

int ft_printf(const char *restrict format, ...);

#endif //PRINTF_FT_PRINTF_H
