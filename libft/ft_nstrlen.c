/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_nstrlen.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afairris <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/10 12:39:32 by afairris          #+#    #+#             */
/*   Updated: 2017/01/10 12:39:33 by afairris         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t		ft_nstrlen(const char *str, size_t maxlen)
{
	size_t	i;

	i = 0;
	while (*str++ && i < maxlen)
		i++;
	return (i);
}
