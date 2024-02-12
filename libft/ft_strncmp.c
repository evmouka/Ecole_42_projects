/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evmouka <evmouka@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 14:04:40 by evmouka           #+#    #+#             */
/*   Updated: 2023/11/23 13:13:42 by evmouka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t			i;
	unsigned char	*str1;
	unsigned char	*str2;

	str1 = (unsigned char *)s1;
	str2 = (unsigned char *)s2;
	i = 0;
	while ((str1[i] || str2[i]) && i < n && str1[i] == str2[i])
		i++;
	if (i >= n)
		return (0);
	return (str1[i] - str2[i]);
}

/*
int	main()
{
	char	*s1 = "hEllo";
	char	*s2 = "world";
	printf("Library function: %d\n", strncmp (s1, s2, 5));
	printf("my funtion: %d\n", ft_strncmp (s1, s2, 5));
	return (0);
}
*/