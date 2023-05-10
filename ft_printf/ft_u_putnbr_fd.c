/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_u_putnbr_fd.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edrouot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/23 15:46:11 by edrouot           #+#    #+#             */
/*   Updated: 2022/12/23 15:46:13 by edrouot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include "ft_printf.h"

unsigned int	lengthunsignedint(unsigned int nb)
{
	unsigned int	div;

	div = 1;
	while (nb >= 10)
	{
		nb = nb / 10;
		div = div * 10;
	}
	return (div);
}

int	ft_u_putnbr_fd(unsigned int nb, int fd, int length)
{
	unsigned int	n;
	unsigned int	div;

	n = nb;
	div = lengthunsignedint(nb);
	while (nb >= 0)
	{
		n = nb / div + 48;
		write (fd, &n, 1);
		length++;
		nb = nb % div;
		div = div / 10;
		if (div == 0)
			break ;
	}
	return (length);
}

