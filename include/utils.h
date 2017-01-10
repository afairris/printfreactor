/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afairris <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/10 14:02:42 by afairris          #+#    #+#             */
/*   Updated: 2017/01/10 14:02:47 by afairris         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H
# include <inttypes.h>
# include "handle_functions.h"

uintmax_t		get_unsigned_from_length(va_list *args, t_arg *arg);
void			width_pad(int nbrstrlen, int width, char padwith);
unsigned int	printf_nbrlen(uintmax_t nbr, char *base);
unsigned int	calc_nbrstrlen(uintmax_t nbr, char *base, char *p,
		t_arg *arg);
ssize_t			nbrforceprefix(uintmax_t n, char *b, t_arg *a,
		char *p);
#endif
