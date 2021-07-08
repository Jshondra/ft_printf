/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_form_convers.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jshondra <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/25 14:25:34 by jshondra          #+#    #+#             */
/*   Updated: 2020/12/06 23:48:11 by jshondra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	print_form_convers(t_box *box, va_list arr, int *i)
{
	if (box->form_convers == 's')
		print_s(box, arr, i);
	else if (box->form_convers == 'c')
		print_c(box, arr, i);
	else if (box->form_convers == 'p')
		print_p(box, arr, i);
	else if (box->form_convers == 'd' ||
			box->form_convers == 'i')
		print_d(box, arr, i);
	else if (box->form_convers == 'u')
		print_u(box, arr, i);
	else if (box->form_convers == 'x' || box->form_convers == 'X')
		print_x(box, arr, i);
	else if (box->form_convers == '%')
		print_perc(box, i);
}
