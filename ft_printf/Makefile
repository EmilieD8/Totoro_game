# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: edrouot <edrouot@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/11 13:11:53 by edrouot           #+#    #+#              #
#    Updated: 2023/01/17 18:24:35 by edrouot          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= libftprintf.a

LIBFT = libft/libft.a

SRCS	= ft_printf.c ft_putcharper_fd.c ft_hu_putnbr_fd.c ft_u_putnbr_fd.c  ft_pointer_fd.c  ft_putstrreturn_fd.c ft_putnbrreturn_fd.c ft_pointer_fd.c

OBJS	= $(SRCS:.c=.o)

CC 	= cc

CFLAGS	= -Wall -Wextra -Werror

all:	$(NAME)

${NAME}: $(OBJS)
	@make -C ./libft
	@cp libft/libft.a $(NAME)
	@ar rsc $(NAME) $(OBJS)

%.o: %.c
	$(CC) $(CFLAGS) -c $^

clean: 
	@rm -f $(OBJS)
	@make clean -C ./libft

fclean: clean
	@rm -f $(NAME)
	@rm -f $(LIBFT)

re:	fclean all

.PHONY:	all clean fclean re
