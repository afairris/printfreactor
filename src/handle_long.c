/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_long.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afairris <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/10 14:35:57 by afairris          #+#    #+#             */
/*   Updated: 2017/01/10 14:35:58 by afairris         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "handle_functions.h"
#include "ft_printf.h"
#include <libft.h>

ssize_t	handle_long(char **format, va_list *args, t_arg *arg)
{
	arg->length = l;
	return (get_handler(ft_tolower(**format))(format, args, arg));
}
