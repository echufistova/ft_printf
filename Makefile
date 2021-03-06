# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ychufist <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/03/24 14:31:10 by ychufist          #+#    #+#              #
#    Updated: 2018/04/19 17:05:46 by ychufist         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

SRCLIBA = libft/ft_memset.c libft/ft_bzero.c libft/ft_memcpy.c\
		libft/ft_memccpy.c libft/ft_memmove.c libft/ft_memchr.c\
		libft/ft_memcmp.c libft/ft_strlen.c libft/ft_strdup.c\
		libft/ft_strncpy.c libft/ft_strcpy.c libft/ft_strstr.c\
		libft/ft_strnstr.c libft/ft_strcmp.c libft/ft_strncmp.c\
		libft/ft_strchr.c libft/ft_strrchr.c libft/ft_toupper.c\
		libft/ft_tolower.c libft/ft_isalpha.c libft/ft_isalnum.c\
		libft/ft_isprint.c libft/ft_isdigit.c libft/ft_isascii.c\
		libft/ft_strcat.c libft/ft_strncat.c libft/ft_atoi.c libft/ft_itoa.c\
		libft/ft_memalloc.c libft/ft_memdel.c libft/ft_strnew.c\
		libft/ft_strdel.c libft/ft_strclr.c libft/ft_striter.c\
		libft/ft_striteri.c libft/ft_strmap.c libft/ft_strmapi.c\
		libft/ft_strequ.c libft/ft_strnequ.c libft/ft_strsub.c\
		libft/ft_strjoin.c libft/ft_strlcat.c libft/ft_strtrim.c\
		libft/ft_strsplit.c libft/ft_putchar.c libft/ft_putstr.c\
		libft/ft_putendl.c libft/ft_putnbr.c libft/ft_putchar_fd.c\
		libft/ft_putstr_fd.c libft/ft_putendl_fd.c libft/ft_putnbr_fd.c\
		libft/ft_cl.c libft/ft_cw.c libft/ft_lstnew.c libft/ft_lstdelone.c\
		libft/ft_lstdel.c libft/ft_lstadd.c libft/ft_lstiter.c libft/ft_lstmap.c\
		 libft/ft_foreach.c libft/ft_mmap.c libft/ft_sqrt.c libft/ft_intlength.c
	  
SRCPRNTF = libft/ft_printf.c \
		libft/ft_print_id.c\
	  	libft/ft_print_o.c\
	  	libft/ft_print_x_u.c\
	  	libft/ft_print_bigs.c\
	  	libft/ft_print_s.c\
	  	libft/ft_print_c.c\
	  	libft/ft_print_p.c\
	  	libft/ft_itoa_unsigned.c \
	  	libft/ft_new_tout.c\
	  	libft/ft_params.c\
	  	libft/ft_flags.c\
	  	libft/ft_presflags.c\
	  	libft/ft_octflag.c\
	  	libft/ft_dopfile.c\
	  	libft/ft_dopfile1.c

# OUTLIBA = $(SRCLIBA:.c=.o)

# OUTPRNTF = $(SRCPRNTF:.c=.o)

HDR = libft/libft.h libft/ft_printf.h

FLAGS = -Wall -Wextra -Werror 

all: $(NAME)

$(NAME): 
	gcc $(FLAG) -c $(SRCLIBA) $(SRCPRNTF) -I $(HDR)
	ar rc $(NAME) *.o

clean:
	/bin/rm -f *.o
	/bin/rm -f *~

fclean: clean
	/bin/rm -f $(NAME)

re : fclean all
