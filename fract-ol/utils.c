/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evmouka <evmouka@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 17:53:01 by evmouka           #+#    #+#             */
/*   Updated: 2024/11/04 17:53:02 by evmouka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t			i;
	unsigned char	*str1;
	unsigned char	*str2;

	str1 = (unsigned char *)s1;
	str2 = (unsigned char *)s2;
	if (s1 == NULL || s2 == NULL || n == 0)
		return (1);
	i = 0;
	while ((str1[i] || str2[i]) && i < n && str1[i] == str2[i])
		i++;
	if (i >= n)
		return (0);
	return (str1[i] - str2[i]);
}

void	ft_putstr_fd(char *s, int fd)
{
	int	i;

	if (!s || fd < 0)
		return ;
	i = 0;
	while (s[i])
	{
		write (fd, &s[i], 1);
		i++;
	}
}

double	ft_atofl(const char *str)
{
	int		sign;
	double	result;
	double	decimal;
	double	div;

	sign = 1;
	result = 0.0;
	decimal = 0.0;
	while ((*str && *str > 8 && *str < 14)
		|| *str == 32 || *str == '-' || *str == '+')
	{
		if (*str++ == '-')
			sign = -1;
	}
	while (*str >= '0' && *str <= '9' && *str && *str != '.')
		result = result * 10 + (*str++ - '0');
	str++;
	div = 10;
	while (*str >= '0' && *str <= '9' && *str)
	{
		decimal = (decimal * div + (*str++ - '0')) / div;
		div *= 10;
	}
	result += decimal;
	return (result * sign);
}
