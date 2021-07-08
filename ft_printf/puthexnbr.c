/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   puthexnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jshondra <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/05 14:43:51 by jshondra          #+#    #+#             */
/*   Updated: 2020/12/08 12:56:25 by jshondra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	puthexnbr(unsigned long num, t_box *box, int *i)
{
	if (num > 15)
	{
		puthexnbr(num / 16, box, i);
		if (num % 16 > 9)
		{
			if (box->form_convers == 'X')
				ft_putchar((num % 16) + 55, i);
			else
				ft_putchar((num % 16) + 87, i);
		}
		else
			ft_putchar(num % 16 + '0', i);
	}
	else
	{
		if (num % 16 > 9)
		{
			if (box->form_convers == 'X')
				ft_putchar((num % 16) + 55, i);
			else
				ft_putchar((num % 16) + 87, i);
		}
		else
			ft_putchar(num + '0', i);
	}
}
