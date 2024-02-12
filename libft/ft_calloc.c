/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evmouka <evmouka@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 17:50:18 by evmouka           #+#    #+#             */
/*   Updated: 2023/11/11 13:31:53 by evmouka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*p;
	size_t	res;

	res = nmemb * size;
	if (size != 0 && res / size != nmemb)
		return (NULL);
	p = malloc(nmemb * size);
	if (!p)
		return (NULL);
	ft_bzero(p, nmemb * size);
	return (p);
}

/*
int	main()
{
	char	*str = ft_calloc(5, 18);
	char	*str1 = calloc(5, 18);
	printf("My function: %s\n", str);
	printf("Library function: %s\n", str1);
	return (0);
}
*/