/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evmouka <evmouka@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 16:27:32 by evmouka           #+#    #+#             */
/*   Updated: 2024/01/06 15:33:55 by evmouka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stddef.h>
# include <stdio.h>
# include <unistd.h>

int		ft_printf(const char *format, ...);
int		ft_parse(const char c, va_list args);
int		ft_print_char(int c);
int		ft_print_str(char *str);
int		ft_print_int(long l, int base, int upper);
int		ft_print_ptr(unsigned long nb);

#endif