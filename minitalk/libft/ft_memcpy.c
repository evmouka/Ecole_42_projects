/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evmouka <evmouka@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 15:29:14 by evmouka           #+#    #+#             */
/*   Updated: 2023/11/20 16:21:33 by evmouka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t			i;

	i = 0;
	if (!dest && !src)
		return (NULL);
	while (i++ < n)
	{
		((unsigned char *)dest)[i - 1] = ((const char *)src)[i - 1];
	}
	return (dest);
}

/*
int	main()
{
	char	src[] = "source";
	char	dest[] = "DESTINATION";
	ft_memcpy(dest, src, 10);
	printf("My funcion copies string: %s\n", dest);
	char	src1[] = "source";
	char	dest1[] = "DESTINATION";
	memcpy(dest1, src1, 10);
	printf("Library funcion copies string: %s\n", dest1);
}
*/