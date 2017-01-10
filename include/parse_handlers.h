/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_handlers.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afairris <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/10 14:02:40 by afairris          #+#    #+#             */
/*   Updated: 2017/01/10 14:02:41 by afairris         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSE_HANDLERS_H
# define PARSE_HANDLERS_H
# include "handle_functions.h"

char	*parse_flags(char **format, t_arg *arg);
char	*parse_width(char **format, va_list *list, t_arg *arg);
char	*parse_precision(char **format, va_list *list, t_arg *arg);
char	*parse_length(char **format, t_arg *arg);
#endif
