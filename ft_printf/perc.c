/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   perc.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jshondra <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/25 12:07:06 by jshondra          #+#    #+#             */
/*   Updated: 2020/12/08 16:04:12 by jshondra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		helpparse(t_box *box, const char **form_p, va_list arr)
{
	while (set_flag(box, **form_p) && check_flag(box, **form_p))
		*form_p += 1;
	while (**form_p == '0' || **form_p == '-')
		*form_p += 1;
	if (ft_isdigit(**form_p))
		box->width = ft_atoi(*form_p);
	else if ((**form_p == '*'))
	{
		((box->width) = va_arg(arr, int));
		*form_p += 1;
	}
	while (ft_isdigit(**form_p))
		*form_p += 1;
}

void		perc(char const **form, va_list arr, int *i)
{
	const char	*form_p;
	t_box		*box;

	box = malloc(sizeof(t_box));
	init(box);
	form_p = ++(*form);
	init(box);
	helpparse(box, &form_p, arr);
	if ((*form_p == '.' && ((box->period) = 1)) || *form_p == '-')
	{
		form_p++;
		if (ft_isdigit(*form_p))
			box->precision = ft_atoi(form_p);
		else if ((*form_p == '*') && form_p++)
			box->precision = va_arg(arr, int);
		while (ft_isdigit(*form_p))
			form_p++;
	}
	form_convers(*form_p) ? box->form_convers = *form_p++ : 0;
	print_form_convers(box, arr, i);
	*form = form_p;
	free(box);
}
