/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbrreturn_fd.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edrouot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/23 14:40:18 by edrouot           #+#    #+#             */
/*   Updated: 2022/12/23 14:40:19 by edrouot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include "ft_printf.h"

int	lengthint(int nb)
{
	int	div;

	div = 1;
	while (nb >= 10)
	{
		nb = nb / 10;
		div = div * 10;
	}
	return (div);
}

int	ft_edgecase(int nb, int fd, int length)
{
	if (nb == -2147483648)
	{
		write (fd, "-2147483648", 11);
		length += 11;
	}
	return (length);
}

int	ft_putnbrreturn_fd(int nb, int fd, int length)
{
	int	n;
	int	div;

	n = nb;
	if (nb == -2147483648)
		length = ft_edgecase(nb, 1, length);
	if (nb < 0 && nb != -2147483648)
	{
		write(fd, "-", 1);
		nb = nb * -1;
		length++;
	}
	div = lengthint(nb);
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
