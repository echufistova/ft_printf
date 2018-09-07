# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ychufist <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/08/09 13:39:53 by ychufist          #+#    #+#              #
#    Updated: 2018/09/07 15:45:23 by ychufist         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a
	
SRCPRNTF = ./ft_printf.c \
	./ft_print_id.c\
	./ft_print_o.c \
	./ft_print_u.c \
	./ft_print_x.c\
	./ft_print_s.c \
	./ft_print_c.c\
	./ft_print_p.c\
	./ft_print_procent.c \
	./ft_add_char.c \
	./ft_itoa_unsigned.c \
	./ft_new_tout.c \
	./ft_params.c\
	./ft_flags.c\
	./ft_presflags.c\
	./ft_itoa_base_uns.c\
	./ft_octflag.c\
\
	./ft_bzero.c \
	./ft_memalloc.c\
	./ft_strdup.c \
	./ft_strlen.c \
	./ft_strsub.c \
	./ft_strjoin.c \
	./ft_atoi.c \
	./ft_itoa.c \
	./ft_putchar.c \
	./ft_putstr.c \
	./ft_putnbr.c \
	./ft_strnew.c \
	./ft_strcmp.c

OUTP = $(SRCPRNTF:.c=.o)

HDRPRNTF = ./ft_printf.h
FLAGS = -Wall -Wextra -Werror 

all: $(NAME)

%.o:%.c $(HDR)
	gcc $(FLAGS) -o $@ $<

$(NAME):
	gcc $(FLAG) -c $(SRCPRNTF) -I $(HDRPRNTF)
	ar rc $(NAME) $(OUTP)

clean:
	/bin/rm -f $(OUTP)
	/bin/rm -f *~

fclean: clean
	/bin/rm -f $(NAME)

re: fclean all

