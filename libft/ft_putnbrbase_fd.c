/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbrbase_fd.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afairris <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/10 12:42:47 by afairris          #+#    #+#             */
/*   Updated: 2017/01/10 12:42:48 by afairris         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "libft.h"

static void	ft_putnbrbase_fd_inner(uintmax_t nbr, char *base, size_t baselen,
				int fd)
{
	if (nbr >= baselen)
	{
		ft_putnbrbase_fd_inner(nbr / baselen, base, baselen, fd);
		ft_putnbrbase_fd_inner(nbr % baselen, base, baselen, fd);
	}
	else
		ft_putchar_fd(base[nbr], fd);
}

void		ft_putnbrbase_fd(uintmax_t nbr, char *base, int fd)
{
	ft_putnbrbase_fd_inner(nbr, base, ft_strlen(base), fd);
}
