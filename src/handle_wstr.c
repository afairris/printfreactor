/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_wstr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afairris <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/10 14:36:18 by afairris          #+#    #+#             */
/*   Updated: 2017/01/10 14:36:21 by afairris         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <libft.h>
#include "ft_printf.h"
#include "handle_functions.h"
#include "utils.h"

static size_t	calculate_wstrlen(wchar_t *str, int precision, size_t i)
{
	if (*str == '\0' || precision == 0)
		return (i);
	else if (*str <= 0x7F)
		return (calculate_wstrlen(str + 1, precision - 1, i + 1));
	else if (*str <= 0x7FF && precision >= 2)
		return (calculate_wstrlen(str + 1, precision - 2, i + 2));
	else if (*str <= 0xFFFF && precision >= 3)
		return (calculate_wstrlen(str + 1, precision - 3, i + 3));
	else if (*str <= 0x10FFFF && precision >= 4)
		return (calculate_wstrlen(str + 1, precision - 4, i + 4));
	else
		return (i);
}

static size_t	wstrlen(wchar_t *str)
{
	size_t i;

	i = 0;
	while (*str)
	{
		if (*str <= 0x7F)
			i++;
		else if (*str <= 0x7FF)
			i += 2;
		else if (*str <= 0xFFFF)
			i += 3;
		else if (*str <= 0x10FFFF)
			i += 4;
		str++;
	}
	return (i);
}

ssize_t			handle_wstr(char **format, va_list *args, t_arg *arg)
{
	wchar_t	*str;
	size_t	strlen;

	(void)format;
	(void)arg;
	str = va_arg(*args, wchar_t*);
	if (str == NULL)
		str = L"(null)";
	strlen = arg->got_precision ? calculate_wstrlen(str, arg->precision, 0) :
			wstrlen(str);
	if (arg->got_width && !arg->right_pad)
		width_pad(strlen, arg->width, arg->pad_zeroes ? '0' : ' ');
	ft_putnwstr(str, strlen);
	if (arg->got_width && arg->right_pad)
		width_pad(strlen, arg->width, ' ');
	return (arg->got_width ? FT_MAX(strlen, arg->width) : strlen);
}
