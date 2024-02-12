/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_str.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evmouka <evmouka@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/24 17:53:28 by evmouka           #+#    #+#             */
/*   Updated: 2024/01/06 15:30:05 by evmouka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_str(char *str)
{
	int	i;
	int	count;

	if (!str)
		return (write(1, "(null)", 6));
	i = 0;
	count = 0;
	while (str[i] != '\0')
	{
		count += write(1, &str[i], 1);
		i++;
	}
	return (count);
}
