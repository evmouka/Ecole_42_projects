/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evmouka <evmouka@student.42london.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/02 22:55:35 by evmouka           #+#    #+#             */
/*   Updated: 2023/11/28 12:17:01 by evmouka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_countwords(char const *s, char c)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	if (!*s)
		return (0);
	while (s[i])
	{
		if (s[i] != c && s[i + 1] == c)
			count++;
		else
			if (s[i] != c && s[i + 1] == '\0')
				count++;
		i++;
	}
	return (count);
}

char	**ft_split(char const *s, char c)
{
	char		**str;
	int			i;
	const char	*next_c;
	str = (char **)malloc(sizeof(char *) * (ft_countwords(s, c) + 1));
	if (!str || !s)
		return (NULL);
	i = 0;
	while (*s)
	{
		if (*s != c)
		{
			next_c = ft_strchr(s, c);
			if (!next_c)
				next_c = s + ft_strlen(s);
			str[i++] = ft_substr(s, 0, next_c - s);
			s = next_c;
		}
		else
			s++;
	}
	str[i] = 0;
	return (str);
}

/*
int	main()
{
	char	**str;
	int		i;

	i = 0;
	str = ft_split("  tripouille  42  ", ' ');
	while (str[i])
	{
		printf("%s\n", str[i]);
		i++;
	}
	return (0);
}
*/