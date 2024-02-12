/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_ptr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evmouka <evmouka@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/23 01:26:20 by evmouka           #+#    #+#             */
/*   Updated: 2024/01/08 15:07:59 by evmouka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_ptr(unsigned long nb)
{
	int	count;
	int	i;
	int	number[100];

	count = 0;
	i = 0;
	if (nb == 0)
	{
		count += write(1, "(nil)", 5);
		return (count);
	}
	while (nb > 0)
	{
		number[i++] = nb % 16;
		nb /= 16;
	}
	count += write(1, "0x", 2);
	while (--i >= 0)
	{
		if (number[i] < 10)
			count += ft_print_char(number[i] + '0');
		else
			count += ft_print_char(number[i] + 'a' - 10);
	}
	return (count);
}
