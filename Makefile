# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ychufist <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/08/09 13:39:53 by ychufist          #+#    #+#              #
#    Updated: 2018/10/01 16:34:59 by ychufist         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a
	
SRCPRNTF = ./ft_printf.c \
	./ft_print_id.c\
	./ft_print_o.c \
	./ft_print_u.c \
	./ft_print_x.c\
	./ft_print_bigs.c\
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

OUTP = $(SRCPRNTF:.c=.o)

FLAGS = -Wall -Wextra -Werror

LIBA = ./libft/libft.a

all: $(NAME)

$(NAME):
	gcc $(FLAGS) -c libft/*.c -I libft/libft.h
	gcc -c $(SRCPRNTF)
	ar rc $(NAME) *.o

%.o:%.c
	gcc $(FLAGS) -o $< -c &< $(LIBA)

clean:
	/bin/rm -f *.o libft/*.o
	/bin/rm -f *~

fclean: clean
	/bin/rm -f $(NAME) libft/*.a

re: fclean all
