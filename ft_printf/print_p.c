/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_p.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jshondra <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/05 17:20:03 by jshondra          #+#    #+#             */
/*   Updated: 2020/12/08 12:57:05 by jshondra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	disp_p(t_box *box, int j, int num, int *i)
{
	int flag;

	flag = 0;
	if (j > 0)
	{
		ft_putstr("0x", i, 2);
		flag = 1;
	}
	if (box->minus != 1 && box->width > box->precision)
		while (num-- > 0)
			ft_putchar(' ', i);
	while (j--)
		ft_putchar('0', i);
	if (!box->pnbr && box->period && !box->precision)
		box->width ? ft_putchar(' ', i) : 0;
	if (flag == 0)
		ft_putstr("0x", i, 2);
	if (!(box->period && !box->precision))
		puthexnbr(box->pnbr, box, i);
	if (box->minus == 1 && box->width > box->precision)
		while (num-- > 0)
			ft_putchar(' ', i);
}

int		shop2(t_box *box, int j)
{
	unsigned long len;

	len = box->pnbr;
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

void	print_p(t_box *box, va_list arr, int *i)
{
	int j;
	int num;
	int s;

	box->pnbr = va_arg(arr, unsigned long);
	j = 0;
	if (!box->pnbr && box->width == 2 && box->period)
	{
		ft_putstr("0x", i, 2);
		return ;
	}
	if (box->pnbr == 0)
		j = 1;
	j = shop2(box, j);
	s = j;
	box->pnbr == 0 ? s = 1 : 0;
	num = box->width;
	if (box->precision > j)
		j = box->precision - j;
	else
		j = 0;
	if (box->width > j)
		num = box->width - j - s - 2;
	disp_p(box, j, num, i);
}
