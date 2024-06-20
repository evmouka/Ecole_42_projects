/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evmouka <evmouka@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/11 19:05:52 by evmouka           #+#    #+#             */
/*   Updated: 2023/11/20 14:37:44 by evmouka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_len(long l)
{
	int	len;

	len = 0;
	if (l == 0)
		return (1);
	if (l < 0)
	{
		l = -l;
		len++;
	}
	while (l > 0)
	{
		l = l / 10;
		len ++;
	}
	return (len);
}

char	*ft_itoa(int n)
{
	char	*str;
	long	nb;
	int		len;

	nb = n;
	len = ft_len(nb);
	str = (char *)malloc(sizeof(char) * (len + 1));
	if (!str)
		return (NULL);
	str[len--] = '\0';
	if (nb < 0)
	{
		nb = nb * -1;
		str[0] = '-';
	}
	if (nb == 0)
		str[0] = '0';
	while (nb > 0)
	{
		str[len--] = (nb % 10) + 48;
		nb = nb / 10;
	}
	return (str);
}

/*
int	main()
{
	int	x;
	
	x = -2147483648;
	printf("result is: %s\n", ft_itoa(x));
	return (0);
}
*/