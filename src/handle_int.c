/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_int.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afairris <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/10 14:35:54 by afairris          #+#    #+#             */
/*   Updated: 2017/01/10 14:35:55 by afairris         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <libft.h>
#include "ft_printf.h"
#include "handle_functions.h"
#include "utils.h"
#include <stdint.h>

static intmax_t	get_signed_from_len(va_list *args, t_arg *arg)
{
	intmax_t	num;

	num = va_arg(*args, intmax_t);
	if (arg->length == hh)
		num = (char)num;
	else if (arg->length == h)
		num = (short int)num;
	else if (arg->length == l)
		num = (long int)num;
	else if (arg->length == ll)
		num = (long long int)num;
	else if (arg->length == j)
		num = (intmax_t)num;
	else if (arg->length == z)
		num = (size_t)num;
	else
		num = (int)num;
	return (num);
}

ssize_t			handle_int(char **format, va_list *args, t_arg *arg)
{
	intmax_t				nbr;
	char					*prefix;

	(void)format;
	if (arg->got_precision)
		arg->pad_zeroes = 0;
	nbr = get_signed_from_len(args, arg);
	if (nbr < 0 || arg->force_sign || arg->blank_sign)
	{
		if (nbr < 0)
		{
			nbr = -nbr;
			prefix = "-";
		}
		else if (arg->force_sign)
			prefix = "+";
		else if (arg->blank_sign)
			prefix = " ";
		else
			prefix = "";
		return (nbrforceprefix(nbr, "0123456789", arg, prefix));
	}
	else
		return (handle_uint(nbr, arg, "0123456789", NULL));
}
