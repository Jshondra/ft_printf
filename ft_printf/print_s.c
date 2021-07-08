/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_s.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jshondra <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/25 14:42:09 by jshondra          #+#    #+#             */
/*   Updated: 2020/12/08 12:42:13 by jshondra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		disp(t_box *box, int x, int len, int *i)
{
	if (box->minus != 1 && box->width > len)
		while (x--)
		{
			if (box->zero == 1 && !box->period)
				ft_putchar('0', i);
			else
				ft_putchar(' ', i);
		}
	ft_putstr(box->str, i, len);
	if (box->minus == 1 && box->width > len)
		while (x--)
			ft_putchar(' ', i);
}

void		print_s(t_box *box, va_list arr, int *i)
{
	char	*s1;
	int		x;
	int		len;

	s1 = (char *)va_arg(arr, void *);
	if (s1 == NULL)
		s1 = "(null)";
	box->str = s1;
	if ((box->precision < 0 || (box->precision > ft_strlen(s1)))
			&& box->period)
		len = ft_strlen(s1);
	else
		len = box->precision;
	if (!box->period)
		len = ft_strlen(s1);
	if (box->width < 0)
	{
		box->width *= -1;
		box->minus = 1;
	}
	if (box->width > len)
		x = box->width - len;
	else
		x = len;
	disp(box, x, len, i);
}
