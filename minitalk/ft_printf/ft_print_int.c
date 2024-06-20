/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_int.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evmouka <evmouka@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/24 17:40:36 by evmouka           #+#    #+#             */
/*   Updated: 2024/01/08 16:09:29 by evmouka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_int(long l, int base, int upper)
{
	int		count;
	char	*symbols;

	count = 0;
	if (upper == 1)
		symbols = "0123456789ABCDEF";
	else
		symbols = "0123456789abcdef";
	if (l < 0)
	{
		write(1, "-", 1);
		count += (ft_print_int(-l, base, upper) + 1);
	}
	else if (l < base)
		count += (ft_print_char(symbols[l]));
	else
	{
		count += ft_print_int(l / base, base, upper);
		count += ft_print_int(l % base, base, upper);
	}
	return (count);
}
