# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: afairris <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/01/10 13:59:23 by afairris          #+#    #+#              #
#    Updated: 2017/01/10 13:59:24 by afairris         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

C_INCLUDE_PATH = include/

CFLAGS += -Wall -Wextra -Werror

CFLAGS += $(foreach d, $(C_INCLUDE_PATH), -I$d)

SRCS = src/ft_printf.c \
	   src/parse_handlers.c \
	   src/get_unsigned_from_length.c \
	   src/width_pad.c \
	   src/nbrlen.c \
	   src/calc_nbrstrlen.c \
	   src/nbrforceprefix.c \
	   src/get_handler_arr.c \
	   src/generic_handle_unsigned.c \
	   src/handle_null.c \
	   src/handle_char.c \
	   src/handle_escape.c \
	   src/handle_hex.c \
	   src/handle_int.c \
	   src/handle_long.c \
	   src/handle_octal.c \
	   src/handle_ptr.c \
	   src/handle_str.c \
	   src/handle_unsigned.c \
	   src/handle_wchar.c \
	   src/handle_binary.c \
	   src/handle_charswritten.c \
	   src/handle_float.c \
	   src/handle_wstr.c

LIBFT_FUNS =	putchar_fd \
				putchar_fd \
				putstr_fd \
				putnbrbase_fd \
				putnstr_fd \
				putwchar_fd \
				memset \
				strchr \
				putstr \
				strlen \
				putnstr \
				bzero \
				isdigit \
				memalloc \
				putchar \
				max \
				tolower \
				nstrlen \
				putwchar \
				putnwstr \
				putnbrbase \

CFLAGS += $(foreach fun,$(LIBFT_FUNS),-Dft_$(fun)=ft_printf_libft_$(fun))

OBJS = $(patsubst src/%.c,obj/%.o,$(SRCS))
OBJS += $(foreach fun,$(LIBFT_FUNS),obj/libft/ft_$(fun).o)

CP = cp

RM = rm -f

all: $(NAME)

$(OBJS): | obj

obj:
	@mkdir -p $@
	@mkdir -p $@/handlers
	@mkdir -p $@/utils
	@mkdir -p $@/libft

obj/%.o: src/%.c
	$(CC) -c $(CFLAGS) $(CPPFLAGS) $< -o $@

obj/libft/%.o: libft/%.c
	$(CC) -c $(CFLAGS) $(CPPFLAGS) $< -o $@

$(NAME): $(OBJS)
	$(AR) -rcs $(NAME) $^

clean:
	$(RM) $(OBJS)

libfttest: $(NAME) obj/main.o
	$(CC) -o $@ obj/main.o -L. -lftprintf

fclean: clean
	$(RM) $(NAME)
	$(RM) -rf obj

re: fclean all

.PHONY: all clean fclean re