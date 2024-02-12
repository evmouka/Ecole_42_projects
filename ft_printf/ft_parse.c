/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evmouka <evmouka@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/14 14:20:30 by evmouka           #+#    #+#             */
/*   Updated: 2024/01/18 16:52:46 by evmouka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_parse(const char c, va_list args)
{
	int	count;

	count = 0;
	if (c == '%')
		count += ft_print_char('%');
	else if (c == 'c')
		count += ft_print_char(va_arg(args, int));
	else if (c == 's')
		count += ft_print_str(va_arg(args, char *));
	else if (c == 'd' || c == 'i')
		count += ft_print_int((long)(va_arg(args, int)), 10, 1);
	else if (c == 'p')
		count += ft_print_ptr(va_arg(args, unsigned long));
	else if (c == 'u')
		count += ft_print_int((long)va_arg(args, unsigned int), 10, 0);
	else if (c == 'x')
		count += ft_print_int((va_arg(args, unsigned int)), 16, 0);
	else if (c == 'X')
		count += ft_print_int((va_arg(args, unsigned int)), 16, 1);
	else if (c == '%')
		count += ft_print_char('%');
	return (count);
}
