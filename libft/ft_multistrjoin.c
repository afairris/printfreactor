/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_multistrjoin.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afairris <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/10 13:52:49 by afairris          #+#    #+#             */
/*   Updated: 2017/01/10 13:52:50 by afairris         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>
#include <stdarg.h>
#include <sys/types.h>

char	*ft_multistrjoin(int count, ...)
{
	va_list		args;
	va_list		args_copy;
	size_t		newstrlen;
	int			i;
	char		*ret;

	va_start(args, count);
	va_copy(args_copy, args);
	i = 0;
	newstrlen = 0;
	while (i++ < count)
		newstrlen += ft_strlen(va_arg(args, char*));
	va_end(args);
	ret = (char*)malloc(sizeof(char) * (newstrlen + 1));
	*ret = '\0';
	i = 0;
	while (i++ < count)
		ft_strcat(ret, va_arg(args_copy, char*));
	va_end(args_copy);
	return (ret);
}
