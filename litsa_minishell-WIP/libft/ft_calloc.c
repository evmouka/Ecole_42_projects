/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evmouka <evmouka@student.42london.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/25 13:52:04 by evmouka           #+#    #+#             */
/*   Updated: 2023/11/27 17:40:43 by evmouka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	void	*ptr;
	size_t	res;

	res = count * size;
	if (count != 0 && res / count != size)
		return (NULL);
	//if (count > SIZE_MAX / size)
	//	return (NULL);
	ptr = malloc(count * size);
	if (ptr == NULL)
		return (NULL);
	//if (count * size > SIZE_MAX)
	//	return (NULL);
	//if (count == 0 || size == 0)
	//	ptr = malloc(0);
	ft_bzero(ptr, count * size);
	return (ptr);
}
