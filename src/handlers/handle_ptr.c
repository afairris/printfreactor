/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_ptr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afairris <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/10 14:36:07 by afairris          #+#    #+#             */
/*   Updated: 2017/01/10 14:36:07 by afairris         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <libft.h>
#include "ft_printf.h"
#include "handle_funcs.h"
#include "utils.h"
#include <stdint.h>

ssize_t	ft_printf_handle_ptr(char **format, va_list *args, t_arg *arg)
{
	char		*base;
	uintmax_t	nbr;

	(void)format;
	arg->length = z;
	if (arg->got_precision)
		arg->pad_zeroes = 0;
	base = "0123456789abcdef";
	nbr = ft_printf_get_unsigned_from_length(args, arg);
	return (ft_printf_nbrforceprefix(nbr, base, arg, "0x"));
}
