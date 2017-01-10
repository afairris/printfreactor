/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_char.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afairris <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/10 14:35:42 by afairris          #+#    #+#             */
/*   Updated: 2017/01/10 14:35:43 by afairris         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <libft.h>
#include "ft_printf.h"
#include "handle_functions.h"
#include "utils.h"

ssize_t	handle_char(char **format, va_list *args, t_arg *arg)
{
	(void)format;
	if (arg->length == l)
		return (handle_wchar(format, args, arg));
	else
	{
		if (arg->got_width && !arg->right_pad)
			width_pad(1, arg->width, arg->pad_zeroes ? '0' : ' ');
		ft_putchar(va_arg(*args, int));
		if (arg->got_width && arg->right_pad)
			width_pad(1, arg->width, ' ');
		return (arg->got_width ? ft_max(arg->width, 1) : 1);
	}
}
