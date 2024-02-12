/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evmouka <evmouka@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 12:00:19 by evmouka           #+#    #+#             */
/*   Updated: 2023/11/02 14:38:41 by evmouka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *s, int c, size_t len)
{
	unsigned char	*ptr;
	size_t			i;

	i = 0;
	ptr = (unsigned char *)s;
	while (i < len)
	{
		ptr[i] = (unsigned char) c;
		i++;
	}
	return (s);
}

/*
int	main()
{
	char	str[] = "This is me!";
	ft_memset(str, 'j', 7);
	printf("%s\n", str);
	char	str1[] = "This is me!";
	memset(str1, 'j', 7);
	printf("%s\n", str1);
	return (0);
}
*/