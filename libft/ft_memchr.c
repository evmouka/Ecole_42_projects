/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evmouka <evmouka@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 14:50:33 by evmouka           #+#    #+#             */
/*   Updated: 2023/11/20 17:16:21 by evmouka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	nb;
	unsigned char	*str;
	size_t			i;

	nb = (unsigned char)c;
	str = (unsigned char *)s;
	i = 0;
	while (i < n)
	{
		if (str[i] == nb)
			return (&str[i]);
		i++;
	}
	return (0);
}

/*
int	main ()
{
	char	s[] = "This is not it, love";
	printf("Library function: %s\n", memchr(s, 'l', 17));
	printf("My function: %s\n", ft_memchr(s, 'l', 17));
	return (0);
}
*/