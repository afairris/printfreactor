/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_hex.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afairris <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/10 14:35:52 by afairris          #+#    #+#             */
/*   Updated: 2017/01/10 14:35:53 by afairris         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include "ft_printf.h"
#include "handle_functions.h"
#include "utils.h"

ssize_t	handle_hex(char **format, va_list *args, t_arg *arg)
{
	uintmax_t	nbr;

	nbr = get_unsigned_from_length(args, arg);
	if (**format == 'X')
		return (handle_uint(nbr, arg, "0123456789ABCDEF", "0X"));
	else
		return (handle_uint(nbr, arg, "0123456789abcdef", "0x"));
}
