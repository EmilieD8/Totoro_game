/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edrouot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 16:26:04 by edrouot           #+#    #+#             */
/*   Updated: 2022/12/08 16:26:07 by edrouot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strlenconst5(const char *str)
{
	int	counter;
	int	i;

	i = 0;
	counter = 0;
	while (str[i] != '\0')
	{
		counter++;
		i++;
	}
	return (i);
}

int	lengthcombine(char const *s1, char const *s2)
{
	int		l1;
	int		l2;
	int		l3;

	l1 = ft_strlenconst5(s1);
	l2 = ft_strlenconst5(s2);
	l3 = l1 + l2;
	return (l3);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		l3;
	char	*s3;
	int		sindex;
	int		bindex;

	l3 = lengthcombine(s1, s2);
	s3 = (char *)malloc(sizeof(char) * (l3 + 1));
	if (s3 == 0)
		return (NULL);
	sindex = 0;
	bindex = 0;
	while (bindex < ft_strlenconst5(s1))
		s3[bindex++] = s1[sindex++];
	sindex = 0;
	while (bindex < l3)
		s3[bindex++] = s2[sindex++];
	s3[bindex] = '\0';
	return (s3);
}

/*int	main(void)
{
	char	*s1 = "je veux ecrire";
	char	*s2 = " une jolie histoire.";
	printf("%s",ft_strjoin(s1,s2));
}*/
