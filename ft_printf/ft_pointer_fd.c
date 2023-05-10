/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pointer_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edrouot <edrouot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/23 18:12:37 by edrouot           #+#    #+#             */
/*   Updated: 2022/12/25 14:22:47 by edrouot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include "ft_printf.h"

int	ft_pointer_fd(unsigned long long ptr, int fd, int length)
{
	if (ptr == 0)
		length = ft_putstrreturn_fd("(nil)", fd, length);
	else
	{
		write(1, "0x", 2);
		length = ft_hu_putnbr_fd(ptr, fd, 1, length) + 2;
	}
	return (length);
}
