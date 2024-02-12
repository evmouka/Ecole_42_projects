/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evmouka <evmouka@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 15:47:33 by evmouka           #+#    #+#             */
/*   Updated: 2023/11/20 17:22:18 by evmouka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n && ((unsigned char *)s1)[i] == ((unsigned char *)s2)[i])
		i++;
	if (i >= n)
		return (0);
	return (((unsigned char *)s1)[i] - ((unsigned char *)s2)[i]);
}

/*
int	main()
{
	char	str1[] = "hella";
	char	str2[] = "hello";
	printf("Library function: %d\n", memcmp(str1, str2, 5));
	printf("My function: %d\n", memcmp(str1, str2, 5));
	return (0);
}
*/