/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evmouka <evmouka@student.42london.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/25 16:21:03 by evmouka           #+#    #+#             */
/*   Updated: 2023/11/03 12:22:41 by evmouka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t			i;

	i = 0;
	if (!dst && !src)
		return (NULL);
	while (i++ < n)
		((unsigned char *)dst)[i - 1] = ((const char *)src)[i - 1];
	return (dst);
}

/*
int	main()
{
	char src[] = "Geeksfor";
	char dest[] = "GeeksforGeeks is for programming geeks.";
	ft_memcpy(dest, src, 5);
	printf("Copied string is %s", dest);
	return (0);
}
*/