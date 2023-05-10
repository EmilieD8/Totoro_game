/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hu_putnbr_fd.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edrouot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/23 14:37:54 by edrouot           #+#    #+#             */
/*   Updated: 2022/12/23 14:37:57 by edrouot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include "ft_printf.h"

unsigned long long	lengthhexunsignedint(unsigned long long nb)
{
	unsigned long long	div;

	div = 1;
	while (nb >= 16)
	{
		nb = nb / 16;
		div = div * 16;
	}
	return (div);
}

int	ft_hu_putnbr_fd(unsigned long long nb, int fd, int upordown, int length)
{
	unsigned long long	n;
	unsigned long long	div;

	n = nb;
	div = lengthhexunsignedint(nb);
	while (nb > -1)
	{
		n = nb / div;
		if (n < 10)
			n = n + 48;
		else if (n >= 10 && upordown == 0)
			n = n + 55;
		else if (n >= 10 && upordown == 1)
			n = n + 87;
		write (fd, &n, 1);
		length++;
		nb = nb % div;
		div = div / 16;
		if (div == 0)
			break ;
	}
	return (length);
}
