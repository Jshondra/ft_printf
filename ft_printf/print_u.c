/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_u.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jshondra <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/01 13:21:21 by jshondra          #+#    #+#             */
/*   Updated: 2020/12/06 21:16:43 by jshondra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	disp_u(t_box *box, int j, int num, int *i)
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
		putunbr(box->unbr, i);
	if (box->minus == 1 && box->width > box->precision)
		while (num-- > 0)
			ft_putchar(' ', i);
}

int		ship(t_box *box, int j)
{
	unsigned int len;

	len = box->unbr;
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

void	print_u(t_box *box, va_list arr, int *i)
{
	int j;
	int num;
	int s;

	box->unbr = va_arg(arr, unsigned int);
	j = 0;
	if (box->unbr == 0)
		j = 1;
	j = ship(box, j);
	s = j;
	num = box->width;
	if (box->precision > j)
		j = box->precision - j;
	else
		j = 0;
	if (box->width > j)
		num = box->width - j - s;
	disp_u(box, j, num, i);
}
