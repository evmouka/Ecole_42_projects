/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evmouka <evmouka@student.42london.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/25 14:01:43 by evmouka           #+#    #+#             */
/*   Updated: 2023/11/20 16:46:37 by evmouka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	char	*str;

	str = (char *)s;
	while (n--)
		*str++ = '\0';
}

/*
int	main()
{
	char str[] = "Hello World!";
	ft_bzero(str, 5);
	printf("%s\n", str);
	return (0);
}
*/