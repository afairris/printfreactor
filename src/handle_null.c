/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_null.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afairris <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/10 14:36:02 by afairris          #+#    #+#             */
/*   Updated: 2017/01/10 14:36:03 by afairris         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "handle_functions.h"
#include "ft_printf.h"
#include <libft.h>
#include "utils.h"

ssize_t	handle_null(char **format, va_list *args, t_arg *arg)
{
	(void)args;
	if (arg->got_width && !arg->right_pad)
		width_pad(1, arg->width, arg->pad_zeroes ? '0' : ' ');
	ft_putchar(**format);
	if (arg->got_width && arg->right_pad)
		width_pad(1, arg->width, ' ');
	return (arg->got_width ? ft_max(arg->width, 1) : 1);
}
