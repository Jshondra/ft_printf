/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   putunbr.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jshondra <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/01 13:50:05 by jshondra          #+#    #+#             */
/*   Updated: 2020/12/06 23:45:43 by jshondra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	putunbr(unsigned int n, int *point)
{
	unsigned int	l;
	unsigned int	v;
	char			c;

	l = 1;
	v = n;
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
