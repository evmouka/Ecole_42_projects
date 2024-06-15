/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evmouka <evmouka@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 13:26:05 by evmouka           #+#    #+#             */
/*   Updated: 2023/11/20 17:05:47 by evmouka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	size_t			i;

	i = 0;
	if (!src && !dest)
		return (NULL);
	if (dest < src)
	{
		while (n > 0)
		{
			((unsigned char *)dest)[i] = ((const char *)src)[i];
			i++;
			n--;
		}
	}
	else
	{
		while (n > 0)
		{
			((unsigned char *)dest)[n - 1] = ((const char *)src)[n - 1];
			n--;
		}
	}
	return (dest);
}

/*
int	main()
{
	char str[100] = "Learningisfun"; 
    char *first, *second; 
    first = str; 
    second = str; 
    printf("Original string :%s\n ", str); 
      
    // when overlap happens then it just ignore it 
    memcpy(first + 8, first, 10); 
    printf("memcpy overlap : %s\n ", str); 
  
    // when overlap it start from first position 
    memmove(second + 8, first, 10); 
    printf("memmove overlap : %s\n ", str);

    
    ft_memmove(second + 8, first, 10); 
    printf("my function : %s\n ", str);
	return (0);
}*/