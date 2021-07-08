/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_x.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jshondra <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/01 14:38:31 by jshondra          #+#    #+#             */
/*   Updated: 2020/12/08 12:56:14 by jshondra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	disp_x(t_box *box, int j, int num, int *i)
{
	if (box->minus != 1 && box->width > box->precision)
	{
		while (num-- > 0)
		{
			if (box->zero == 1 && !box->period)
				ft_putchar('0', i);
			else if (box->zero && box->period && box->precision < 0)
				ft_putchar('0', i);
			else
				ft_putchar(' ', i);
		}
	}
	while (j--)
		ft_putchar('0', i);
	if (!box->unbr && box->period && !box->precision)
		box->width ? ft_putchar(' ', i) : 0;
	else
		puthexnbr(box->unbr, box, i);
	if (box->minus == 1 && box->width > box->precision)
		while (num-- > 0)
			ft_putchar(' ', i);
}

int		shop1(t_box *box, int j)
{
	unsigned int len;

	len = box->unbr;
	while (len != 0)
	{
		len = len / 16;
		j++;
	}
	if (box->width < 0)
	{
		box->width *= -1;
		box->minus = 1;
	}
	if (box->width < j)
		box->width = 0;
	return (j);
}

void	print_x(t_box *box, va_list arr, int *i)
{
	int j;
	int num;
	int s;

	box->unbr = va_arg(arr, unsigned int);
	j = 0;
	if (box->unbr == 0)
		j = 1;
	j = shop1(box, j);
	s = j;
	num = box->width;
	if (box->precision > j)
		j = box->precision - j;
	else
		j = 0;
	if (box->width > j)
		num = box->width - j - s;
	disp_x(box, j, num, i);
}
