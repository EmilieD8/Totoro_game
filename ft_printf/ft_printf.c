/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edrouot <edrouot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/17 16:40:38 by edrouot           #+#    #+#             */
/*   Updated: 2022/12/25 14:22:45 by edrouot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include "ft_printf.h"

int	scnd_printf(const char *s, va_list args, int length, int i)
{
	unsigned long long	ptr;

	if (s[i] == 'd' || s[i] == 'i')
		length = ft_putnbrreturn_fd(va_arg(args, int), 1, length);
	else if (s[i] == 'c')
		length = ft_putcharper_fd(va_arg(args, int), 1, length);
	else if (s[i] == 's')
		length = ft_putstrreturn_fd(va_arg(args, char *), 1, length);
	else if (s[i] == 'u')
		length = ft_u_putnbr_fd(va_arg(args, unsigned int), 1, length);
	else if (s[i] == 'x')
		length = ft_hu_putnbr_fd(va_arg(args, unsigned int), 1, 1, length);
	else if (s[i] == 'X')
		length = ft_hu_putnbr_fd(va_arg(args, unsigned int), 1, 0, length);
	else if (s[i] == 'p')
	{
		ptr = va_arg(args, unsigned long long);
		length = ft_pointer_fd(ptr, 1, length);
	}
	else if (s[i] == '%')
		length = ft_putcharper_fd('%', 1, length);
	return (length);
}

int	ft_sndprintf(const char *s, va_list args, size_t index, int length)
{
	while (s[index] != '\0' && index < ft_strlen(s))
	{
		if (s[index] == '%')
		{
			length = scnd_printf(s, args, length, index + 1);
			index++;
		}
		else
		{
			write (1, &s[index], 1);
			if (s[index] != '\0')
				length++;
		}
		index++;
	}
	return (length);
}

int	ft_printf(const char *s, ...)
{
	va_list	args;
	size_t	index;
	int		length;

	index = 0;
	length = 0;
	va_start(args, s);
	if (!s)
		return (0);
	length = ft_sndprintf(s, args, index, length);
	va_end(args);
	return (length);
}

/*int	main(void)
{
	unsigned long long	d;
	d = 123; 
	unsigned long long *ptr;
	ptr = &d;

	printf("return of ft is %d", ft_printf("1. %c  2. %d  3. %i
	  4. %u  5. %x  6. %X  7. %%  8. %p", 'p', 123, 456, 7
	  89123456, 123, 123, ptr));
			printf("\n");
		printf("return of print is %d", printf("1. %c  2. %d  3. %i
		  4. %u  5. %x  6. %X  7. %%  8. %p", 'p', 123, 456, 
		  789123456, 123, 123, ptr));

}*/
