/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evmouka <evmouka@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 12:49:43 by evmouka           #+#    #+#             */
/*   Updated: 2023/11/07 16:57:43 by evmouka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	count;

	i = 0;
	count = 0;
	while (src[count])
		count++;
	if (size == 0)
		return (count);
	while (src[i] != '\0' && i < (size - 1))
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (count);
}

/*
#include <bsd/string.h>
int	main()
{
	char	s1[] = "i want more";
	char	s2[] = "all of it";
	char	s3[] = "i want more";
	char	s4[] = "all of it";
	printf("My function: %zu\n", ft_strlcpy(s1, s2, 20));
	printf("%s\n", s1);
	printf("Library function: %zu\n", strlcpy(s3, s4, 20));
	printf("%s\n", s3);
	return (0);
}
*/
