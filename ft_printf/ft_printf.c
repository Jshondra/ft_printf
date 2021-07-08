/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jshondra <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/20 17:39:59 by jshondra          #+#    #+#             */
/*   Updated: 2020/12/06 23:42:49 by jshondra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_printf(const char *form, ...)
{
	va_list			arr;
	int				count;

	count = 0;
	va_start(arr, form);
	while (*form)
	{
		if (*form == '%')
			perc(&form, arr, &count);
		else if (*form != '%')
		{
			ft_putchar(*form, &count);
			form++;
		}
	}
	va_end(arr);
	return (count);
}
