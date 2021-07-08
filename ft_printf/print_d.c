/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_d.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jshondra <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/29 16:10:42 by jshondra          #+#    #+#             */
/*   Updated: 2020/12/08 16:23:40 by jshondra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	disp_bad_d(t_box *box, int num, int *i)
{
	if (box->minus != 1 && box->width > box->precision)
		while (num-- > 0 && box->unbr == 0)
		{
			if (box->zero == 1 && !box->period)
				ft_putchar('0', i);
			else if (box->zero && box->period && box->precision < 0)
				ft_putchar('0', i);
			else
				ft_putchar(' ', i);
		}
	box->chislo < 0 ? ft_putchar('-', i) : 0;
	if (box->zero && box->width > 0 && !box->minus && box->precision < 0
		&& box->period && box->chislo < 0 && box->unbr > 0)
		while (box->unbr != 0)
		{
			box->unbr--;
			ft_putchar('0', i);
		}
}

void	disp_d(t_box *box, int j, int num, int *i)
{
	box->chislo < 0 ? num-- : 0;
	if (box->chislo < 0 && box->zero && box->precision < 0)
		num--;
	disp_bad_d(box, num, i);
	while (j--)
		ft_putchar('0', i);
	if (!box->chislo && box->period && !box->precision)
		box->width ? ft_putchar(' ', i) : 0;
	else
		ft_putnbr(box->chislo, i);
	if (box->minus == 1 && box->width > box->precision)
		while (num-- > 0)
			ft_putchar(' ', i);
}

void	selection(t_box *box, int j, int num, int *i)
{
	if (box->zero && box->chislo < 0 && !box->period &&
			box->width > 0 && box->minus == 0)
	{
		ft_putchar('-', i);
		num--;
		if (box->width > box->precision)
		{
			while (num-- > 0)
				if (box->zero == 1 && !box->period)
					ft_putchar('0', i);
				else
					ft_putchar(' ', i);
		}
		ft_putnbr(box->chislo, i);
	}
	else
		disp_d(box, j, num, i);
}

int		shop(t_box *box, int j)
{
	int len;

	len = box->chislo;
	while (len != 0)
	{
		len = len / 10;
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

void	print_d(t_box *box, va_list arr, int *i)
{
	int j;
	int num;
	int s;

	box->chislo = va_arg(arr, int);
	j = 0;
	if (box->chislo == 0)
		j = 1;
	j = shop(box, j);
	s = j;
	if ((box->width > s + 1) && box->chislo < 0 && box->zero == 1
		&& box->minus == 0 && box->precision < 0 && box->period)
		box->unbr = box->width - s - 1;
	num = box->width;
	if (box->precision > j)
		j = box->precision - j;
	else
		j = 0;
	if (box->width > j)
		num = box->width - j - s;
	selection(box, j, num, i);
}
