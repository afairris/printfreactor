/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afairris <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/10 14:06:20 by afairris          #+#    #+#             */
/*   Updated: 2017/01/10 14:06:20 by afairris         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include "libft.h"
#include "ft_printf.h"
#include "handle_functions.h"
#include "parse_handlers.h"

static ssize_t	handle_arguments(char **format, va_list *args, t_arg *sarg)
{
	ssize_t		ret;
	t_handler	handler;

	if ((*(++*format)) == '\0')
		return (0);
	if ((parse_flags(format, sarg)) == NULL)
		return (-1);
	if ((parse_width(format, args, sarg)) == NULL)
		return (-1);
	if ((parse_precision(format, args, sarg)) == NULL)
		return (-1);
	if ((parse_length(format, sarg)) == NULL)
		return (-1);
	if (**format == '\0')
		return (0);
	if (get_handler(**format) == NULL)
		handler = handle_null;
	else
		handler = get_handler(**format);
	ret = handler(format, args, sarg);
	(*format)++;
	return (ret);
}

static int		inner_loop(const char *format, va_list *args, size_t chrs)
{
	char	*next_arg;
	t_arg	sarg;
	ssize_t	han_len;

	next_arg = ft_strchr(format, '%');
	if (*format == '\0')
		return (chrs);
	if (next_arg == NULL)
	{
		ft_putstr(format);
		return (chrs + ft_strlen(format));
	}
	else if (next_arg > format)
	{
		ft_putnstr(format, next_arg - format);
		return (inner_loop(next_arg, args, chrs + (next_arg - format)));
	}
	else
	{
		ft_bzero(&sarg, sizeof(sarg));
		if ((han_len = handle_arguments((char**)&format, args, &sarg)) == -1)
			return (-1);
		else
			return (inner_loop(format, args, chrs + han_len));
	}
}

int				ft_printf(const char *format, ...)
{
	va_list	args;
	int		ret;

	va_start(args, format);
	ret = inner_loop(format, &args, 0);
	va_end(args);
	return (ret);
}
