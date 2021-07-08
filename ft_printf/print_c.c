/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_c.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jshondra <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/27 18:01:58 by jshondra          #+#    #+#             */
/*   Updated: 2020/12/07 17:16:43 by jshondra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		print_c(t_box *box, va_list arr, int *i)
{
	int		x;
	char	c;

	x = box->width;
	c = (char)va_arg(arr, void*);
	if (x < 0)
	{
		x *= -1;
		box->minus = 1;
	}
	if (box->minus != 1 && x > 1)
		while (--x)
			ft_putchar(' ', i);
	ft_putchar(c, i);
	if (box->minus == 1 && x > 1)
		while (--x > 0)
			ft_putchar(' ', i);
}
