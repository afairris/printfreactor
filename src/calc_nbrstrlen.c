/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calc_nbrstrlen.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afairris <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/10 14:33:16 by afairris          #+#    #+#             */
/*   Updated: 2017/01/10 14:33:18 by afairris         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <inttypes.h>
#include <libft.h>
#include "handle_functions.h"
#include "utils.h"

unsigned int	calc_nbrstrlen(uintmax_t nbr, char *base,
		char *p, t_arg *arg)
{
	unsigned int	nbr_len;
	unsigned int	nbrstrlen;

	nbr_len = printf_nbrlen(nbr, base);
	if (nbr == 0 && arg->got_precision && arg->precision == 0)
		nbrstrlen = 0;
	else if (arg->got_precision)
		nbrstrlen = ft_max(nbr_len, arg->precision);
	else
		nbrstrlen = nbr_len;
	if (arg->force_prefix && p != NULL && nbr != 0)
		nbrstrlen += ft_strlen(p);
	return (nbrstrlen);
}
