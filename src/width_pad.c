/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   width_pad.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afairris <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/10 14:33:28 by afairris          #+#    #+#             */
/*   Updated: 2017/01/10 14:33:30 by afairris         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

void	width_pad(int nbrstrlen, int width, char padwith)
{
	while (nbrstrlen < width)
	{
		ft_putchar(padwith);
		nbrstrlen++;
	}
}
