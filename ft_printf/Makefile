# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jshondra <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/12/08 17:56:38 by jshondra          #+#    #+#              #
#    Updated: 2020/12/08 17:58:41 by jshondra         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

CFLAGS = -Wall -Wextra -Werror

SRCS = check_flag.c	ft_putnbr.c	print_form_convers.c form_convers.c	\
	   ft_strlen.c	print_s.c ft_atoi.c init.c set_flag.c ft_isdigit.c\
	   ft_printf.c perc.c ft_putchar.c print_c.c print_d.c ft_putstr.c\
	   print_u.c putunbr.c puthexnbr.c print_x.c print_p.c print_perc.c   

HEAD = ft_printf.h

OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	ar rc $(NAME) $(OBJS)
	ranlib $(NAME)

%.o: %.c $(HEAD)
	gcc $(CFLAGS) -c $< -o $@

clean:
	rm -rf $(OBJS)

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re
