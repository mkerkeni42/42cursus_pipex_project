# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mkerkeni <mkerkeni@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/04/03 12:55:09 by mkerkeni          #+#    #+#              #
#    Updated: 2023/05/02 15:27:23 by mkerkeni         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = pipex
LIBFT = Libft/
CC = gcc
CFLAGS = -Wall -Wextra -Werror
#CFLAGS += -fsanitize=address -g3

SRCS = 	main.c pipex.c \

#SRCS_BONUS = 	

OBJS = $(SRCS:.c=.o)

%.o:%.c
	@$(CC) $(CFLAGS) -c $< -o $(<:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	@echo "	Compilation in progress..."
	@$(MAKE) -C $(LIBFT)
	@$(CC) $(CFLAGS) -o $(NAME) $^ $(LIBFT)libft.a
	@echo "	Compiled !"

clean:
	@rm -f $(OBJS)
	@$(MAKE) clean -C $(LIBFT)

fclean: clean
	@rm -f $(NAME)
	@rm -f Libft/libft.a

re: fclean all

.PHONY: all clean fclean re bonus
