/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_functions.h                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afairris <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/10 14:02:35 by afairris          #+#    #+#             */
/*   Updated: 2017/01/10 14:02:37 by afairris         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HANDLE_FUNCTIONS_H
# define HANDLE_FUNCTIONS_H
# include <stdarg.h>
# include "ft_printf.h"
# include <stdint.h>
# include <sys/types.h>

typedef struct		s_arg
{
	int				force_prefix : 1;
	int				pad_zeroes : 1;
	int				right_pad : 1;
	int				force_sign : 1;
	int				blank_sign : 1;
	int				got_width : 1;
	int				got_precision : 1;
	unsigned int	width;
	unsigned int	precision;
	enum {
		none,
		hh,
		h,
		l,
		ll,
		j,
		z
	}				length;
}					t_arg;

ssize_t				handle_escape(char **format, va_list *args,
		t_arg *arg);
ssize_t				handle_str(char **format, va_list *args,
		t_arg *arg);
ssize_t				handle_wstr(char **format, va_list *args,
		t_arg *arg);
ssize_t				handle_ptr(char **format, va_list *args,
		t_arg *arg);
ssize_t				handle_int(char **format, va_list *args,
		t_arg *arg);
ssize_t				handle_long(char **format, va_list *args,
		t_arg *arg);
ssize_t				handle_octal(char **format, va_list *args,
		t_arg *arg);
ssize_t				handle_unsigned(char **format, va_list *args,
		t_arg *arg);
ssize_t				handle_hex(char **format, va_list *args,
		t_arg *arg);
ssize_t				handle_char(char **format, va_list *args,
		t_arg *arg);
ssize_t				handle_wchar(char **format, va_list *args,
		t_arg *arg);
ssize_t				handle_null(char **format, va_list *args,
		t_arg *arg);
ssize_t				handle_binary(char **format, va_list *args,
		t_arg *arg);
ssize_t				handle_float(char **format, va_list *args,
		t_arg *arg);
ssize_t				handle_charswritten(char **format, va_list *a,
		t_arg *arg);
ssize_t				handle_uint(uintmax_t nbr, t_arg *arg, char *b,
		char *p);
typedef ssize_t		(*t_handler)(char**, va_list*, t_arg*);
t_handler			get_handler(char c);

#endif
