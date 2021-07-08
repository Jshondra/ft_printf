/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_per.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jshondra <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/05 19:54:37 by jshondra          #+#    #+#             */
/*   Updated: 2020/12/06 21:16:25 by jshondra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		print_perc(t_box *box, int *i)
{
	int		x;
	char	c;
	int		j;

	x = box->width;
	j = x;
	c = '%';
	if (x < 0)
	{
		x *= -1;
		box->minus = 1;
	}
	if (box->minus != 1 && x > 1)
		while (--x)
			(box->zero) ? ft_putchar('0', i) : ft_putchar(' ', i);
	ft_putchar(c, i);
	if (box->minus == 1 && x > 1)
		while (--x > 0)
			ft_putchar(' ', i);
	while (j--)
		i++;
}
