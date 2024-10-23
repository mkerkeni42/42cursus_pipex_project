# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mkerkeni <mkerkeni@student.42nice.fr>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/20 11:42:45 by mkerkeni          #+#    #+#              #
#    Updated: 2024/10/12 21:39:12 by mkerkeni         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME 	= libft.a
CC 		= gcc
CFLAGS 	= -Wall -Wextra -Werror

SRCS 	= 	char_utils/ft_isalpha.c \
			char_utils/ft_isdigit.c \
			char_utils/ft_isalnum.c \
			char_utils/ft_isascii.c \
			char_utils/ft_isprint.c \
			char_utils/ft_toupper.c \
			char_utils/ft_tolower.c \
			char_utils/ft_putchar_fd.c \
			string_utils/ft_strlcat.c \
			string_utils/ft_strlcpy.c \
			string_utils/ft_strlen.c \
			string_utils/ft_strchr.c \
			string_utils/ft_strrchr.c \
			string_utils/ft_strncmp.c \
			string_utils/ft_strdup.c \
			string_utils/ft_strnstr.c \
			string_utils/ft_substr.c \
			string_utils/ft_putstr_fd.c \
			string_utils/ft_putendl_fd.c \
			string_utils/ft_strjoin.c \
			string_utils/ft_strmapi.c \
			string_utils/ft_striteri.c \
			string_utils/ft_split.c \
			string_utils/ft_strtrim.c \
			memory_utils/ft_bzero.c \
			memory_utils/ft_memset.c \
			memory_utils/ft_memmove.c \
			memory_utils/ft_memcpy.c \
			memory_utils/ft_memchr.c \
			memory_utils/ft_memcmp.c \
			memory_utils/ft_calloc.c \
			number_utils/ft_putnbr_fd.c \
			number_utils/ft_atoi.c \
			number_utils/ft_itoa.c \
			ft_printf/ft_printf.c \
			ft_printf/ft_putnbr_unsigned_int.c \
			ft_printf/print_str.c \
			ft_printf/print_nbr.c \
			ft_printf/ft_putnbr_hexa.c \
			ft_printf/print_hexa_low.c \
			ft_printf/print_hexa_up.c \
			get_next_line/get_next_line.c \
			get_next_line/get_next_line_utils.c
			

OBJS = $(SRCS:.c=.o)

SRCS_BONUS = list_utils/ft_lstnew.c \
			list_utils/ft_lstadd_front.c \
			list_utils/ft_lstsize.c \
			list_utils/ft_lstlast.c \
			list_utils/ft_lstadd_back.c \
			list_utils/ft_lstdelone.c \
			list_utils/ft_lstclear.c \
			list_utils/ft_lstiter.c \
			list_utils/ft_lstmap.c \

OBJS_BONUS = $(SRCS_BONUS:.c=.o)

all: $(NAME)
	
$(NAME): $(OBJS)
	ar -rcs $@ $^

bonus: $(OBJS_BONUS) $(OBJS)
	ar -rcs $(NAME) $^
	
clean:
	rm -f $(OBJS) $(OBJS_BONUS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re bonus
