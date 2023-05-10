/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstrreturn_fd.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edrouot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/23 15:42:36 by edrouot           #+#    #+#             */
/*   Updated: 2022/12/23 15:42:37 by edrouot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include "ft_printf.h"

int	ft_putstrreturn_fd(char *s, int fd, int length)
{
	int	index;

	index = 0;
	if (s == NULL)
	{
		write(1, "(null)", 6);
		return (length + 6);
	}
	while (s[index] != '\0')
	{
		write(fd, &s[index], 1);
		index++;
		length++;
	}
	return (length);
}
