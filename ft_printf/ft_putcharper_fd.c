/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putcharper_fd.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edrouot <edrouot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/23 14:39:17 by edrouot           #+#    #+#             */
/*   Updated: 2022/12/23 16:45:25 by edrouot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include "ft_printf.h"

int	ft_putcharper_fd(int c, int fd, int length)
{
	write(fd, &c, 1);
	length++;
	return (length);
}
