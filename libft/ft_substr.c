/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evmouka <evmouka@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 16:29:37 by evmouka           #+#    #+#             */
/*   Updated: 2023/11/11 13:35:39 by evmouka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*str;
	size_t	i;
	size_t	j;

	if (!s)
		return (NULL);
	if (start >= ft_strlen(s))
		return (ft_strdup(""));
	if (len >= ft_strlen(s) && start == 0)
		return (ft_strdup(s));
	if (len > ft_strlen(s) - start)
		len = ft_strlen(s) - start;
	str = malloc(sizeof(char) * (len + 1));
	if (!str)
		return (NULL);
	i = start;
	j = 0;
	while (s[i + j] && j < len)
	{
		str[j] = s[i + j];
		j++;
	}
	str[j] = '\0';
	return (str);
}

/*
int	main()
{
	char	s1[] = "Black as life";
	int	start1 = 8;
	int	length1 = 4;
	printf("%s", ft_substr(s1, start1, length1));
	return (0);
}
*/