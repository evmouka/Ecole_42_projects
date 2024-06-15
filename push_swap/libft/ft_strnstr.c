/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evmouka <evmouka@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 10:25:50 by evmouka           #+#    #+#             */
/*   Updated: 2023/11/20 18:53:22 by evmouka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	j;

	i = 0;
	if (little[0] == '\0')
		return ((char *)big);
	if (big == 0 && len == 0)
		return (NULL);
	while (((char *)big)[i] && i < len)
	{
		j = 0;
		while (((char *)big)[i + j] == little[j] && (i + j) < len)
		{
			if (little[j + 1] == '\0')
				return ((char *)big + i);
			j++;
		}
		i++;
	}
	return (0);
}

/*
# include <bsd/string.h>
int	main()
{
	char	*haystack = "Hello world there";
	char	*needle = "world";

	printf("Library function: %s\n", strnstr(haystack, needle, 12));
	printf("My function: %s\n", ft_strnstr(haystack, needle, 12));
	return (0);
}
*/