/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_unsigned.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afairris <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/10 14:36:12 by afairris          #+#    #+#             */
/*   Updated: 2017/01/10 14:36:13 by afairris         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include "ft_printf.h"
#include "handle_funcs.h"
#include <stddef.h>
#include "utils.h"

ssize_t	ft_printf_handle_unsigned(char **format, va_list *args, t_arg *arg)
{
	uintmax_t	nbr;

	(void)format;
	nbr = ft_printf_get_unsigned_from_length(args, arg);
	return (ft_printf_handle_uint(nbr, arg, "0123456789", NULL));
}
