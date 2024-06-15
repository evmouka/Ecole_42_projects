/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evmouka <evmouka@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/11 13:38:59 by evmouka           #+#    #+#             */
/*   Updated: 2023/11/21 18:33:55 by evmouka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_countwords(char const *str, char w)
{
	size_t	words;
	size_t	i;

	words = 0;
	i = 0;
	if (!str)
		return (0);
	if (str[0] != '\0' && str[0] != w)
		words = 1;
	while (str[i] != '\0')
	{
		if (str[i] == w && str[i + 1] != w && str[i + 1] != '\0')
			words++;
		i++;
	}
	return (words);
}

char	**ft_split(char const *s, char c)
{
	char	**str;
	size_t	i;
	size_t	j;

	j = ft_countwords(s, c);
	str = (char **)ft_calloc((j + 1), sizeof(char *));
	if (!str || !s)
		return (NULL);
	i = 0;
	while (s != NULL && *s)
	{
		if (*s != c)
		{
			str[i] = ft_substr(s, 0, ft_strchr(s, c) - s);
			s = ft_strchr(s, c);
			i++;
		}
		else
			s++;
	}
	return (str);
}

/*
int	main()
{
	char	**s1;
	int	i;

	i = 0;
	s1 = ft_split("this  is a   new sentence for   you", ' ');
	while (s1[i])
	{
		printf("|%s|\n", s1[i]);
		i++;
	}
	return (0);
}
*/