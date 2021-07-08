/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jshondra <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/06 20:10:10 by jshondra          #+#    #+#             */
/*   Updated: 2020/12/08 12:57:46 by jshondra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	put(long int *n, long int *b)
{
	if ((*n < 0))
	{
		*n *= -1;
		*b *= -1;
	}
}

void	ft_putnbr(long int n, int *point)
{
	long int		l;
	long int		v;
	char			c;

	l = 1;
	v = n;
	put(&v, &n);
	while ((v = v / 10) > 0)
		l *= 10;
	while (l > 0)
	{
		v = n / l;
		c = v + 48;
		ft_putchar(c, point);
		if (v % l == 0)
			v = v / l;
		else
			n = n % l;
		l /= 10;
	}
}
