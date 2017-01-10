/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afairris <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/10 14:06:23 by afairris          #+#    #+#             */
/*   Updated: 2017/01/10 14:06:26 by afairris         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <inttypes.h>
#include <libft.h>
#include <locale.h>
#include <wchar.h>
#include "ft_printf.h"

int	main(void)
{
	char	*test;
	char	c;

	test = "{%c}";
	c = '\0';
	printf("PRINTF :\n");
	printf("%d\n", printf(test, c));
	printf("FT_PRINTF\n");
	printf("%d\n", ft_printf(test, c));
	return (0);
}
