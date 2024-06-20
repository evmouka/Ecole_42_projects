/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evmouka <evmouka@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 12:01:40 by evmouka           #+#    #+#             */
/*   Updated: 2023/11/20 16:59:41 by evmouka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	int		i;
	char	*str;

	i = 0;
	str = (char *)s;
	while (s[i] && s[i] != (char)c)
		i++;
	if (s[i] == (char)c)
		return (&str[i]);
	return (0);
}

/*
int	main()
{
	char	*str = "Hello";
	char	*ptr;
	ptr = ft_strchr(str, 'l');
	printf("%s\n", ptr);
}
*/