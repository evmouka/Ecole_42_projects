/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evmouka <evmouka@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 14:40:15 by evmouka           #+#    #+#             */
/*   Updated: 2023/11/03 12:47:29 by evmouka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	char	*ptr;
	size_t	i;

	i = 0;
	ptr = (char *)s;
	while (i < n)
	{
		ptr[i] = '\0';
		i++;
	}
}

/*
int	main()
{
	char	str[] = "This is me!";
	ft_bzero(str, 7);
	printf("%s\n", str);
	char	str1[] = "This is me!";
	bzero(str1, 7);
	printf("%s\n", str1);
	return (0);
}
*/