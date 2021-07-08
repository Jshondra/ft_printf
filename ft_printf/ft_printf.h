/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jshondra <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/06 20:04:00 by jshondra          #+#    #+#             */
/*   Updated: 2020/12/08 17:11:26 by jshondra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct			s_box
{
	int					zero;
	int					minus;
	int					period;
	int					width;
	int					precision;
	int					chislo;
	char				form_convers;
	char				*str;
	unsigned int		unbr;
	unsigned long		pnbr;

}						t_box;

int						ft_printf(const char *form, ...);
void					perc(char const **form, va_list arr, int *i);
int						set_flag(t_box *box, char c);
int						check_flag(t_box *box, char c);
int						form_convers(char c);
void					print_form_convers(t_box *box, va_list arr, int *i);
void					print_s(t_box *box, va_list arr, int *i);
void					print_c(t_box *box, va_list arr, int *i);
void					init(t_box *box);
void					print_d(t_box *box, va_list arr, int *i);
void					ft_putchar(char c, int *i);
void					ft_putnbr(long int n, int *point);
int						ft_strlen(char const *str);
int						ft_isdigit(int c);
int						ft_atoi(const char *str);
void					ft_putstr(char *s, int *i, int len);
void					putunbr(unsigned int n, int *point);
void					print_u(t_box *box, va_list arr, int *i);
void					puthexnbr(unsigned long num, t_box *box, int *i);
void					print_x(t_box *box, va_list arr, int *i);
void					print_p(t_box *box, va_list arr, int *i);
void					print_perc(t_box *box, int *i);

#endif
