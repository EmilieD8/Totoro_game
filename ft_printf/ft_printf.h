/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edrouot <edrouot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/23 15:54:07 by edrouot           #+#    #+#             */
/*   Updated: 2022/12/25 14:21:26 by edrouot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>

# ifndef OPEN_MAX
#  define OPEN_MAX 32
# endif

size_t	ft_strlen(const char *s);
char	*ft_substr(char const *s, unsigned int start, size_t len);
int		lengthint(int nb);
int		ft_putnbrreturn_fd(int nb, int fd, int length);
int		ft_putchar_fd(char c, int fd);
int		ft_putstrreturn_fd(char *s, int fd, int length);
int		ft_u_putnbr_fd(unsigned int nb, int fd, int length);
int		ft_hu_putnbr_fd(
			unsigned long long nb, int fd, int upordown, int length);
int		ft_putcharper_fd(int c, int fd, int length);
int		ft_printf(const char *s, ...);
char	*ft_itoa(int n);
size_t	ft_strlcpy(char *dst, const char *src, size_t size);
int		ft_pointer_fd(unsigned long long ptr, int fd, int length);

#endif
