/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evmouka <evmouka@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 13:29:53 by evmouka           #+#    #+#             */
/*   Updated: 2023/11/20 17:45:44 by evmouka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int		i;
	char	*ptr;

	i = ft_strlen(s);
	ptr = (char *)s;
	while (i > 0 && s[i] != (char)c)
		i--;
	if (s[i] == (char)c)
		return (&ptr[i]);
	return (0);
}

/*
int	main()
{
	char	*str = "Hello";
	char	*ptr;
	ptr = ft_strrchr(str, 'l');
	printf("%s\n", ptr);
	return (0);
}
*/