/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_float.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afairris <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/10 14:35:49 by afairris          #+#    #+#             */
/*   Updated: 2017/01/10 14:35:50 by afairris         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "handle_functions.h"
#include <libft.h>
#include "utils.h"
#include <stdarg.h>

ssize_t	handle_float(char **format, va_list *args, t_arg *arg)
{
	float	nbr;

	(void)format;
	(void)arg;
	nbr = (float)va_arg(*args, double);
	(void)nbr;
	ft_putstr("Float");
	return (0);
}
