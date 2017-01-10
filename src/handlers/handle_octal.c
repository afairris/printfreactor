/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_octal.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afairris <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/10 14:36:04 by afairris          #+#    #+#             */
/*   Updated: 2017/01/10 14:36:05 by afairris         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include "ft_printf.h"
#include "handle_functions.h"
#include "utils.h"
#include <stdlib.h>
#include <libft.h>

ssize_t	handle_octal(char **format, va_list *args, t_arg *arg)
{
	uintmax_t	nbr;

	(void)format;
	nbr = get_unsigned_from_length(args, arg);
	if (arg->force_prefix && nbr == 0 &&
				arg->got_precision && arg->precision == 0)
	{
		if (arg->got_width && !arg->right_pad)
			width_pad(1, arg->width, arg->pad_zeroes ? '0' : ' ');
		ft_putstr("0");
		if (arg->got_width && arg->right_pad)
			width_pad(1, arg->width, ' ');
		return (arg->got_width ? ft_max(arg->width, 1) : 1);
	}
	else if (arg->force_prefix && nbr != 0)
	{
		arg->got_precision = 1;
		arg->precision = ft_max(arg->precision,
				printf_nbrlen(nbr, "01234567") + 1);
	}
	return (handle_uint(nbr, arg, "01234567", NULL));
}
