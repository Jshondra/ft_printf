/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jshondra <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/28 21:24:44 by jshondra          #+#    #+#             */
/*   Updated: 2020/12/08 17:26:21 by jshondra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	init(t_box *box)
{
	box->zero = 0;
	box->minus = 0;
	box->period = 0;
	box->width = 0;
	box->precision = 0;
	box->form_convers = 0;
	box->unbr = 0;
}
