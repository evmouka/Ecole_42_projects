/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evmouka <evmouka@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 17:52:43 by evmouka           #+#    #+#             */
/*   Updated: 2024/11/25 14:12:29 by evmouka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include <limits.h>

int	main(int argc, char **argv)
{
	t_fractol	fractol;

	if ((argc == 2 && ft_strncmp(argv[1], "mandelbrot", 10) == 0)
		|| (argc == 4 && ft_strncmp(argv[1], "julia", 5) == 0))
	{
		fractol.name = argv[1];
		if (ft_strncmp(argv[1], "julia", 5) == 0)
		{
			fractol.julia_re = ft_atofl(argv[2]);
			fractol.julia_im = ft_atofl(argv[3]);
			if (fractol.julia_re > INT_MAX || fractol.julia_re < INT_MIN
				|| fractol.julia_im > INT_MAX || fractol.julia_im < INT_MIN)
				return (1);
		}
		fractol_init(&fractol);
		fractol_render(&fractol);
		mlx_loop(fractol.mlx_connection);
	}
	else
	{
		ft_putstr_fd(ERROR_MESSAGE1, STDERR_FILENO);
		ft_putstr_fd(ERROR_MESSAGE2, STDERR_FILENO);
		exit(EXIT_FAILURE);
	}
	return (0);
}
