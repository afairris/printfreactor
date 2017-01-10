/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsuffix.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afairris <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/10 13:56:15 by afairris          #+#    #+#             */
/*   Updated: 2017/01/10 13:56:16 by afairris         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_strsuffix(const char *str, const char *suffix)
{
	const char	*str_iter;
	const char	*suffix_iter;

	str_iter = str;
	suffix_iter = suffix;
	while (*str_iter != '\0')
		str_iter++;
	while (*suffix_iter != '\0')
		suffix_iter++;
	while (suffix_iter >= suffix && str_iter >= str &&
			*str_iter == *suffix_iter)
	{
		str_iter--;
		suffix_iter--;
	}
	return (suffix_iter < suffix);
}
