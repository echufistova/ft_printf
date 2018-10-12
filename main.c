#include "libft/ft_printf.h"

 int main (void)
{
 	setlocale(LC_ALL, "");
 	int p;
 	//#define PRINTF "aa%%bb"
 	printf("%C\n", L'ÁM-^L´');
 	ft_printf("%C\n", L'ÁM-^L´');
   printf(" %d\n", printf("%C\n", L'ÁM-^L´'));
   printf(" %d\n", ft_printf("%C\n", L'ÁM-^L´'));
 	//system("leaks a.out");
    return (0);
}