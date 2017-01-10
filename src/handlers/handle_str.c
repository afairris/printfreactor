/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_str.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afairris <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/10 14:36:09 by afairris          #+#    #+#             */
/*   Updated: 2017/01/10 14:36:10 by afairris         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "handle_functions.h"
#include "utils.h"
#include <libft.h>
#include <wchar.h>

ssize_t	handle_str(char **format, va_list *args, t_arg *arg)
{
	char	*str;
	size_t	strlen;

	if (arg->length == l)
		return (handle_wstr(format, args, arg));
	else
	{
		str = va_arg(*args, char*);
		if (str == NULL)
			str = "(null)";
		strlen = arg->got_precision ? ft_nstrlen(str, arg->precision) :
				ft_strlen(str);
		if (arg->got_width && !arg->right_pad)
			width_pad(strlen, arg->width, arg->pad_zeroes ?
					'0' : ' ');
		ft_putnstr(str, strlen);
		if (arg->got_width && arg->right_pad)
			width_pad(strlen, arg->width, ' ');
		return (arg->got_width ? FT_MAX(strlen, arg->width) : strlen);
	}
}
