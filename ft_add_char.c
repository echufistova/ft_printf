//
// Created by echufy on 08.08.18.
//

#include "ft_printf.h"
#include "libft.h"

char *ft_add_char(char *str, char c)
{
    int i;
    char *res;

    i = 0;
    res = (char *) ft_memalloc(sizeof(char) * (ft_strlen(str) + 2));
    if (str != NULL)
    {
        while (str[i] != '\0')
        {
            res[i] = str[i];
            i++;
        }
    }
    res[i] = c;
    if (str)
        free(str);
    return (res);
}