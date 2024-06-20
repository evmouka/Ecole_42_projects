/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evmouka <evmouka@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 15:26:20 by evmouka           #+#    #+#             */
/*   Updated: 2023/11/20 19:19:30 by evmouka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	src_len;
	size_t	dst_len;

	if ((!dst || !src) && size == 0)
		return (0);
	src_len = ft_strlen(src);
	dst_len = ft_strlen(dst);
	i = 0;
	if (size <= dst_len)
		return (src_len + size);
	while (src[i] && (dst_len + i + 1) < (size))
	{
		dst[dst_len + i] = src[i];
		i++;
	}
	if (dst_len + i < size)
		dst[dst_len + i] = '\0';
	return (dst_len + src_len);
}

/*
#include <bsd/string.h>
int	main()
{
	char	s2[] = "i want ";
	char	s1[20] = "all of it";
	char	s4[] = "i want ";
	char	s3[20] = "all of it";
	printf("My function: %zu\n", ft_strlcat(s1, s2, 9));
	printf("%s\n", s1);
	printf("Library function: %zu\n", strlcat(s3, s4, 9));
	printf("%s\n", s3);
	return (0);
}
*/