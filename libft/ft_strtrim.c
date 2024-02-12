/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evmouka <evmouka@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 13:11:30 by evmouka           #+#    #+#             */
/*   Updated: 2023/11/23 13:11:49 by evmouka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_in_set(const char *set, char c)
{
	size_t	i;

	i = 0;
	while (set[i])
	{
		if (set[i] == c)
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	start;
	size_t	end;	

	if (!s1)
		return (NULL);
	if (!set)
		return (ft_strdup(s1));
	start = 0;
	end = ft_strlen(s1);
	while (ft_in_set(set, s1[start]) == 1)
		start++;
	while (end > start && ft_in_set(set, s1[end - 1]) == 1)
		end--;
	return (ft_substr(s1, start, end - start));
}

/*
int	main ()
{
	char	*s2 = "/\t///^/hello ^ please \t	trim me	!]	^";
	char	*remove = "/^\t]";
	printf("|%s|\n", ft_strtrim(s2, remove));
	return (0);
}
*/