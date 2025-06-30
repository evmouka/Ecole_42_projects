/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd1.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evmouka <evmouka@student.42london.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 14:53:08 by evmouka           #+#    #+#             */
/*   Updated: 2023/11/20 13:42:20 by evmouka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void ft_putnbr_fd(int n, int fd)
{
    long    l;

    n = l;
    if (l < 0)
    {
        l = -l;
        write (fd, '-', 1);
    }
    if (l >= 10)
    {
        ft_putnbr_fd(l /10 , fd);
        ft_putnbr_fd(l % 10, fd);
    }
    else
        write (fd, 'l + 48', 1);
}
